#pragma once 
#include "tcp_socket.hpp"
typedef function<void(const string& req,string* resp)> Handler;


class TcpThreadServer
{
  public:
    TcpThreadServer()
    {
      _sock.Socket();
    }

    ~TcpThreadServer()
    {
      _sock.Close();
    }

    bool Start(const string& ip,const uint16_t& port,Handler handler)
    {
      _sock.Bind(ip,port);

      _sock.Listen(5);

      while(1)
      {
        string _ip;
        uint16_t _port;
        TcpSocket newsock;

        _sock.Accept(&newsock,&_ip,&_port);

        printf("[%s:%d]客户端建立链接！\n",_ip.c_str(),_port);

        PthreadConnect(newsock,_ip,_port,handler);
      }
    }

    struct ThreadEntryArg
    {
      TcpSocket client_sock;
      string ip;
      uint16_t port;
      Handler handler;

    };

    void PthreadConnect(TcpSocket& client_sock,const string& ip,uint16_t port,Handler handler)
    {
      ThreadEntryArg* arg = new ThreadEntryArg();
      arg->client_sock = client_sock;
      arg->ip = ip;
      arg->port = port;
      arg->handler = handler;

      pthread_t tid;
      pthread_create(&tid,NULL,ThreadEntry,(void*)arg);
      pthread_detach(tid);
    }

    static void* ThreadEntry(void* arg)
    {
      ThreadEntryArg* args = (ThreadEntryArg*)arg;
      while(1)
      {
        string req;
        int ret = args->client_sock.Recv(&req);
        if(ret < 0)
        {
          continue;
        }
        else if(ret == 0)
        {
          args->client_sock.Close();
          printf("[%s:%d],客户端断开链接了\n！",args->ip.c_str(),args->port);
          break;
        }

        string resp;
        args->handler(req,&resp);

        args->client_sock.Send(resp);
      }
      return NULL;
    }
  private:
    TcpSocket _sock;
};

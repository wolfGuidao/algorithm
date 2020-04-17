#pragma once
#include "tcp_socket.hpp"
typedef function<void(const string& req,string* resp)> Handler;

class TcpProcessServer 
{
  public:
    TcpProcessServer()
    {
      _sock.Socket();
    }

    ~TcpProcessServer()
    {
      _sock.Close();
    }

    bool Start(const string& ip,const uint16_t& port,Handler handler)
    {
      _sock.Bind(ip,port);

      _sock.Listen(5);

      while(1)
      {
        TcpSocket newsock;
        string _ip;
        uint16_t _port;
        _sock.Accept(&newsock,&_ip,&_port);
        printf("有客户端成功链接ip:[%s] port:[%d]\n",_ip.c_str(),_port);

        ProcessConnect(newsock,_ip,_port,handler);
      }
    }
    void ProcessConnect(TcpSocket& client_sock,string& ip,uint16_t port,Handler handler)
    {
      pid_t pid = fork();
        if(pid < 0)
        {
          return ;
        }

      if(pid > 0)
      {
        client_sock.Close();
        return ;
      }
      
      while(1)
      {
        string req;

        int ret = client_sock.Recv(&req);
        if(ret < 0)
        {
          continue;
        }
        if(ret == 0)
        {
          printf("有客户端断开连接 ip:[%s] port[%d]\n",ip.c_str(),port);
          break;
        }

        string resp;
        handler(req,&resp);

        client_sock.Send(resp);
      }
    }
  private:
    TcpSocket _sock;
};


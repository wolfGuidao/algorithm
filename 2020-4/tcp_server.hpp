#pragma once 
#include "tcp_socket.hpp"
#include <functional>
#define CHECK_RET(op) if(!(op)) return false;
typedef function<void(const string& req,string* resp)> Handler;

class TcpServer 
{
  public:
    TcpServer()
    {
      
    }

    ~TcpServer()
    {
      _sock.Close();
    }
    bool Start(const string& ip, uint16_t port,Handler handler)
    {
      CHECK_RET(_sock.Socket());

      CHECK_RET(_sock.Bind(ip,port));

      CHECK_RET(_sock.Listen(5));

      while(1)
      {
        TcpSocket newsock;
        string _ip;
        uint16_t _port;
        bool ret = _sock.Accept(&newsock,&_ip,&_port);
        if(!ret)
        {
          continue;
        }
        
        printf("有客户端成功链接：[ip]:%s [port]:%d\n",_ip.c_str(),_port);

        while(1)
        {
          string req;
          int ret = newsock.Recv(&req);
          if(ret == -1)
          {
            printf("Recv error\n");
            continue;
          }
          else if(ret == 0)
          {
            printf("有客户端断开接：[ip]:%s [port]:%d\n",_ip.c_str(),_port);
            return false;
          }

          string resp;
          
          handler(req,&resp);

          newsock.Send(resp);
        }
      }
    }
  private:
    TcpSocket _sock;
};

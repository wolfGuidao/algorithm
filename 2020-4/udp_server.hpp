#pragma once 
#include "udp_socket.hpp"
typedef function<void(const string& req,string* resp)> Handler;

class UdpServer 
{
  public:
    UdpServer()
    {
      _sock.Socket(); 
    }
    ~UdpServer()
    {
      _sock.Close();
    }

    bool Start(const string& ip,const uint16_t& port,Handler handler)
    {
      bool ret = _sock.Bind(ip,port);
      if(!ret)
      {
        return false;
      }

      while(1)
      {
        string req;
        string _ip;
        uint16_t _port;
        _sock.RecvFrom(&req,&_ip,&_port);
        printf("有客户端成功链接：[ip]: %s [port]: %d\n",_ip.c_str(),_port);

        string resp;
        handler(req,&resp);

        _sock.SendTo(req,_ip,_port);
      }
    }
  private:
    UdpSocket _sock;
};

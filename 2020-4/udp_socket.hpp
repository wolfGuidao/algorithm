#pragma once 
#include "Header.hpp"

class UdpSocket
{
  UdpSocket()
  {
    _fd = -1;
  }

  bool Socket()
  {
    _fd = socket(AF_INET,SOCK_DGRAM,0);
    if(_fd < 0)
    {
      return false;
    }
    return true;
  }

  bool Bind(const string& ip,const uint16_t& port)
  {
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);
    int ret = bind(_fd,(sockaddr*)&addr,sizeof(addr));
    if(ret < 0)
    {
      return false;
    }
    return true;
  }

  bool RecvFrom(string* req,string* ip = nullptr,uint16_t* port = nullptr)
  {
    req->clear();
    char buf[1024 * 10] = {0};
    sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int ret = recvfrom(_fd,buf,sizeof(buf) - 1,0,(sockaddr*)&addr,&len);
    if(ret < 0)
    {
      return false;
    }
    req->assign(buf);
    if(ip != nullptr)
    {
      *ip = inet_ntoa(addr.sin_addr); 
    }
    if(port != nullptr)
    {
      *port = ntohs(addr.sin_port);
    }
    return true;
  }

  bool SendTo(const string& resp,const string& ip,const uint16_t& port)
  {
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);
    socklen_t len = sizeof(addr);
    int ret = sendto(_fd,resp.c_str(),resp.size(),0,(sockaddr*)&addr,len);
    if(ret < 0)
    {
      return false;
    }
    return true;
  }

  bool Close()
  {
    if(_fd != -1)
    {
      close(_fd);
    }
    return true;
  }
  private:
    int _fd;
};

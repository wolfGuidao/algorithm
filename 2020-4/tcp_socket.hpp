#pragma once 
#include "Header.hpp"

class TcpSocket 
{
  public:
    TcpSocket()
    {
      _fd = -1;
    }

    bool Socket()
    {
      _fd = socket(AF_INET,SOCK_STREAM,0);
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

    bool Listen(size_t size)
    {
      int ret = listen(_fd,size);
      if(ret < 0)
      {
        return false;
      }
      return true;
    }

    bool Accept(TcpSocket* newSocket,string* ip = nullptr,uint16_t* port = nullptr)
    {
      sockaddr_in addr;
      socklen_t len = sizeof(addr);

      int _newfd = accept(_fd,(sockaddr*)&addr,&len);
      if(_newfd < 0)
      {
        return false;
      }
      newSocket->_fd = _newfd;
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

    int Recv(string* req)
    {
      req->clear();
      char buf[1024 * 10] = {0};
      int ret = recv(_fd,buf,sizeof(buf) - 1,0); 
      if(ret < 0)
      {
        return -1;
      }
      else if(ret == 0)
      {
        return 0;
      }
      else 
      {
        req->assign(buf);
        return 1;
      }
    }

    bool Send(const string& resp)
    {
      int n = send(_fd,resp.c_str(),resp.size(),0);
      if(n < 0)
      {
        return false;
      }
      return true;
    }

    bool Connect(const string& ip,uint16_t& port)
    {
      sockaddr_in addr;
      addr.sin_addr.s_addr = inet_addr(ip.c_str());
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port);
      int ret = connect(_fd,(sockaddr*)&addr,sizeof(addr));
      if(ret < 0)
      {
        return false;
      }
      return true;
    }

    bool Close()
    {
      if(_fd != -1)
        close(_fd);
      return true;
    }
  private:
    int _fd;
};


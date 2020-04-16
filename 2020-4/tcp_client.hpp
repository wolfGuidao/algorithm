#pragma once 
#include "tcp_socket.hpp"

class TcpClient 
{
  public:
    TcpClient()
    {
      _sock.Socket();
    }

    ~TcpClient()
    {
      _sock.Close();
    }

    bool Connect(const string& ip,const uint16_t& port)
    {
      return _sock.Connect(ip,port);
    }

    bool Send(const string req)
    {
      return _sock.Send(req);
    }

    bool Recv(string* resp)
    {
      return _sock.Recv(resp);
    }
  private:
    TcpSocket _sock;
};

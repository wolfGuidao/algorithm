#pragma once 
#include "udp_socket.hpp"

class UdpClient
{
  public:
    UdpClient()
    {
      _sock.Socket();
    }

    ~UdpClient()
    {
      _sock.Close();
    }

    bool RecvFrom(string* resp)
    {
      return _sock.RecvFrom(resp);
    }

    bool SendTo(const string& req,const string& ip,const uint16_t& port)
    {
      return _sock.SendTo(req,ip,port);
    }
  private:
    UdpSocket _sock;
};

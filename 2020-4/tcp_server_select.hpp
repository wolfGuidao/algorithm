#pragma once 
#include "tcp_socket.hpp"
typedef function<void(const string& req,string* resp)>Handler;

class Select 
{
  public:
    void Add(TcpSocket& sock)
    {
      printf("select add sock fd:[%d]\n",sock.GetFd());
      set_sock.insert(sock);
    }

    void Wait(vector<TcpSocket>* output)
    {
      output->clear();
      if(set_sock.empty())
      {
        printf("select set is empty\n");
        return ;
      }

      int maxfd = set_sock.rbegin()->GetFd();

      fd_set readfd;
      FD_ZERO(&readfd);

      for(auto e : set_sock)
      {
        FD_SET(e.GetFd(),&readfd);
      }

      int nfds = select(maxfd + 1,&readfd,NULL,NULL,NULL);
      if(nfds < 0)
      {
        printf("select\n");
        return;
      }
      for(int fd = 0;fd < maxfd + 1;fd++)
      {
        if(FD_ISSET(fd,&readfd))
        {
          output->push_back(TcpSocket(fd));
        }
      }
    }
  
    void Del(TcpSocket& sock)
    {
      printf("del sock fd :%d\n",sock.GetFd());
      set_sock.erase(sock);
    }

  private:
    set<TcpSocket> set_sock;
};

class TcpSelectServer
{
  public:
    TcpSelectServer()
    {
      _sock.Socket();
    }

    ~TcpSelectServer()
    {
      _sock.Close();
    }

    bool Start(const string& ip,const uint16_t& port,Handler handler)
    {
      _sock.Bind(ip,port);

      _sock.Listen(5);

      Select sele;
      sele.Add(_sock);
      while(1)
      {
        vector<TcpSocket> output;
        sele.Wait(&output);

        for(auto e : output)
        {
          if(e.GetFd() == _sock.GetFd())
          {
            string _ip;
            uint16_t _port;
            TcpSocket newsock;
            e.Accept(&newsock,&_ip,&_port);
            sele.Add(newsock);
            printf("[client %s:%d] connected!\n",_ip.c_str(),_port);
          }
          else 
          {
            string req;
            int ret = e.Recv(&req);
            if(ret < 0)
            {
              continue;
            }
            if(ret == 0)
            {
              printf("对端断开连接\n");
              e.Close();
              sele.Del(e);
              continue;
            }

            string resp;
            handler(req,&resp);

            e.Send(resp);
          }
        }
      }
    }
  private:
    TcpSocket _sock;
};

#pragma once 
#include "tcp_socket.hpp"
typedef function<void(const string& req,string* rsp)>Handler;

class Epoll
{
  public:
    Epoll()
    {
      _epoll_fd = epoll_create(100);
    }

    ~Epoll()
    {
      close(_epoll_fd);
    }

    void Add(TcpSocket& sock,bool IsET = false)
    {
      printf("insert sock fd:%d\n",sock.GetFd());

      epoll_event event;
      event.data.fd = sock.GetFd();
      event.events = EPOLLIN;
      if(IsET)
      {
        event.events |= EPOLLET;
      }
      epoll_ctl(_epoll_fd,EPOLL_CTL_ADD,sock.GetFd(),&event);
    }

    void Wait(vector<TcpSocket>* output)
    {
      output->clear();

      epoll_event events[100];
      int nfds = epoll_wait(_epoll_fd,events,100,-1); 
      if(nfds < 0)
      {
        printf("epollwait\n");
        return ;
      }
      for(int i = 0;i < nfds;i++)
      {
        TcpSocket sock(events[i].data.fd);
        output->push_back(sock);
      }
    }

    void Del(TcpSocket& sock)
    {
      printf("dee sock fd:%d\n",sock.GetFd());
      epoll_ctl(_epoll_fd,EPOLL_CTL_DEL,sock.GetFd(),NULL);
    }
  private:
    int _epoll_fd;
};

class TcpEpollServer 
{
  public:
    TcpEpollServer()
    {
      _sock.Socket();
    }

    ~TcpEpollServer()
    {
      _sock.Close();
    }

    bool Start(const string& ip,uint16_t port,Handler hander)
    {
      _sock.Bind(ip,port);

      _sock.Listen(5);

      Epoll epoll;
      epoll.Add(_sock,true);
      while(1)
      {
        vector<TcpSocket> out;
        epoll.Wait(&out);

        for(auto e : out)
        {
          if(e.GetFd() == _sock.GetFd())
          {
            TcpSocket newsock;
            string _ip;
            uint16_t _port;
            e.Accept(&newsock,&_ip,&_port);
            printf("有客户端成功链接：ip:[%s],port:[%d]\n",_ip.c_str(),_port);
            epoll.Add(newsock,true);
          }
          else 
          {
            string req;
            int ret = e.RecvNoBlock(&req);
            if(ret < 0)
            {
              continue;
            }
            else if(ret == 0)
            {
              e.Close();
              epoll.Del(e);
              printf("有客户端断开连接\n");
              continue;
            }

            string resp;
            hander(req,&resp);

            e.SendNoBlock(resp);
          }
        }
      }
    }
  private:
    TcpSocket _sock;
};

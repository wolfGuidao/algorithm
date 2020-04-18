#pragma once
#include "tcp_socket.hpp"
typedef function<void(const string& req,string* resp)> Handler;

class Poll
{
  public:
    Poll()
    {
      
    }

    void Add(TcpSocket& sock)
    {
      printf("insert sock fd :%d\n",sock.GetFd());
      set_sock.insert(sock);
    }

    void Wait(vector<TcpSocket>* output)
    {
      output->clear();

      struct pollfd* fds = new pollfd[set_sock.size()];
      int i = 0;
      for(auto e : set_sock)
      {
        fds[i].fd = e.GetFd();
        fds[i].events = POLLIN;
        i++;
      }

      int ret = poll(fds,i,0);
      if(ret < 0)
      {
        printf("poll error\n");
        return ;
      }

      for(size_t i = 0;i < set_sock.size();i++)
      {
        if(fds[i].revents == POLLIN)
        {
          TcpSocket temp(fds[i].fd);
          output->push_back(temp);
        }
      }
    }

    void Del(TcpSocket& sock)
    {
      set_sock.erase(sock);
      printf("del sock fd:%d\n",sock.GetFd());
    }
  private:
    set<TcpSocket> set_sock;
};

class TcpPollServer
{
  public:
    TcpPollServer()
    {
      _sock.Socket();
    }

    ~TcpPollServer()
    {
      _sock.Close();
    }

    bool Start(const string& ip,const uint16_t& port,Handler handler)
    {
      _sock.Bind(ip,port);

      _sock.Listen(5);

      Poll poll;
      poll.Add(_sock);

      while(1)
      {
        vector<TcpSocket> out;
        poll.Wait(&out);

        for(auto e : out)
        {
          if(e.GetFd() == _sock.GetFd())
          {
            TcpSocket newsock;
            string _ip;
            uint16_t _port;

            e.Accept(&newsock,&_ip,&_port);

            poll.Add(newsock);
          }
          else 
          {
            string req;
            int ret = e.Recv(&req);
            if(ret < 0)
            {
              continue;
            }
            else if(ret == 0)
            {
              printf("对端关闭链接\n");
              e.Close();
              poll.Del(e);
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

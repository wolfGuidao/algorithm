#pragma once 
#include "Header.hpp"

class TcpSocket 
{
  public:
    TcpSocket()
    {
      _fd = -1;
    }
    TcpSocket(const int fd)
      :_fd(fd)
    {

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

    bool Connect(const string& ip,const uint16_t& port)
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

    bool SetNoBlock()
    {
      //获取到fd_文件描述符的相关标志位，保存在f1这个位图中
      int f1 = fcntl(_fd,F_GETFL);
      if(f1 < 0)
      {
        perror("funcl F_GETFL");
        return false;
      }
      int ret = fcntl(_fd,F_SETFL,f1|O_NONBLOCK);
      if(ret < 0)
      {
        perror("fcnl F_SETFL");
        return false;
      }
      return true;
    }

    int RecvNoBlock(string* msg)
    {
      msg->clear();
      //这是一个近似的写法，没有考虑粘包问题
      //如果tcp的接受缓冲 区为空，此时读不到数据，但recv同样会返回，如果没读到->errno会被设为EAGAIN/EWOULDBLOCK
      //如果读到的数据长度比设定的用户缓冲区长度一样，就继续往下读
      //如果当前读到的数据的长度已经比缓冲区长度短，就认为读完了
      char temp[1024 * 10];
      while(1)
      {
        ssize_t n = recv(_fd,temp,1024 * 10 - 1,0);
        if(n < 0)
        {
          if(errno == EAGAIN || errno == EWOULDBLOCK)
          {
            //表明缓冲区已经没有数据了,但仍还要继续尝试读
            continue;
          }
          else
          {
            //其他原因导致的读失败，就退出函数
            return -1;
          }
        }
        else if(n == 0)
        {
          printf("对端关闭链接\n");
          return 0;
        }
        temp[n] = '\0';
        //把这个数据追加到输出参数中
        msg->append(temp);
        if(n < (ssize_t)sizeof(temp) - 1)
        {
          //这次读取没有填充完整个缓冲区，认为当前都缓冲区中没有数据了
          break;
        }
      }
      return msg->size();
    }

    bool SendNoBlock(const string& msg)const
    {
      //当实际发送的数据长度和msg一样就代表发送完了
      //send(fd_,msg.c_str(),msg.size(),0);//有风险，由于当前是非阻塞IO，如果发送缓冲区满了，函数一调用就返回可能会出现发送失败的情况
      //所以最好采用小块小块的发送，每发送完一个数据后，都检查自己发送了多少个数据，累加发送的数据的长度
      //当长度等于msg的长度时才代表最终发送完成

      //记录当前写到的位置
      ssize_t cur_pos = 0;
      ssize_t left_size = msg.size();
      while(1)
      {
        ssize_t write_size = send(_fd,msg.data() + cur_pos,left_size,0);
        if(write_size < 0)
        {
          if(errno == EAGAIN || errno == EWOULDBLOCK)
          {
            continue;
          }
          return false;
        }
        cur_pos += write_size;
        left_size -= write_size;
        if(left_size <= 0)
        {
          break;
        }
      }
      return true;
    }

    int GetFd()const 
    {
      return _fd;
    }

  private:
    int _fd;
};

bool operator<(const TcpSocket& l,const TcpSocket& r)
{
  return l.GetFd() < r.GetFd();
}

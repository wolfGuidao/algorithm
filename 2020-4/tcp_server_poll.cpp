#include "tcp_server_poll.hpp"

int main()
{
  TcpPollServer server;
  server.Start("0.0.0.0",9090,[](const string& req,string* resp)
      {
         printf("client say:%s\n",req.c_str());
         printf("server input:\n");
         getline(cin,*resp);
      });
  return 0;
}

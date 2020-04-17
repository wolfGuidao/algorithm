#include "tcp_server_pthread.hpp"

int main()
{
  TcpThreadServer server;
  server.Start("0.0.0.0",9090,[](const string& req,string* resp)
      {
         printf("client say:%s\n",req.c_str());
         printf("server input:\n");
         getline(cin,*resp);
      });
  return 0;
}

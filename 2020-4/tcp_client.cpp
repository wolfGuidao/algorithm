#include "tcp_client.hpp"

int main()
{
  TcpClient client;
  client.Connect("0.0.0.0",9090);

  while(1)
  {
    printf("client input:\n");
    string req;
    getline(cin,req);

    client.Send(req);

    string resp;
    client.Recv(&resp);

    printf("server say:%s\n",resp.c_str());
  }
  return 0;
}

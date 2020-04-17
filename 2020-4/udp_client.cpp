#include "udp_client.hpp"

int main()
{
  UdpClient client;
  while(1)
  {

  
  string req;
  printf("client input:\n");
  getline(cin,req);
  client.SendTo(req,"0.0.0.0",9090);
  string resp;
  client.RecvFrom(&resp);
  printf("server say:%s\n",resp.c_str());
  }
  return 0;
}

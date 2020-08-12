/*************************************************************************
# File Name: 8-17.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月11日 星期二 22时34分51秒
 *************************************************************************/
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
    int sock = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET; 
    sock_addr.sin_addr.s_addr = inet_addr("192.168.221.132");
    sock_addr.sin_port = htons(9090);

    int ret = bind(sock,(struct sockaddr*)&sock_addr,sizeof(sock_addr));
    if(ret < 0)
    {
        cout<<"bind error"<<endl;
        return -1;
    }

    pid_t pid = fork();
    if(pid < 0)
    {
        return -1;
    }
    else if(pid == 0)
    {

        //int ret = bind(sock,(struct sockaddr*)&sock_addr,sizeof(sock_addr));
        //if(ret < 0)
        //{
        //    cout<<"bind error"<<endl;
        //    return -1;
        //}
        int ret = listen(sock,5);
        if(ret < 0)
        {
            cout<<"listen error"<<endl;
            return -1;
        }
    }
    else 
    {
        //int ret = bind(sock,(struct sockaddr*)&sock_addr,sizeof(sock_addr));    
        //if(ret < 0)    
        //{               
        //    cout<<"bind error"<<endl;    
        //    return -1;     
        //}    
        int ret = listen(sock,5);
        if(ret < 0)
        {
            cout<<"listen error"<<endl;
            return -1;
        }
    }
    return 0;
}

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

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        vector<vector<int>> s(increase.size() + 1,vector<int>(3,0));
        for(int i = 0;i < increase.size();i++)
        {
            for(int j = 0;j < 3;j++)
            {
                s[i + 1][j] = s[i][j] + increase[i][j];
            }
        }
        vector<int> ans;
        for(auto v:requirements)
        {
            int l = 0, r = increase.size();
            while(l < r)
            {
                int m = (l + r) / 2;
                if(s[m][0] >= v[0] && s[m][1] >= v[1] && s[m][2] >= v[2])
                    r = m;
                else
                    l = m + 1;
            }
            if(s[l][0] >= v[0] && s[l][1] >= v[1] && s[l][2] >= v[2])
                ans.push_back(l);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};

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

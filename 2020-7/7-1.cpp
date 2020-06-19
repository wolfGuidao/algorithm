/*************************************************************************
  > File Name: 7-1.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月19日 星期五 12时49分26秒
 ************************************************************************/

#include "Header.hpp"
#include <boost/timer.hpp>

#if 0
int main()
{
    //pthread_rwlock_t rwlock;
    // boost::timer timer;
    //time_t begin = clock();
    //pid_t pid = vfork();
    //if(pid < 0)
    //{
    //    perror("vfork error");
    //    return -1;
    //}
    //else if(pid == 0)
    //{
    //    cout<<"i am child"<<endl;
    //    sleep(3);
    //    exit(0);
    //}
    //else 
    //{
    //    cout<<" i am father"<<endl;
    //}
    //time_t end = clock();
    //cout<<(end - begin) /CLOCKS_PER_SEC<<endl;
    //cout<<" cost time: "<<timer.elapsed() <<endl;
    long long a = 1,b = 2,c = 3;
    printf("%d,%d,%d\n",a,b,c);
    return 0;
}
#endif


#if 0
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1;
    string str2;
    while(cin>>str1>>str2)
    {
        string ret;

        //    12 : 2
        //123456 : 6
        //         4

        int size1 = str1.size();
        int size2 = str2.size();
        if(size1 < size2)
        {
            for(int i = 0;i < size2 - size1;i++)
            {
                str1 = '0' + str1;
            }
        }
        else if(size1 > size2)
        {
            for(int i = 0;i < size1 - size2;i++)
            {
                str2 = '0' + str2;
            }
        }
        // '1' - '0' = 1;
        int inde = 0;
        int sum = 0;
        for(int i = str1.size() - 1;i >= 0;i--)
        {
            sum = (str1[i] - '0') + (str2[i] - '0');

            int temp = (sum + inde) % 10;

            ret += (temp + '0');

            inde = (sum + inde) / 10;
        }
        if(inde != 0)
        {
            ret += '1';
        }

        reverse(ret.begin(),ret.end());
        cout<<ret<<endl;
    }
    return 0;
}
#endif

#if 0
#define KEY 0x12345678

int main()
{

    pid_t pid = fork();
    if(pid < 0)
    {
        exit(0);
    }
    else if(pid == 0)
    {
        int shmid = shmget((key_t)1234,32,IPC_CREAT);
        char* addr = (char*)shmat(shmid,nullptr,0);
        addr[0] = 'h';
        addr[1] = 'h';
        addr[2] = 'h';
        addr[3] = '\0';
        shmdt(addr);
        shmctl(shmid,IPC_RMID,nullptr);    
        exit(0);
    }

    else 
    {
        sleep(3);
        int shmid = shmget((key_t)1234,32,IPC_CREAT);
        void* addr_peer = shmat(shmid,nullptr,0);
        cout<<(char*)addr_peer<<endl;
        shmdt(addr_peer);
        shmctl(shmid,IPC_RMID,nullptr);    
    }
    return 0;
}
#endif
#if 0

int main()
{
    key_t key = ftok(".",0x6666);

    int shmid = shmget(key,4096,IPC_CREAT | IPC_EXCL | 0666);

    char* addr = (char*)shmat(shmid,nullptr,0);

    cout<<"flag"<<endl;
    sleep(2);

    for(int i = 0;i < 10;i++)
    {
        printf("client say:%s\n",addr);
        sleep(1);
    }

    shmdt((void*)addr);

    shmctl(shmid,IPC_RMID,nullptr);
    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

#define shm_key 0x99999999
int main()
{
    int shmid = shmget(shm_key, 1024, IPC_CREAT | 0664);
    if(shmid < 0)
    {
        perror("shmget");
        return 0;
    }

    struct shmid_ds buf;
    shmctl(shmid, IPC_STAT, &buf);
    printf("shm_size:%ld\n", buf.shm_segsz);

    void* lp = shmat(shmid, NULL, 0);
    if(!lp)
    {
        perror("shmat");
        return 0;
    }

    while(1)
    {
        printf("readshm read [%s]\n", (char*)lp);
        sleep(1);
    }
    shmdt(lp);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
#endif


#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

#define shm_key 0x99999999
int main()
{
    int shmid = shmget(shm_key, 1024, IPC_CREAT | 0664);
    if(shmid < 0)
    {
        perror("shmget");
        return 0;
    }

    void* lp = shmat(shmid, NULL, 0);
    if(!lp)
    {
        perror("shmat");
        return 0;
    }

    int i = 0;
    while(1)
    {
        sprintf((char*)lp, "%s-%d", "linux", i);
        i++;
        sleep(1);
    }
    //shmdt(lp);
    //shmctl(shmid, IPC_RMID, NULL)
    return 0;
}

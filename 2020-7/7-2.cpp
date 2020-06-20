/*************************************************************************
  > File Name: 7-2.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月19日 星期五 16时32分29秒
 ************************************************************************/

#include "Header.hpp"

#if 0
int main()
{
    key_t key = ftok(".",0x6666);
    int shmid = shmget(key,4096,IPC_CREAT);

    char* addr = (char*)shmat(shmid,nullptr,0);

    for(int i = 0;i < 10;i++)
    {
        addr[i] = 'A' + i;
        cout<<"flag"<<endl;
        addr[i + 1] = 0;
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


#if 0
int main()
{
    int fd[2];

    int ret = pipe(fd);

    if(ret < 0)
    {
        return -1;
    }

    write(fd[1],"hello wolf", 12);

    char temp[1024] = {0};

    read(fd[0],temp,sizeof(temp));

    cout<<temp<<endl;
    return 0;
}
#endif

#if 0
int main()
{
    int fd[2];

    int ret = pipe(fd);

    pid_t pid = fork();

    if(pid == 0)
    {
        close(fd[0]);
        while(1)
            write(fd[1],"hello wolf", 12);
    }
    else if(pid > 0) 
    {

        while(1)
        {
            close(fd[1]);
            char temp[1024] = {0};

            read(fd[0],temp,sizeof(temp));

            cout<<temp<<endl;

        }}

    while(1);
    return 0;
}
#endif

#if 0
void Handler(int)
{
    cout<<"i am Handler"<<endl;
}

int main()
{
    //struct sigaction newact;
    //newact.sa_handler = Handler;

    //sigaction(2,&newact,nullptr);

    struct sigaction newact;
    newact.sa_handler = Handler;
    sigaction(2,&newact,nullptr);
    sigaction(40,&newact,nullptr);

    //sigset_t newset;
    //sigaddset(&newset,2);
    //sigprocmask(SIG_BLOCK,&newset,nullptr);


    //getchar();

    //sigprocmask(SIG_UNBLOCK,&newset,nullptr);
    //struct sigaction oldact;
    //struct sigaction newact;
    //newact.sa_handler = Handler;
    //sigemptyset(&newact.sa_mask);
    //newact.sa_flags = 0;

    //sigaction(2, &newact, &oldact);
    //signal(2,Handler);
    //signal(40,Handler);

    sigset_t newset;
    sigaddset(&newset,2);
    sigaddset(&newset,40);
    sigprocmask(SIG_BLOCK,&newset,nullptr);
    
    getchar();

    sigprocmask(SIG_UNBLOCK,&newset,nullptr);

    while(1);
    return 0;
}
#endif

void* ThreadEntry(void* arg)
{
    cout<<"i am thread"<<endl;
    pthread_detach(*(pthread_t*)arg);
    return nullptr;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid,nullptr,ThreadEntry,&tid);
    //pthread_join(tid,nullptr);
    cout<<"i am main thread"<<endl;

    return 0;
}

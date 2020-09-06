/*************************************************************************
# File Name: 9-5.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月06日 星期日 09时46分37秒
 *************************************************************************/
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <mqueue.h>
using namespace std;

int golobal = 0;
pthread_mutex_t _mutex;
pthread_cond_t _cond1;
pthread_cond_t _cond2;

void* ThreadEntry1(void* arg)
{
    (void)arg;
    pthread_mutex_lock(&_mutex);
    while(golobal <= 100)
    {
        pthread_cond_signal(&_cond2);
        golobal++;
        cout<<"i am thread1 : "<<pthread_self()<<" ： "<<golobal<<endl;
        sleep(2);
        pthread_cond_wait(&_cond1,&_mutex);
    }
    pthread_mutex_unlock(&_mutex);
    return nullptr;
}

void* ThreadEntry2(void* arg)
{
    (void)arg;
    pthread_mutex_lock(&_mutex);
    while(golobal <= 100)
    {
        pthread_cond_signal(&_cond1);
        golobal++;
        cout<<"i am thread2 : "<<pthread_self()<<" ： "<<golobal<<endl;
        sleep(3);
        pthread_cond_wait(&_cond2,&_mutex);
    }
    pthread_mutex_unlock(&_mutex);
    return nullptr;
}

int main()
{
    pthread_mutex_init(&_mutex,nullptr);
    pthread_cond_init(&_cond1,nullptr);
    pthread_cond_init(&_cond2,nullptr);

    pthread_t tid[2];
    pthread_create(&tid[0],nullptr,ThreadEntry1,nullptr);
    pthread_create(&tid[1],nullptr,ThreadEntry2,nullptr);

    for(int i = 0;i < 2;i++)
    {
        pthread_join(tid[i],nullptr);
    }

    pthread_mutex_destroy(&_mutex);
    pthread_cond_destroy(&_cond1);
    pthread_cond_destroy(&_cond2);
    return 0;
}

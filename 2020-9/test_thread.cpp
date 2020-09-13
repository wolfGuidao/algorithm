/*************************************************************************
# File Name: test_thread.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月12日 星期六 20时48分43秒
 *************************************************************************/
#include <iostream>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

using namespace std;

pthread_mutex_t  lock;
int a = 0;

void* A(void* arg){

    while(true){
        pthread_mutex_lock(&lock);
        if(a < 100 && a % 2 == 1){
            ++a;
            cout<<"A--->"<<a<<endl;
            pthread_mutex_unlock(&lock);
        }
        else{
            pthread_mutex_lock(&lock);
            break;
        }
        usleep(100); 
    }
    return nullptr;
}


void* B(void* arg){ 

    while(true){
        pthread_mutex_lock(&lock);
        if(a < 100 && a%2 == 0){
            ++a;
            cout<<"B-->"<<a<<endl;
            pthread_mutex_unlock(&lock);
        }
        else{
            pthread_mutex_lock(&lock);
            break;
        }
        usleep(100); 
    }
    return nullptr;
}

int main(){
    pthread_t t1, t2;

    pthread_create(&t1, nullptr, A, nullptr);
    pthread_create(&t2, nullptr, B, nullptr);

    pthread_exit(&t1);
    pthread_exit(&t2);

    return 0;
}

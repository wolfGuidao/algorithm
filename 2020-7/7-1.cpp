/*************************************************************************
    > File Name: 7-1.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月19日 星期五 12时49分26秒
 ************************************************************************/

#include "Header.hpp"
#include <boost/timer.hpp>

int main()
{
    pthread_rwlock_t rwlock;
     boost::timer timer;
    time_t begin = clock();
    pid_t pid = vfork();
    if(pid < 0)
    {
        perror("vfork error");
        return -1;
    }
    else if(pid == 0)
    {
        cout<<"i am child"<<endl;
        sleep(3);
        exit(0);
    }
    else 
    {
        cout<<" i am father"<<endl;
    }
    time_t end = clock();
    cout<<(end - begin) /CLOCKS_PER_SEC<<endl;
    cout<<" cost time: "<<timer.elapsed() <<endl;
    return 0;
}


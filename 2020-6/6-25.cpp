/*************************************************************************
    > File Name: 6-25.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月13日 星期六 11时41分52秒
 ************************************************************************/

#include "Header.hpp"

int main()
{
    pid_t pid1 = fork();
    if(pid1 < 0)
    {
        perror("fork");
    }
    else if(pid1 == 0)
    {

        printf("i am child1:%d\n",pid1);
    }
    
    //pid_t pid2 = fork();
    //if(pid2 < 0)
    //{
    //    perror("fork");
    //}
    //else if(pid2 == 0)
    //{
    //    printf("i am child2:%d\n",pid2);
    //}
    //printf("i am father1:%d\n",pid1); 
    //printf("i am father2:%d\n",pid2); 
    int status;
    pid_t pid = waitpid(-1,&status,0);
    printf("i wait a pid: %d\n",pid);
    if(WIFEXITED(status))
    {
        cout<<WEXITSTATUS(status)<<endl;
    }
    return 0;
}


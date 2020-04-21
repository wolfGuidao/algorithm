#include "Header.hpp"

int main()
{
  int fd[2];

  int ret = pipe(fd);

  int pid = fork();
  if(pid == 0)
  {
    //close(fd[0]);

    char buf[1024] = "hello";
    printf("i am child,i write: %s\n",buf);
    while(1)
    {
      write(fd[1],buf,sizeof(buf));
    }
      close(fd[1]);
  }
  else if(pid > 0)
  {
    //close(fd[1]);

    sleep(3);
    char buf[1024] = {0};
    int size = read(fd[0],buf,60);
    if(size < 0)
    {
      perror("read");
      return -1;
    }
    else if(size == 0)
    {
      perror("read error");
    }
    else 
    {
      printf("i am father,i read : %s\n",buf);
    }
    close(fd[0]);
  
  }
  return 0;
}

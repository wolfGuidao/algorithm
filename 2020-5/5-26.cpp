#include "Header.hpp"

#if 0
void funcnal(int sig)
{
  cout<<"i am a sig"<<endl;
}

int main()
{
  int fds[2];
  if(pipe(fds))
  {
    perror("pipe");
    exit(-1);
  }

  pid_t pid = fork();
  if(pid < 0)
  {
    perror("fork");
    exit(-1);
  }
  else if(pid == 0)
  {
    close(fds[0]);
    //close(fds[1]);
    while(1)
    {
      cout<<"i am child ,i am write input in guandao :"<<endl;
      char buf[1024] = {0};
      cin>>buf;
      write(fds[1],buf, sizeof(buf));
    }
  }

  close(fds[1]);
  close(fds[0]);
  //while(1)
  //{
  //  //sleep(10);
  //  //cout<<"i am fathet ,i am read output in guandao :"<<endl;
  //  //char temp[1024] = {0};
  //  //int ret = read(fds[0],temp,1024);

  //  //cout<<temp<<"ret : "<<ret<<endl;
  //}
  sleep(10);
  
  signal(SIGPIPE,funcnal);
  return 0;
}
#endif

void SignalFunc(int sig)
{
  cout<<"i catch a sig: "<<sig<<endl;
  exit(-1);
}

void Print(sigset_t set_info)
{
  for(int i = 0;i < 32;i++)
  {
    if(sigismember(&set_info, i))
    {
      putchar('1');
    }
    else 
    {
      putchar('0');
    }
        
  }
}

int main()
{
  //sigset_t s;
  //sigemptyset(&s);
  //sigaddset(&s, 2);
  //sigset_t out;
  //sigprocmask(SIG_BLOCK,&s, &out);
  //sigset_t info;
  //sigpending(&info);
  //while(1)
  //{
  //  Print(out);
  //  Print(info);
  //}
  
  struct sigaction action;
  action.sa_handler = SignalFunc;
  sigaction(2, &action, NULL);
  while(1);
}

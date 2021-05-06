#include<stdio.h>
#include<fcntl.h>
#include<syslog.h>
#include<errno.h>
int main()
{
int fd=-1,fd1=-1,fd2=-1;
fd=open("a.txt",O_RDONLY,0777);
fd1=open("b.txt",O_CREAT,0777);
fd2=open("c.txt",O_CREAT,0777);
printf("the fd:%d\n and fd1:%d\n and fd2:%d\n",fd,fd1,fd2);
syslog(LOG_ERR,"error -occured=%m");
printf("error is %d and redable error msg is %s\n",errno,strerror(errno));
return 0;
}

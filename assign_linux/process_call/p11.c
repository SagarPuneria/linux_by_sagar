#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	pid_t pid;
	int status,i;
	for(i=0;i<argc;i++)
		printf("%s\n",argv[i]);
	printf("above forkz\n");
	pid=fork();
	if(pid>0)
	{
		printf("in parent pid: %d,ppid :%d,pgid :%d\n",getpid(),getppid(),getpgid(pid));
	}
	else
	{
		printf("in child pid: %d,ppid:%d,pgid :%d\n",getpid(),getppid(),getpgid(pid));
		execvp(argv[1],argv+1);
		printf("after execl\n");
		_exit(6);
	}
	wait(&status);
	printf("status=%d\n",WEXITSTATUS(status));	
	return 0;
}


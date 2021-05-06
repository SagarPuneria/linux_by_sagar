#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
int main()
{
	pid_t pid;
	int status;
	printf("above forkz\n");
	pid=fork();
	if(pid>0)
	{
	 printf("in parent %d\n",getpid());
	}
	else
	{
	printf("in child%d\n",getpid());
	
	execl("./6","./6",NULL);
	_exit(0);
	}
	wait(&status);
return 0;
}


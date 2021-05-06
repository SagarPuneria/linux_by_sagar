#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>



int main()
{
	pid_t pid;
	int status;
	pid=fork();
	if(pid>0)
	{
	 printf("in parent 6.c\n");
	//while(1)
	//{
	//}
	//wait(&status);
	}
	else
	{
	 printf("in child 6.c");
		//sleep(10);
	// _exit(0);
	}
	//wait(&status);
return 0;
}

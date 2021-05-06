#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
int main()
{
	pid_t pid;
	int i,status;
	pid=fork();
	if(pid>0)
	{
		printf("in parent 6.c\n");
	}
	else
	{
		sleep(3);
		printf("enter number\n");	
		scanf("%d",&i);
		printf("i=%d\n",i);
		printf("in child 6.c\n");
		_exit(2);//By using this exit codes the parent can read status of child
	}
	printf("parent is\n");
		
	i=wait(&status);//use wait() call in parent to avoid zombie process
	printf("wait returns child pid=%d\n",i);
	printf("exit status of child=%d\n",WEXITSTATUS(status));
	return 0;
}

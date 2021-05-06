#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
int main()
{
	pid_t pid;
	int i,w;
	pid=fork();
	if(pid>0)
	{
		printf("in parent 6.c\n");
		//wait(&w);/* By using wait() call we can avoid orphan process */
		printf("parent is\n");
		exit(0);	
	}
	else
	{
		//sleep(3);
		printf("enter number\n");	
		scanf("%d",&i);
		printf("i=%d\n",i);
		printf("in child 6.c\n");
	}
	//wait(&w);/* By using wait() call we can avoid orphan process */
	//printf("parent is\n");
	return 0;
}

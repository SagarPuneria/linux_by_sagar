#include<unistd.h>
#include<stdio.h>
int main()
{
	pid_t pid;
	printf("above fork\n");
	pid=fork();
	if(pid>0)
	{
		printf("in parent :%d,the fork returns child pid :%d\n",getpid(),pid);
	}
	else
	{
		printf("in child :%d,the fork returns zero :%d\n",getpid(),pid);
	}
	return 0;
}



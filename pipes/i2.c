#include<stdio.h>
#include<unistd.h>
int main()
{
	int pfd[2];
	int ret;
	char buff[20];
	ret=pipe(pfd);
	if(ret<0)
	{
		perror("pipe create failed\n");
		return -1;
	}
	ret=fork();
	if(ret<0)
	{
		perror("fork failed\n");
		return -1;
	}
	else if(ret>0)
	{//parent
		close(pfd[0]);
		close(1);
		dup(pfd[1]);
		execl("/bin/ls","ls","-l",NULL);
		printf("PARENT:execl failed\n");
	}
	else if(ret==0)
	{//child
		close(pfd[1]);
		close(0);
		dup(pfd[0]);
		execl("/usr/bin/wc","wc",NULL);
		printf("CHILD:execl failed\n",buff);
	}
	return 0;
}

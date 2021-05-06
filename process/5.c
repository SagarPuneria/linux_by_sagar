#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>
 #include <unistd.h>
int main()
{
	pid_t pid;
	int w;
	int fd=-1;
	fd=open("xyz1.txt",O_CREAT|O_RDWR|O_TRUNC,0644);
	pid=fork();
//	fd=open("xyz1.txt",O_CREAT|O_RDWR);
	if(pid>0)
	{
		printf("from parent\n");
		write(fd,"inparent",9);
	}
	else
	{
		sleep(3);
		printf("from child\n");
		write(fd,"inchild",8);
		_exit(7);
	}
	wait(&w);
	printf("status=%d\n",WEXITSTATUS(w));
	return 0;
}

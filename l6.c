#include<stdio.h>
#include<fcntl.h>
#include<string.h>
main()
{
	int fd1=-1,ret=0,fd2=-1;
	fd1=open("file.txt",O_CREAT|O_TRUNC|O_RDWR,0644);
	printf("Before dup2 fd1=%d\n",fd1);
	fd2=dup2(fd1,1);//fd1=3
	printf("After dup2 fd2=%d\n",fd2);//fd2=1
}

//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int fd=-1,ret=-1;
	char buf[200];
	fd=open("file.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open failed\n");
		return -1;
	}
	ret=lseek(fd,5,SEEK_END);
	printf("%d\n",ret);
	ret=read(fd,buf,sizeof(buf));
	if(ret<=0)
	{
		perror("read failed\n");
		return -1;
	}
	fd=open("file1.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd<0)
	{
		perror("open failed\n");
		return -1;
	}
	ret=write(fd,buf,strlen(buf)+1);
	if(ret<0)
	{
		perror("write failed\n");
		return -1;
	}
	//memset(buf,'\0',sizeof(buf));
	close(fd);
}

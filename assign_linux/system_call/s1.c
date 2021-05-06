//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int fd=-1,ret=-1;
	char buf[25]="sagar";
	fd=open(argv[1],O_CREAT|O_TRUNC|O_RDWR|O_EXCL,0644);
	printf("fd=%d\n",fd);
	if(fd<0)
	{
		perror("open failed\n");
		return -1;
	}
	ret=write(fd,buf,strlen(buf)+1);
	printf("write=%d\n",ret);
	if(ret<0)
	{
		perror("write failed\n");
		return -1;
	}
	printf("written succesfull\n");
	//memset(buf,'\0',sizeof(buf));
	lseek(fd,0,SEEK_SET);//take another arrry buffer for read call to avoid lseek()
	ret=read(fd,buf,sizeof(buf));
	//buf[ret]='\0';
	printf("read=%d\n",ret);
	if(ret<0)
	{
		perror("read failed\n");
		return -1;
	}
	printf("read data is\n%s\n",buf);
	close(fd);
}

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
main()
{
	int fd1=-1,ret=0,fd2=4;
	char buf[20]="agfakjv";
	fd1=open("abc.txt",O_CREAT|O_RDWR,0644);
	if(fd1<0)
	{
		perror("open failed\n");
		return -1;
	}
	fd2=dup(fd1);
	printf("%d\n",fd2);
	printf("%d\n",fd1);
	ret=write(fd2,buf,strlen(buf)+1);
	printf("write=%d\n",ret);	
	printf("%d\n",fd2);
	if(ret<0)
	{
		perror("write failed\n");
		return -1;
	}
	printf("written succesfull\n");
	//memset(buf,'\0',sizeof(buf));
	lseek(fd2,0,SEEK_SET);//take another arrry buffer for read call to avoid lseek()
	ret=read(fd2,buf,sizeof(buf));
	//buf[ret]='\0';
	printf("read=%d\n",ret);
	if(ret<0)
	{
		perror("read failed\n");
		return -1;
	}
	printf("read data is\n%s\n",buf);
	close(fd2);
	close(fd1);
}

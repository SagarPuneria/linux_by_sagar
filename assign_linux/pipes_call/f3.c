#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd1=-1,fd2=-1,ret;
	char buff[20];
	fd1=open("MYFIFO1",O_WRONLY);
	if(fd1<0)	
	{
		if(mkfifo("MYFIFO1",0644)<0)
		{
			perror("FIFO create failed\n");
			return -1;
		}
		else
			fd1=open("MYFIFO",O_WRONLY);
		
	}
	fd2=open("MYFIFO2",O_RDONLY);
	if(fd2<0)	
	{
		if(mkfifo("MYFIFO2",0644)<0)
		{
			perror("FIFO create failed\n");
			return -1;
		}
		else
			fd2=open("MYFIFO",O_RDONLY);
		
	}
	ret=fork();
	if(ret<0)
	{
		perror("fork failed\n");
		return -1;
	}
	else if(ret>0)
	{
	close(fd2);
	write(fd1,"hello FIFO",11);
	printf("data written to FIFO\n");
	//close(fd1);
	}
	else if(ret==0)
	{
	close(fd1);
	read(fd2,buff,sizeof(buff));
	printf("data read is %s\n",buff);
	//unlink("./MYFIFO");
	//close(fd2);
	}
	return 0;
}

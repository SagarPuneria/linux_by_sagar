#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd=-1;
	char buff[20];
	fd=open("MYFIFO",O_RDONLY);
	if(fd<0)	
	{
		if(mkfifo("MYFIFO",0644)<0)
		{
			perror("FIFO create failed\n");
			return -1;
		}
		else
			fd=open("MYFIFO",O_RDONLY);
		
	}
	read(fd,buff,sizeof(buff));
	printf("data read is %s\n",buff);
	unlink("./MYFIFO");
	close(fd);
	return 0;
}

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd=-1;
	fd=open("MYFIFO",O_WRONLY);
	if(fd<0)	
	{
		if(mkfifo("MYFIFO",0644)<0)
		{
			perror("FIFO create failed\n");
			return -1;
		}
		else
			fd=open("MYFIFO",O_WRONLY);
		
	}
	write(fd,"hello FIFO",11);
	printf("data written to FIFO\n");
	close(fd);
	return 0;
}

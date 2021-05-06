#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int ret,fd;
	ret=mkfifo("MYFIFO",0644);
	if(ret<0)
	{
		perror("FIFO create failed\n");
		return -1;
	}
	fd=open("MYFIFO",O_WRONLY);
	if(fd<0)	
	{
		perror("FIFO open failed\n");
		unlink("./MYFIFO");
		return -1;
	}
	write(fd,"hello FIFO",11);
	printf("data written to FIFO\n");
	close(fd);
	return 0;
}

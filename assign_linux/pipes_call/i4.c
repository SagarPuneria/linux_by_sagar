#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int ret,fd;
	char buff[20];
	/*ret=mkfifo("MYFIFO",0644);
	if(ret<0)
	{
		perror("FIFO create failed\n");
		return -1;
	}*/
	fd=open("MYFIFO",O_RDONLY);
	if(fd<0)	
	{
		perror("FIFO open failed\n");
		//unlink("MYFIFO");
		return -1;
	}
	read(fd,buff,sizeof(buff));
	printf("data read is %s\n",buff);
	unlink("./MYFIFO");
	close(fd);
	return 0;
}

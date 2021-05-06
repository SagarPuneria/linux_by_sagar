#include <fcntl.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int fd=-1;
	char buf[200];
	fd=open("file.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open failed\n");
		return -1;
	}
	read(fd,buf,sizeof(buf));
	printf("%s\n",buf);
	return 0;
}

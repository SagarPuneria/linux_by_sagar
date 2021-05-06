#include <sys/stat.h>
#include <sys/types.h>
#include<stdio.h>
int main()
{
	int r;
	r=mkdir("./folder",0755);
	if(r==-1)
	{
		perror("error");
		return -1;
	}
	printf("folder is created\n");
	sleep(15);
	r=rmdir("./folder");
	if(r==-1)
	{
		perror("error");
		return -1;
	}
	printf("folder is deleted\n");
}

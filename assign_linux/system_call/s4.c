#include <fcntl.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int fd=-1,i=0,ret=1;
	char c;
	int ch;
	fd=open("myfile",O_RDONLY);
	if(fd<0)
	{
		perror("open failed\n");
		return -1;
	}
	lseek(fd,0,SEEK_SET);
	/*while(c!='\0')
	{
		lseek(fd,i,SEEK_SET);
		ret=read(fd,&c,1);
		//printf("%d\n",ret);
		if(ret==1)
		{
			printf("%c",c);
			i++;
//		ch=c;		
		}	
	}*/
	while(ret==1)
	{
		lseek(fd,i,SEEK_SET);
		ret=read(fd,&c,1);
		//printf("%d\n",ret);
		if(ret==1)
		{
			printf("%c",c);
			i++;
//		ch=c;		
		}	
	}
	printf("len=%d\n",i);
	return 0;
}

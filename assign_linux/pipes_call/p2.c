#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int p1[2],p2[2];
	int ret,i,n;
	char buff[20];
	ret=pipe(p1);
	if(ret<0)
	{
		perror("pipe1 create failed\n");
		return -1;
	}
	ret=pipe(p2);
	if(ret<0)
	{
		perror("pipe2 create failed\n");
		return -1;
	}
	ret=fork();
	if(ret<0)
	{
		perror("fork failed\n");
		return -1;
	}
	else if(ret>0)
	{//parent
		close(p1[0]);
		close(p2[1]);
		printf("Enter string string\n");
		scanf("%s",buff);
		write(p1[1],buff,strlen(buff)+1);
		printf("PARENT: msg written to pipe1 success\n");
		read(p2[0],buff,sizeof(buff));
		printf("PARENT:read msg from pipe2 is %s\n",buff);
	}
	else if(ret==0)
	{//child
		close(p1[1]);
		close(p2[0]);
		n=read(p1[0],buff,sizeof(buff));
		for(i=0;i<n;i++)
		{
			if((buff[i]>='A') && (buff[i]<='Z'))
				buff[i]+=32;
			else //if((buff[i]>='a') && (buff[i]<='z'))
				buff[i]-=32;
		}
		buff[n]='\0';
		write(p2[1],buff,strlen(buff)+1);
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int pfd[2];
	int ret,i,n;
	char buff[20];
	ret=pipe(pfd);
	if(ret<0)
	{
		perror("pipe create failed\n");
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
		close(pfd[0]);
		printf("Enter string\n");
		scanf("%s",buff);
		write(pfd[1],buff,strlen(buff)+1);
		printf("PARENT: msg written to pipe success\n");
	}
	else if(ret==0)
	{//child
		close(pfd[1]);
		read(pfd[0],buff,sizeof(buff));
		for(i=0;buff[i]!='\0';i++)
		{
			if((buff[i]>='A') && (buff[i]<='Z'))
				buff[i]+=32;
			else //if((buff[i]>='a') && (buff[i]<='z'))
				buff[i]-=32;
		}
		printf("CHILD:read msg is %s\n",buff);
	}
	return 0;
}

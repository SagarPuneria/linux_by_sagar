#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int a,char *argv[])
{
	extern char **environ;
	int i=0;
	setenv("PWD","/usr",1);
	printf("PWD value is %s\n",getenv("PWD"));
	while(environ[i]!=NULL)
	{
	 printf("the env name_val pair is:%s \n",environ[i]);
	 i++;
	}
return 0;
}
	

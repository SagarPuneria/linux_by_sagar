#include<stdio.h>
#include<unistd.h>
main()
{
	extern char **environ;
	int i=0;
	while(environ[i]!=NULL)
	{
		printf("the environment name val pair is %s\n",environ[i]);
		i++;
	}
}

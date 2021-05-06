#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int a1,char *argv[])//i/p:-PATH,HOME,PWD
{
	int i=0;
	char *env_val=NULL;
	if(a1!=2)
	{
	 printf("error");
	 exit(1);
	}
	env_val=getenv(argv[1]);
	printf("the val %s = %s\n",argv[1],env_val);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
	int i=0;
	char *en=NULL;

	en=getenv(argv[1]);
	printf("val of pwd is %s\n",en);//o/p:- /home/batch1/linux

	putenv("PWD=/
home/");
	printf("new pwd is %s\n",getenv("PWD"));//o/p:- /home/batch1/linux

	setenv("PWD","/usr/",0);
	printf("new pwd is %s\n",getenv("PWD"));//o/p:- /home/batch1/linux

	setenv("PWD","/usr/",1);
	printf("new pwd is %s\n",getenv("PWD"));//o/p:- /usr/
}

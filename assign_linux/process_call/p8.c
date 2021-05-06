#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main ()
{
	int a = 10, b = 20, c;
	if (!fork ())
	{
		a = b + 10;
		c = a + b + 2;
		printf ("child:1st case: C=%d\n", c);//o/p:-C=52
		exit (0);
	}
	//else
	//{
		b = a + 10;
		c = a + b + 10;
		printf ("parent:2nd Case: C=%d\n", c);//o/p:-C=40
	//}
	/*
	int x=20,stat;
	if(fork()==0)
	{
		x=40;
		exit(5);
	}
	wait(&stat);
	printf("%d\n",x);*/
	return 1;
}

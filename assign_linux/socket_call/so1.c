#include<unistd.h>
#include<stdio.h>
int main()
{
	char buff[20];
	gethostname(buff,20);
	printf("machine hostname=%s\n",buff);
}

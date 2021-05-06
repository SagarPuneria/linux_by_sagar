#include <time.h>
#include<stdio.h>

int main()
{

	long now,t1;
	t1=time(&now);
	printf("ctime(&now)=%s\n",ctime(&now));
	printf("t1=%ld\n",t1);
	sleep(3);
	t1=time(&now);
	printf("t1=%ld\n",t1);
	
}


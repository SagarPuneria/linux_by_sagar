#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<syslog.h>
main()
{
	int fd=-1;
	fd=open("file.txt",O_CREAT|O_RDONLY|O_EXCL,0644);
	syslog(LOG_ERR,"error_occured=%m");
	printf("error is %s\n",strerror());
	printf("error is %d and readable error mesg is %s\n",errno,strerror(errno));	
}

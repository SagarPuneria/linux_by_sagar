#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
int main()
{
	pid_t pid;
	char *const argv[]={"ls","-l",NULL};
	int status;
	printf("above forkz\n");
	pid=fork();
	if(pid>0)
	{
		printf("in parent :%d,the fork returns child pid :%d\n",getpid(),pid);
	}
	else
	{
		printf("in child :%d,the fork returns zero :%d\n",getpid(),pid);
		//execv("/bin/ls",argv);//default		
		//execv("ls",argv);//wrong
		//execvp("ls",argv);//default
		//execvp("/bin/ls",argv);//ok
		
		//execl("/bin/ps","ps","ax",NULL);//default
		//execl("ps","ps","ax",NULL);//wrong
		//execlp("ps","ps","ax",NULL);//default
		//execlp("/bin/ps","ps","ax",NULL);//ok
		printf("after execl\n");
		_exit(6);
	}
	wait(&status);
	printf("status=%d\n",WEXITSTATUS(status));	
	return 0;
}


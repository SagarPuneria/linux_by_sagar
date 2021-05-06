#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	pid_t pid;
	int status,i;
	for(i=0;i<argc;i++)
		printf("%s\n",argv[i]);
	printf("above forkz\n");
	pid=fork();
	if(pid>0)
	{
		printf("in parent :%d,the fork returns child pid :%d\n",getpid(),pid);
	}
	else
	{
		printf("in child :%d,the fork returns zero :%d\n",getpid(),pid);
		//execv("/bin/ls",argv+1);//default		
		//execv("ls",argv+1);//wrong
		execvp(argv[1],argv+1);//default
		//execvp("ls",argv+1);//default
		//execvp("/bin/ls",argv+1);//ok

		//sleep(10);
		//execl("/bin/ps","ps","ax",NULL);//default
		//execl("ps","ps","ax",NULL);//wrong
		//execlp("ps","ps","ax",NULL);//default
		//execlp("/bin/ps","ps","ax",NULL);//ok
		printf("after execl\n");
		_exit(6);
	}
	wait(&status);
	printf("status=%d\n",WEXITSTATUS(status));	
	if(WIFEXITED(status))
		printf("exited normally\n");
	else if(WIFSIGNALED(status))
		printf("exited by signal\n");
	return 0;
}

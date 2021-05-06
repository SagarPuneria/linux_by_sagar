#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
main(int argc,char *argv[])
{
	pid_t id;
	int w,i;
	char cmdbuf[10],strbuf[10],*cmdarg[3];
	for(i=0;i<argc;i++)
		printf("argv[%d]-->%s\n",i,argv[i]);
/*	while(1)
	{
		printf("myshell>");
		scanf("%s %s",cmdbuf,strbuf);
		//scanf("%s",strbuf);
		cmdarg[0]=cmdbuf;
		if((strlen(cmdbuf)==2) && (strlen(strbuf)==2))
		{
			cmdarg[1]=strbuf;
			cmdarg[2]='\0';
		}		
		else
			cmdarg[1]='\0';
		id=fork();
		if(id==0)
		{
			execvp(cmdbuf,cmdarg);
			printf("sagar\n");
		}
		wait(&w);
	}
	/*while(1)
	{
		printf("myshell>\n");
		sleep(1);		


		cmdarg[0]=argv[1];
		if(argc<3)
			cmdarg[1]='\0';
		else
		{
			cmdarg[1]=argv[2];
			cmdarg[2]='\0';
		}
		id=fork();
		if(id==0)
		{
			execvp(argv[1],cmdarg);
			printf("sagar\n");
		}
		wait(&w);
		
	}*/

	while(1)
	{
		printf("myshell>");
		gets(cmdbuf);
		cmdarg[0]=cmdbuf;
		cmdarg[1]='\0';
		id=fork();
		if(id==0)
		{
			execvp(cmdbuf,cmdarg);
		}
		wait(&w);
	}
}
	

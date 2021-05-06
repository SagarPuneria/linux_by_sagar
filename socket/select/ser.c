#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
 #include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
       #include <netinet/in.h>
       #include <arpa/inet.h>
	#include<sys/select.h>
int main()
{
	int listenfd,ret,size,sessfd;
	struct sockaddr_in saddr,caddr;
	char buff[100];
	int maxfd,fd,val=1;
	fd_set readset,iset;
	/*creating the end point of communication*/
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	if(listenfd<0){
		printf("socket creation failed\n");
		return 0;
	}

	setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&val,sizeof(val));
	/*naming the socket(usr/include/linux/in.h)*/
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(9000);//server port
	//saddr.sin_addr.s_addr=htonl(INADDR_ANY);
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");//$man inet_addr
	ret=bind(listenfd,(struct sockaddr *)&saddr,sizeof(saddr));
	if(ret<0)
	{
		printf("bind failed\n");
		return 0;
	}

	listen(listenfd,5);
	maxfd=listenfd;
	FD_ZERO(&readset);
	FD_SET(listenfd,&readset);
	while(1)
	{
		//printf("before accept");
		iset=readset;
		ret=select(maxfd+1,&iset,NULL,NULL,NULL);
		if(ret<0)
		{
			printf("confailed");
			return 0;
		}
		if (FD_ISSET(listenfd,&iset))
		{
			size=sizeof(caddr);
			sessfd=accept(listenfd,(struct sockaddr *)&caddr,&size);
			if(sessfd<0)
			{
				printf("accept failed");
				continue;
			}
		 	FD_SET(sessfd,&readset);
			if(maxfd<sessfd)
			maxfd=sessfd;
		}
		for(fd=0;fd<=maxfd;fd++)
		{
			if(FD_ISSET(fd,&iset)&&(fd!=listenfd))
			{
				memset(buff,0,sizeof(buff));
				ret=read(fd,buff,sizeof(buff));
				if(ret==0)
				{
					close(fd);
					 FD_CLR(fd,&readset);
					 continue;
				}
				printf("data read :%s\n",buff);
				write(fd,buff,sizeof(buff));
			}
		 }
	}
	return 0;
}

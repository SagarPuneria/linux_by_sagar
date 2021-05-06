#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<string.h>
int main()
{
	struct req
	{
		float x;
		float y;
		char op;

	}buff1;
	struct res
	{
		float res;
	}buff2; 
	int listenfd,ret,size,sessfd;
	struct sockaddr_in saddr,caddr;
	char buff[100];
	int val=1;

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

	while(1)
	{
		memset(buff,0,sizeof(buff));
		size=sizeof(caddr);
		printf("before accept\n");

		sessfd=accept(listenfd,(struct sockaddr *)&caddr,&size);
		if(sessfd<0)
		{
			printf("accept failed\n");
			continue;
		}
		printf("after accept\n");
		printf("client ip:%s,client port:%d\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port)); 

		read(sessfd,&buff1,sizeof(buff1));
		//printf("data read %s\n",buff1);
		switch(buff1.op)
		{
			case '+':buff2.res=buff1.x+buff1.y;
					break;
			case '-':buff2.res=buff1.x-buff1.y;
					break;
			case '*':buff2.res=buff1.x*buff1.y;
					break;
			case '/':buff2.res=buff1.x/buff1.y;
					break;
			default:buff2.res=-999;
		}
		write(sessfd,&buff2,sizeof(buff2));
		close(sessfd);
	}
	return 0;
}

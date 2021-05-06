#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<string.h>
int main()
{
	int sockfd,ret,size,sessfd;
	struct sockaddr_in saddr,caddr;
	char buff[100];
	int val=1;

	/*creating the end point of communication*/
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0){
		printf("socket creation failed\n");
		return 0;
	}

	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&val,sizeof(val));
	/*naming the socket(usr/include/linux/in.h)*/
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(9000);//server port
	//saddr.sin_addr.s_addr=htonl(INADDR_ANY);
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");//$man inet_addr
	ret=bind(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));
	if(ret<0)
	{
		printf("bind failed\n");
		return 0;
	}
	size=sizeof(caddr);
	while(1)
	{
		recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&caddr,&size);
		sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&caddr,sizeof(caddr));
		printf("data received is %s\n",buff);
	}
	return 0;
}

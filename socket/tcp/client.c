#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<string.h>
int main()
{
	int sockfd,ret,size;
	struct sockaddr_in saddr,caddr;
	char buff[100];

	/*creating the end point of communication*/
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		printf("socket creation failed\n");
		return 0;
	}

	/*naming the socket(usr/include/linux/in.h)*/
	/*caddr.sin_family=AF_INET;
	caddr.sin_port=htons(9234);//client port
	//caddr.sin_addr.s_addr=htonl(INADDR_ANY);
	caddr.sin_addr.s_addr=inet_addr("127.0.0.1");//$man inet_addr
	ret=bind(sockfd,(struct sockaddr *)&caddr,sizeof(caddr));
	if(ret<0)
	{
		printf("bind failed\n");
		return 0;
	}*/

	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(9000);
	//saddr.sin_addr.s_addr=htonl(INADDR_ANY);
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");//$man inet_addr
	connect(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));

	size=sizeof(caddr);
	getsockname(sockfd,(struct sockaddr *)&caddr,&size);
	printf("client ip:%s,client port:%d\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));

	memset(buff,0,sizeof(buff));
	strcpy(buff,"welcome to cdac");
	write(sockfd,buff,sizeof(buff));

	memset(buff,0,sizeof(buff));
	read(sockfd,buff,sizeof(buff));
	printf("data read %s\n",buff);

	close(sockfd);
	return 0;
}

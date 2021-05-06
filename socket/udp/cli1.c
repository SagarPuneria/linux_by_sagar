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
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0){
		printf("socket creation failed\n");
		return 0;
	}
	memset(buff,0,sizeof(buff));
	strcpy(buff,"welcome to cdac");
	
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(9000);
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");//$man inet_addr
	sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&saddr,sizeof(saddr));//this UDP dont need to use connect()

	/*connect(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));//this UDP dont need to use connect()
	send(sockfd,buff,sizeof(buff),0);*/	
	//memset(buff,0,sizeof(buff));
	size=sizeof(saddr);
	recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&saddr,&size);
	printf("data received %s\n",buff);
	close(sockfd);
	return 0;
}

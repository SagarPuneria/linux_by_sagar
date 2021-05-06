#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
	int sockfd,ret;
	char buf[100];
	struct sockaddr_in saddr;
	sockfd=socket(AF_INET,SOCK_STREAM ,0); //creating a socket
	if(sockfd<0)
	{
	 	printf("socket failed");
		return 0;
	}	
	saddr.sin_family=AF_INET;	/* Address family		*/
  	saddr.sin_port=htons(9000);	/* Port number			*/
  	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");	/* Internet address		*/
	ret=connect(sockfd, (struct sockaddr *)&saddr,sizeof(saddr));
	memset(buf,0,sizeof(buf));
//	strcpy(buf,"welcome to cdac");
	scanf("%s",buf);
	write(sockfd, buf, sizeof(buf));
	memset(buf,0,sizeof(buf));
	read(sockfd, buf, sizeof(buf));
	printf("data read:%s\n",buf);
	close(sockfd);
return 0;
}

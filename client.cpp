#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
 int sockfd = 0, n = 0;
 char recvBuff[1024];
 char sendbuff[1024];
 struct sockaddr_in cli_addr;
 if(argc != 2)
 {
 printf("\n Usage: %s <ip of server> \n",argv[0]);
 return 1;
 }
 memset(recvBuff, '0',sizeof(recvBuff));
 memset(sendbuff, '0',sizeof(sendbuff));
 if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) //creates a socket
 {
 printf("\n Error : Could not create socket \n");
 return 1;
 }
 memset(&cli_addr, '0', sizeof(cli_addr));
 cli_addr.sin_family = AF_INET;
 cli_addr.sin_port = htons(5000);
 if(inet_pton(AF_INET, argv[1], &cli_addr.sin_addr)<=0)
 {
 printf("\n inet_pton error occured\n");
 return 1;
 }
 if( connect(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr)) < 0) // connecting to the
server
 {
 printf("\n Error : Connect Failed \n");
 return 1;
 }
cout<<"Enter website to send and enter CTRL + Z to exit\n"; // enter the name of
the site you want to receive the ip address
 while(true)
{
cout<<"client: ";
gets(sendbuff); // send buff to read the contents
send(sockfd, sendbuff, 1024,0);
recv(sockfd, recvBuff, 25,0);
cout<<"server: "<<recvBuff<<"\n";

 }
 return 0;
}

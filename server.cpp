#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <iostream>
#include<fstream>
using namespace std;
int main(int argc, char *argv[])
{
ifstream fp ("test");
string line;
char n;
int i=0;
int j,k=0;
char ip[25],website[25];
int listenfd = 0, connfd = 0;
 struct sockaddr_in serv_addr;
 char sendBuff[1025];
 char recvbuff[1025];
if(fp.is_open())
{
getline(fp,line);
while(line[i]!=':'){
ip[i]=line[i];
i++;
}
i++;
j=i;
ip[i]='\0';
while(line[j]!='\0')
{
website[k]=line[j];
j++;
k++;
}
website[k]='\0';
fp.close();
}
else
cout<<"cannot open file\n";
 listenfd = socket(AF_INET, SOCK_STREAM, 0); // listen to the socket
 memset(&serv_addr, '0', sizeof(serv_addr));
 memset(recvbuff, '0',sizeof(recvbuff));
 memset(sendBuff, '0',sizeof(sendBuff));
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
 serv_addr.sin_port = htons(5000);
 bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
// binding to the socket
 listen(listenfd, 10); // listen to the client
cout<<"server sends the IP address";
connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); // accept the request
and respond
 while(true)
 {
recv(connfd,recvbuff, 1024,0);
cout<<"\nClient: "<<recvbuff<<"\n"; // display the ip addresss of the website
 send(connfd, website, 25,0);
 }
}

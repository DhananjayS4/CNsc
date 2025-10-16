#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>  // for printf

int main(int c,char**v){
 if(c<4)return 1;
 int s=socket(2,1,0),n; char b[4096];
 struct sockaddr_in a={2,htons(atoi(v[3])),inet_addr(v[1])};
 printf("Client online...\n");                 // client online message
 if(connect(s,(void*)&a,16))return 1;
 write(s,v[2],strlen(v[2])+1);
 while((n=read(s,b,4096))>0)write(1,b,n);
 printf("\nFile transfer completed successfully.\n"); // completed message
 close(s);
}

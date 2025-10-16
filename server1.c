#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>  // needed for printf

int main(int c,char**v){
 if(c<2)return 1;
 int s=socket(2,1,0),f,n; char b[4096];
 struct sockaddr_in a={2,htons(atoi(v[1])),htonl(INADDR_ANY)};
 bind(s,(void*)&a,16); listen(s,5);
 while(1){
  int cs=accept(s,0,0);
  read(cs,b,4096);
  if((f=open(b,0))<0){close(cs);continue;}
  while((n=read(f,b,4096))>0)write(cs,b,n);
  close(f); close(cs);
  printf("Transfer Completed\n");  // <-- print after each transfer
 }
}

#include<stdio.h>
main()
{
 char b[20];
 int fd,xr;
 if((fd=open("balaji",0))==-1)
 {
  printf("Cannot open file\n");
  exit(1);
 }
 do
 {
   xr=read(fd,b,20);
   b[xr]='\0';
   printf("%s",b);
 }
while(xr==20);
 close(fd);
}

#include<stdio.h>
main(int ac,char *av[])
 {
  int fd;
  int i=1,j=0;
  char *sep="";
  printf("%s",av[1]);
  if(ac<1)
  {
   printf("\n INSUFFICIENT ARGUMENTS");
   exit(1);
  }
  if((fd=open("balaji",0660))==-1)
  {
   printf("\n cannot create the file");
   exit(1);
  }
  while(i<ac)
  {
 j=write(fd,av[i],(unsigned)strlen(av[i]));
  printf("%d",j);
   write(fd,sep,(unsigned)strlen(sep));
   i++;
   }
   close(fd);
}

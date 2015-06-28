#include<stdio.h>
int main()
{
  int fd;
  if((fd=open("file.dat"))==-1)
  {
   perror("cannot open the file.dat");
   exit(0);
  }
  else
  printf("\nFILE OPENED SUCCESSFULLY");
  return 0;
}

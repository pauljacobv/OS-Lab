#include<stdio.h>
#include<dirent.h>
struct dirent *dptr;
void main(int argc, char *argv[])
{
  char buff[100];
  DIR *dirp;
  printf("\n\nEnter Directory Name: ");
  scanf("%s",buff);
  if((dirp=opendir(buff))==NULL)
  {
   printf("\n The given directory does not exist\n");
   exit(1);
  }
  while(dptr=readdir(dirp))
  {
    printf("%s\n",dptr->d_name);
  }
  closedir(dirp);
} 

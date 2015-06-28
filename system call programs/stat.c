#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
 int s;
 struct stat st;
  s=stat("sss.c",&st);
  if(s<0)
  {
   printf("use of stat() is unsuccessful\n");
  exit(0);  
   }
   printf("\ninode number of sss.c file is %d",st.st_ino);
   printf("\nnumber of links to sss.c is %d",st.st_nlink);
   printf("\nfile permissions of sss.c file is %d",st.st_mode);
   printf("\nsize of sss.c file is %d",st.st_size);
   printf("\nlast access time of sss.c file is %d\n",st.st_atime);
}

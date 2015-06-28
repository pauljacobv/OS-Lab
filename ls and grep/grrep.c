#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main()

{

char fn[10],pat[10],temp[200];

FILE *fp;

printf("\n Enter file name : ");

scanf("%s",fn);

printf("Enter the pattern to be searched : ");

scanf("%s",pat);

fp=fopen(fn,"r");

while(!feof(fp))

{

fgets(temp,1000,fp);

if(strstr(temp,pat))

printf("%s",temp);

}

fclose(fp);

}

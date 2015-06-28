#include<stdio.h>
#include<stdlib.h>
int i,j,n,x,ch,size,ch1,ch2,y,pid;
struct alloc1
{ 
  int id,sa,ea,size;
  struct alloc1 *next;
}*start=NULL,*ptr=NULL,*newn=NULL;

struct free1
{
  int stadd,eadd,size1;
  struct free1 *next;
}*start1=NULL,*newn1=NULL,*ptr2=NULL,*preptr2=NULL;

void displayfree(struct free1 *temp)
{
	printf("\n\nFree Space\n");
	temp=start1;
while(temp!=NULL)
    {
    printf("%d",temp->stadd);
    printf(" - %d\n",temp->eadd);
    temp=temp->next;
    }
}

void display(struct alloc1 *temp1)
{
	printf("\n\nAllocated\n");
	temp1=start;
while(temp1!=NULL)
    {
    printf("%d",temp1->sa);
    printf(" - %d\n",temp1->ea);
    temp1=temp1->next;
    }
}

void init()
{
	newn->sa=ptr2->stadd;
				   newn->ea=newn->sa+size-1;
				   ptr2->stadd=ptr2->stadd+size;
				   ptr2->size1=ptr2->size1-size;
}

void main()
{
  
  printf("\nEnter the number of processes:\n");
  scanf("%d",&n);
 
  

  for(i=0;i<n;i++)
  {
         newn=(struct alloc1 *) malloc(sizeof(struct alloc1));
	printf("\nEnter process id: ");
        scanf("%d",&newn->id);
         printf("\nEnter the start address: ");
         scanf("%d",&newn->sa);
	printf("\nEnter the end address: ");
   	scanf("%d",&newn->ea);
	newn->size=(newn->ea-newn->sa)+1;
        if(start==NULL)
  {
    start=newn;
    start->next=NULL;
  ptr=start;
   }
   else
   {
     while(ptr->next!=NULL)
     {
       ptr=ptr->next;
     }
     ptr->next=newn;
     ptr=ptr->next;
     ptr->next=NULL;
  }
}
 
 printf("\nEnter the details of free space\n");
 do
 {
    newn1=(struct free1 *) malloc(sizeof(struct free1));
   printf("\nEnter the starting address: ");
   scanf("%d",&newn1->stadd);
   printf("\nEnter the ending address: ");
   scanf("%d",&newn1->eadd);
   newn1->size1=(newn1->eadd-newn1->stadd)+1;
    if(start1==NULL)
  {
    start1=newn1;
    start1->next=NULL;
  ptr2=start1;
   }
   else
   {
     while(ptr2->next!=NULL)
     {
       ptr2=ptr2->next;
     }
     ptr2->next=newn1;
     ptr2=ptr2->next;
     ptr2->next=NULL;
  }
  ptr2=start1;
  printf("\nPress 1 to add more...");
  scanf("%d",&ch);
 }while(ch==1);

displayfree(ptr2);
 ptr=start;
display(ptr);
do
{
  printf("\nEnter the size of new process: ");
  scanf("%d",&size);
  printf("\nEnter the process id:");
  scanf("%d",&pid);

			   newn=((struct alloc1 *)malloc(sizeof(struct alloc1)));
			   newn->next=NULL;   
			   newn->size=size;
               newn->id=pid;
     printf("\nMENU:\n1.First fit\n2.Best fit\n3.Worst fit\n4.Exit\n");
     printf("\nEnter your choice:\n");
     scanf("%d",&ch1);
     switch(ch1)
     {
       case 1: 

		    
			   ptr2=start1;
			   if(ptr2->size1==size)
			   {
				   start1=ptr2->next;
			   }
			   else
			   {
				   while(ptr2->size1<size)
				   {
					   preptr2=ptr2;
					   ptr2=ptr2->next;
					   if(ptr->size==size)
					   {
						   preptr2->next=ptr2->next;
					   }
				   }
			   }
			   init();
			   ptr=start;
			   while(ptr->next!=NULL)
			   {
				   ptr=ptr->next;
			   }
			   ptr->next=newn;
			   display(ptr);
			   displayfree(ptr2);
	           break;



	case 2:
			   ptr2=start1;
			   x=1000;
			   while(ptr2!=NULL)
			   {
				   if((ptr2->size1>=size)&&(ptr2->size1<=x))
				   {
					   x=ptr2->size1;
				   }
					   ptr2=ptr2->next;
				  }
				   ptr2=start1;
				   while(ptr2->size1!=x)
				   {
					   preptr2=ptr2;
					   ptr2=ptr2->next;
				   }
				init();
				if(ptr2->stadd==ptr2->eadd)
				   {
					   preptr2->next=ptr2->next;
				   }
				   ptr=start;
				   while(ptr->next!=NULL)
				   {
					   ptr=ptr->next;
				   }
				   ptr->next=newn;
				   display(ptr);
				   displayfree(ptr2);

			break;
case 3:	   
	   ptr2=start1;
		       y=0;
			   while(ptr2!=NULL)
			   {
				   if((ptr2->size1>=size)&&(ptr2->size1>=y))
				   {
					   y=ptr2->size1;
				   }
					   ptr2=ptr2->next;
				  }
				   ptr2=start1;
				   while(ptr2->size1!=y)
				   {
					   preptr2=ptr2;
					   ptr2=ptr2->next;
				   }
				   
				   if(ptr2->stadd==ptr2->eadd)
				   {
					   preptr2->next=ptr2->next;
				   }
				   init();
				   ptr=start;
				   while(ptr->next!=NULL)
				   {
					   ptr=ptr->next;
				   }
				   ptr->next=newn;
				   display(ptr);
				   displayfree(ptr2);
				   break;
case 4:break;
default:break;
	}

printf("\npress 1 to add more..");
scanf("%d",&ch2);
}while(ch1==1);
}

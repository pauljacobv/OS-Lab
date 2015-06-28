#include<stdio.h>

struct process
{
	char p[10];
	int at,bt,pr,wt,tt,r,ar;
}a[100],temp;
int n,j;

void sorta()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j].at>a[j+1].at)
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}

void sortp()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j].pr>a[j+1].pr)
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}

void sortar()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((a[j].ar>a[j+1].ar)||(a[j].ar==a[j+1].ar&&a[j].ar!=a[j].at))
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}

void main()
{ 
	int i,c,t=0,f1=1,f=0,tq=0,cf,nt=0;
	float aw=0,at=0;
    printf("Enter the no of Process\t");
    scanf("%d",&n);
	printf("Enter the process details");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the Process ID:");
		scanf("%s",&a[i].p);
		printf("\nEnter the Priority:");
		scanf("%d",&a[i].pr);
		printf("Enter the Arrival Time:");
		scanf("%d",&a[i].at);
		printf("\nEnter the Burst Time:"); 		
		scanf("%d",&a[i].bt);

		a[i].wt=a[i].tt=0;
		a[i].r=a[i].bt;
		a[i].ar=a[i].at;
	}
	printf("\nMENU:\n1.Priority\n2.Round Robin\n");
	printf("\nEnter your choice:");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			   sorta();
			   sortp();
			   printf("\nGantt Chart for priority\n");
			   printf("%d",t);
			   while(f1==1)
			   {
				   f1=0;
				   for(i=0;i<n;i++)
				   {
					   if(a[i].at<=t&&a[i].r!=0)
					   {
						   a[i].wt=t-a[i].at;
						   aw+=a[i].wt;
						   printf("%s",a[i].p);
						   t=t+a[i].bt;
						   for(j=0;j<t;j++)
						   printf("=");
						   a[i].tt=t-a[i].at;
						   at+=a[i].tt;
						   a[i].r=0;
						   f=0;
						   f1=1;
						   break;
					   }
					   else if(f==0&&a[i].r!=0)
					   {
						   nt=a[i].at;
						   f=f1=1;
					   }
					   else if(nt>a[i].at&&a[i].r!=0)
					   
						   nt=a[i].at;
				   }
				   if(f==1)
				   {
					   t=nt;
					   for(j=0;j<t;j++)
					   printf("=");
					   f=0;
				   }
			   }

			   printf("\nAverage waiting time=%f",(aw/n));
			   printf("\nAverage turn around time=%f\n",(at/n));
			   break;
		case 2:
			printf("\nEnter the time quantum:");
			scanf("%d",&tq);
			if(tq>0)
			{
				sorta();
				printf("\nGantt Chart for Round Robin\n");
				printf("%d",t);
				while(f1==1)
				{
					cf=0;
					f1=0;
					sortar();
				    for(i=0;i<n;i++)
				    {
						if(a[i].at<=f&&a[i].r!=0)
					    {
							a[i].wt+=t-a[i].tt;
							printf("%s",a[i].p);
							if(a[i].r<tq)
							{
								t=t+a[i].r;
								a[i].r=0;
							}
							else
							{
								t=t+tq;
								a[i].r-=tq;
							}
							for(j=0;j<t;j++)
							printf("=");
							a[i].tt=a[i].ar=t;
							if(cf==0)
							{
								cf=1;
								f=t;
							}
						}
						if(a[i].r!=0&&f1==0)
						f1=1;
						if(a[i].at>f)
							break;
					}
					if(cf==0&&f1==1)
					{
						t=f=a[i].at;
						for(j=0;j<t;j++)
						printf("=");
					}
				}
				for(i=0;i<n;i++)
				{
					a[i].wt=a[i].wt-a[i].at;
					a[i].tt=a[i].tt-a[i].at;
					aw+=a[i].wt;
					at+=a[i].tt;
				}


				printf("\nAverage waiting time=%f",(aw/n));
			   printf("\nAverage turn around time=%f\n",(at/n));
			}
			else
				printf("\nTime quantum is wrong");
			break;
		default:
			printf("\nWrong Choice\n");
			break;
			}
			}


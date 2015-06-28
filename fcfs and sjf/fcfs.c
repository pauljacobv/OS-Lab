/* non premptive sjf fcfs too */


#include<stdio.h>
#include<string.h>

struct process
{
int arr,bur,wait,turn;
char pid[5];
}p[100],temp,to[100];
int n;

void sort( )
{
int i,j;
            for(i=0;i<n-1;i++)
            {
            for(j=i+1;j<n;j++)
                {
                if(p[i].arr>p[j].arr)
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
                }
            }

}

avg()
    {
    float i,avgw=0,avgt=0;
    for(i=0;i<n;i++)
    {
        avgw=avgw+p[i].wait;
        avgt=avgt+p[i].turn;
    }
    avgw=avgw/n;
    avgt=avgt/n;

printf("\nAverage waiting time: %d\nAverage turnaround time: %d\n",avgw,avgt);
    }


    void disp()
	{    int i;
	    printf("\npid\tburst\tarrival\twait\tturnaround\n");

	 for(i=0;i<n;i++)
            {
            printf("%s\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].bur,p[i].arr,p[i].wait,p[i].turn);
        }
    avg();
    chart();

        }
chart()
{int i;
printf("\n");

    for(i=0;i<n;i++)
    {
        printf("     %s",p[i].pid);

    }
printf("\n0");
for(i=0;i<n;i++)
{
printf("-------");
printf("%d",p[i].turn);
}
printf("\n");

}



    void fcfs()
        {
        int i;
        p[0].wait=0;
        p[0].turn=p[0].wait+p[0].bur;
        for(i=1;i<n;i++)
            {
            p[i].wait=p[i-1].wait+p[i-1].bur;
            p[i].turn=p[i].wait+p[i].bur;
            }
        disp();
        }


    sjf()
    {

            int i,j;
            sort();
            for(i=0;i<n;i++)
            {
              to[i] = p[i];
            }
            for(i=1;i<n-1;i++)
            {
            for(j=i+1;j<n;j++)
                {
                if(p[i].bur>p[j].bur)
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
                }
            }
            p[0].wait=0;
            p[0].turn=p[0].wait+p[0].bur;
                for(i=1;i<n;i++)
                        {
                        p[i].wait=p[i-1].wait+p[i-1].bur;
                        p[i].turn=p[i].wait+p[i].bur;
                        }
                disp();
        }





int main()
{
    int j,i,h;
    printf("Enter Number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
          printf("PID of process %d: ",i+1);
        scanf("%s",p[i].pid);
        printf("Arrival time of process%d: ",i+1);
        scanf("%d",&p[i].arr);
        printf("Burst time of process %d: ",i+1);
        scanf("%d",&p[i].bur);
        printf("\n");
        }
do
{
    printf("MENU:\n\n1.FCFS\n2.SJF\nEnter your choice: ");
    scanf("%d",&j);
    switch(j)
    {
    case 1:sort();
           fcfs();
              break;
    case 2:   sort();
              sjf();
              break;

    default : printf("invalid");
    }
printf("\n Press (1) to continue : ");
scanf("%d",&h);
}while(h==1);
}




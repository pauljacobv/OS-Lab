#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define N 5
#define right i%N
#define left (N+i-1)%N

sem_t s[5];

void think(int i)
{
	printf("\n\n%d is thinking\n",i);
	sleep(1);
}

void eat(int i)
{
	printf("\n\n%d is eating\n",i);
	sleep(1);
}

void *philo(int i)
{
	do
	{
		think(i);
		sem_wait(&s[left]);
		printf("\n\n%d picked up chopstick %d\n",i,left);
		sem_wait(&s[right]);
		printf("\n\n%d picked up chopstick %d\n",i,right);
		eat(i);
		sem_post(&s[left]);
		printf("\n\n%d kept down chopstick %d\n",i,left);
		sem_post(&s[right]);
		printf("\n\n%d kept down chopstick %d\n",i,right);
	}while(1);
}

void main()
{
int i;
pthread_t p[5];
		for(i=0;i<N;i++)
		{
			sem_init(&s[i],0,1);
		}
		for(i=0;i<N;i++)
		{
			pthread_create(&p[i],0,(void *)philo,(void *)i);
		}
	while(1);
}

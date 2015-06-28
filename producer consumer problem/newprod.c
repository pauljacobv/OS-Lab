#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define BUFFERSIZE 5
pthread_t producerThread, consumerThread;
int counter = -1;
sem_t mutex, empty, full; 
int buffer[BUFFERSIZE];
void produce()
{
	while(1)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		counter = counter + 1;
		buffer[counter] = rand() % 100;
		printf("\n\nProduced item %d\n", buffer[counter]);
                sleep(1);
		sem_post(&mutex);
		sem_post(&full);
		usleep(((rand() % 10)) * 1000);
	}
}
void consume()
{
	while(1)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		printf("\n\nConsumed item %d\n", buffer[counter]);
                sleep(1);
		counter = counter - 1;
		sem_post(&mutex);
		sem_post(&empty);
		usleep(((rand() % 10)) * 1000);
	}
}
int main()
{
	int i=0;
	sem_init(&mutex, 0, 1);
	sem_init(&empty, 0, BUFFERSIZE);
	sem_init(&full, 0, 0);
	pthread_create(&producerThread, NULL, (void *) &produce,(void *)i);
	usleep(((rand() % 10)) * 10000);
	pthread_create(&consumerThread, NULL, (void *) &consume,(void *)i);
	
	while(1) sleep(1);
}

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

void * function1(void * val);
void * function2(void * val);

volatile int X;
volatile int Y;

sem_t s1;
sem_t s2;

void main(int argc, char const *argv[])
{
	
	void * status;

	pthread_t thread1;
	pthread_t thread2;
	srand(time(NULL));

	sem_init(&s1,0,0);
	sem_init(&s2,0,0);

	pthread_create(&thread1,NULL,function1,NULL);
	pthread_create(&thread2,NULL,function2,NULL);

	pthread_join(thread1,&status);
	pthread_join(thread2,&status);

	sem_destroy(&s1);
	sem_destroy(&s2);

}

void * function1 (void * val){
	while(1){
		sem_post(&s1);
		sem_wait(&s2);
		X = rand() % 1000;
		printf("\nAfter thread ID A writes to X, X = %d\n", X);
		printf("\nAfter thread ID A reads from Y, Y = %d\n", Y);
		sleep(3);
	}
}

void *function2 (void * val){
	while(1){
		sem_wait(&s1);
		sem_post(&s2);
		Y = rand() % 1000;
		printf("\nAfter thread ID  B reads from X, X = %d\n", X);
		printf("\nAfter thread ID B writes to Y, Y = %d\n", Y);
		
		sleep(3);
	}
}
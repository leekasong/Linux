#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_increment(void *arg);
char thread1[] = "A Thread";
char thread2[] = "B Thread";

pthread_mutex_t mutex;
int num = 0;

void main(){

	pthread_t t1, t2;
	int state;
	printf("before init : %d\n", mutex.__data.__lock);
	state = pthread_mutex_init(&mutex, NULL);
	printf("after init : %d\n", mutex.__data.__lock);

	if(state){
		perror("pthread_mutex_init()");
		return;
	}
	
	pthread_create(&t1, NULL, thread_increment, thread1);
	pthread_create(&t2, NULL, thread_increment, thread2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("final num : %d\n", num);
	pthread_mutex_destroy(&mutex);


}

void *thread_increment(void *arg){
	int i;
	pthread_mutex_lock(&mutex);
	printf("after mutex lock : %d\n", mutex.__data.__lock);
	for(i = 0; i < 5; i++){
		num++;	
		printf("thread %s, num : %d\n", arg, num);
	}
	pthread_mutex_unlock(&mutex);
	printf("after mutex unlock : %d\n", mutex.__data.__lock);
}

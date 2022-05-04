#include <stdio.h>
#include <pthread.h>

void *increment(void *arg);
int count = 0, size = 0, line = 0, collum = 0;
int *a;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void) 
{
  //create the matrix
  scanf("%d", &size);
  int m[size][size];
    
  //get elements of matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  //make threads
	pthread_t threads[size];
	for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++){
      a = m[i][j];
    }
		if (pthread_create(&(threads[i]), NULL, increment, NULL) != 0){
			printf("Error creating thread number %d", i); //could not create
		}
	}

	for (int i = 0; i < size; i++){
		pthread_join(threads[i], NULL);
	}

	printf("\nSum = %d\n", count);
}

void *increment(void *arg) 
{

  pthread_mutex_lock(&mutex);
  count = count + a;
  pthread_mutex_unlock(&mutex);
  
  return arg;
}
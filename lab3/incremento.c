#include <stdio.h>
#include <pthread.h>

#define NUM_INCREMENT 10000

void *increment(void *counter_p) {
  int* c = (int*) counter_p;
  for (int i = 0; i < NUM_INCREMENT; i++)
    *c += 1;
}

int main() {

  const int NUMTHREADS = 10;
  pthread_t threads[NUMTHREADS];
  int counter = 0;
  
  for (long int i = 0; i < NUMTHREADS; i++) {
    pthread_create(&threads[i], NULL, increment, &counter);
  }
  
  for (int i = 0; i < NUMTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("%d\n", counter);

  return 0;
}
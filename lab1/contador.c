#include <stdio.h>
#include <pthread.h>

void *tarefa(void *id) {
  int tid = (int ) id;
  for (int i = 0; i < 5; i++) {
    printf("Sou a thread %d e estou no número %d\n", tid, i);
  }
}
int main() {
  const int NUMTHREADS = 10;
  pthread_t threads[NUMTHREADS];
  
  for (int i = 0; i < NUMTHREADS; i++) {
    pthread_create(&threads[i], NULL, tarefa, (void *) i);
  }
  
  for (int i = 0; i < NUMTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
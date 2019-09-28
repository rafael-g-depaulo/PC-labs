#define _GNU_SOURCE  

#include <stdio.h>
#include <pthread.h>
#include <sched.h>
 

void *tarefa(void *id) {
  int tid = *(int *) id;
  for (int i = 0; i < 5; i++) {
    printf("Sou a thread %d e estou no número %d\n", tid, i);
  }
}

int main() {
  const int NUMTHREADS = 10;
  pthread_t threads[NUMTHREADS];
  
  // código para utilizar somente um núcleo
  cpu_set_t mascaranucleos;             // Bitmask para os núcleos
  CPU_ZERO(&mascaranucleos);            // Remove a seleçãao de todos os núcleos
  CPU_SET(0, &mascaranucleos);          // Marca somente um núcleo 0 para uso
  sched_setaffinity(0, sizeof(cpu_set_t), &mascaranucleos);

  for (int i = 0; i < NUMTHREADS; i++) {
    pthread_create(&threads[i], NULL, tarefa, (void *) &i);
  }
  
  for (int i = 0; i < NUMTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
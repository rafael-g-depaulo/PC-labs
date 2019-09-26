#include <stdio.h>
#include <pthread.h>
#include <sched.h>

#define _GNU_SOURCE 

int largada = 3;

void *carro(void *id) {
  int tid = (long int) id;
  while (largada > 0) { sleep(1); }
  printf("Sou a o carro %d e terminei a corrida!\n", tid);
}

void *juizdelargada(void * nada) {
  while (largada > 0) {
    // fazer a parte do random aqui
    sleep(1);
    largada--;
  }
  printf("GO!!\n");
}

int main() {
  const int NUMCARTHREADS = 10;
  pthread_t threads[NUMCARTHREADS];
  pthread_t juiz_thread;
  for (long int i = 0; i < NUMCARTHREADS; i++) {
    pthread_create(&threads[i], NULL, carro, (void *) i);
  }
  pthread_create(&juiz_thread, NULL, juizdelargada, NULL);
  
  for (int i = 0; i < NUMCARTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  pthread_join(juiz_thread, NULL);

  return 0;
}
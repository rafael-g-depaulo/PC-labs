#include <stdio.h>
#include <pthread.h>

void *rotina() {
  printf("Ola, sou uma thread\n");
}

int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, rotina, NULL);
  pthread_create(&t2, NULL, rotina, NULL);
  
  printf("Ola, sou a main.\n");

  return 0;
}
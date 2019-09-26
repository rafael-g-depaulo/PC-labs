#include <stdio.h>
#include <pthread.h>

#define DEPOSITA 0
#define RETIRA 1

int turno = DEPOSITA;

void *deposita(void *conta_p) {
  int* c = (int*) conta_p;

  while (1) {
    while (turno != DEPOSITA) {}
    *c += 20;
    printf("foi adicionado 20 à conta. saldo atual: %d\n", *c);
    turno = RETIRA;
  }
}

void *retira(void *conta_p) {
  int* c = (int*) conta_p;

  while (1) {
    while (turno != RETIRA) {}
    *c -= 10;
    printf("foi retirado 10 da conta. saldo atual: %d\n", *c);
    turno = DEPOSITA;
  }
}

int main() {

  pthread_t t1, t2;

  int conta = 0;
  
  pthread_create(&t1, NULL, deposita, &conta);
  pthread_create(&t2, NULL, retira, &conta);
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}
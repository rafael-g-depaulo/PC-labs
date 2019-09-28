#include <stdio.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

int quer[] = { FALSE, FALSE, FALSE };

void *count_down(void *counter_p) {
  int * counter = (int*) counter_p;

  while (*counter > 0) {
    quer[0] = TRUE;
    while (quer[1] || quer[2]) {

    }
  }

}

int main() {

  pthread_t t1, t2, t3;
  int x = 5, y = 10, z = 15;
  
  pthread_create(&t1, NULL, count_down, &x);
  pthread_create(&t2, NULL, count_down, &y);
  pthread_create(&t3, NULL, count_down, &z);
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);


  return 0;
}

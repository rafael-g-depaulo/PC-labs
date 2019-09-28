#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

void *x2times10(void * content) {
  double *x = malloc(sizeof(double));
  *x = *(double*) content;
  *x = pow(*x, 2) * 10;
  pthread_exit(x);
}

void *x3times42(void * content) {
  double *x = malloc(sizeof(double));
  *x = *(double*) content;
  *x = pow(*x, 3) * 10;
  pthread_exit(x);
}

double f(double x) {
  pthread_t t1, t2;
  void *r1, *r2;
  
  pthread_create(&t1, NULL, x2times10, (double*) &x);
  pthread_create(&t2, NULL, x3times42, (double*) &x);
  pthread_join(t1, &r1);
  pthread_join(t2, &r2);

  return *(double*)r1 + *(double*)r2;
}

int main() {

  double x = 10;

  printf("%.4f\n", f(x));

  return 0;
}
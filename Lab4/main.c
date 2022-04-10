#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "interp.h"
#include "vetor.h"

#define N 6

int main (void){
  
  double a = 0.0;
  double b = 12.0;

  double* xi = vet_cria (N);
  int i;

  for(i = 0; i < N; i++){
    xi[i] = 0.0;
  }

  regular (N, a, b, xi);

  printf("\n**Vetor xi preenchido**\n");
  for(i = 0; i < N; i++){
    printf("xi[%d] = %lf\n", i, xi[i]);
  }

  vet_libera(xi);

  return 0;
}
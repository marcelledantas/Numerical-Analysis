#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "interp.h"
#include "vetor.h"

#define N 6


double f (double x){

  double raiz = x * x * x + x  - 7; //mudar
  return raiz;
}


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


  double* bi = vet_cria (N);

  coeficientes (N, xi, f, bi);

  vet_libera(xi);
  vet_libera(bi);

  return 0;
}
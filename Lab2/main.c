#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "raiz.h"

double f (double x){

  double raiz = x * x * x + x  - 7;
  return raiz;
}



int main (void){
    
  double *r = (double*)malloc(sizeof(double));
  double *s = (double*)malloc(sizeof(double));

  if (r == NULL || s == NULL){
    printf("\nFalha ao locar raíz(es) na memória\n");
  }

  double a = 1, b = 1.739204, x0 = 1.5, x1 = 0.5;
  int resultadoSecante, resultadoBissecao; 

  printf("\n ***Método Bisseção***\n");
  resultadoBissecao = bissecao (a, b, f, r);
  printf("O número de iterações método bisseção igual a %d\n", resultadoBissecao);
  if(*r != 0.0){
    printf("A raiz da função pelo método da bissecao é %lf\n", *r);
  }

  printf("\n ***Método Secante***");
  resultadoSecante = secante (x0, x1, f, s);
  printf("O número de iterações método secante igual a %d\n", resultadoSecante);
  if(*s != 0.0){
    printf("A raiz da função pelo método da secante é %lf\n", *s);
  }

  return 0;
}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "simpson.h"

double f (double x){

  double raiz = x * x + x  - 7;
  return raiz;
}


int main (void){

  double a, b, tol;

  tol = 1E-10;
  a = 10;
  b = 20;

  printf("\nResultado pelo método Adaptiva Simpson: %lf\n", adaptsimpson (a, b, f, tol) );
  
  double sigma = 1;
  printf("\nProbabilidade pelo método Adaptiva Simpson: %.8lf\n", probabilidade (sigma) );
  
  return 0;
}
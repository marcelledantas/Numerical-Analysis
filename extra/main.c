#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "extra.h"

#define N 8

double f (double x){

  double func = x * x - 20;
  return func;
}


double g (double x){

  double func = x * x * x + x - 7;
  return func;
}

int main (void){

  // *****Método Interpolação quadrática inversa (IQI)******

  int retornoIQI_Iter;
  double x0, x1, x2, *r;

  r = (double *)malloc(sizeof(double));

  x0 = 1.6;
  x1 = 1.5;
  x2 = 1.4;

  retornoIQI_Iter = IQI (x0, x1, x2, g, r);
  printf("**\nMétodo Interpolação quadrática inversa (IQI)**\n");
  printf("Número de iterações usado na determinação da raíz: %d\n", retornoIQI_Iter);
  printf("Raíz encontrada: %lf\n", *r);


  // *****Método Mínimos Quadrados******

  double t[N] = {1, 2, 3, 4, 5, 6, 7, 8};
  double c[N] = {8.0, 12.3, 15.5, 16.8, 17.1, 15.8, 15.2, 14.0};
  double *a, *b;


  a = (double *)malloc(sizeof(double));
  b = (double *)malloc(sizeof(double));

  ajuste(N, t, c, a, b);
  printf("\nCoeficientes a = %lf | b = %lf\n", *a, *b);
  
  free(r);
  free(a); 
  free(b);

  return 0;
}

// ajuste (int n, double* t, double* c, double* a, double* b)
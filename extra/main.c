#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "extra.h"

double f (double x){

  double func = x * x - 20;
  return func;
}


double g (double x){

  double func = x * x * x + x - 7;
  return func;
}

int main (void){

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

  free(r);
  return 0;
}
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX_ITER 50

#include "extra.h"

int IQI (double x0, double x1, double x2, double (*f) (double x), double *r){

  double fx0, fx1, fx2, L0, L1, L2, somaL, tol;
  int iter;
  tol = 0.5e-8;
  iter = 0;
  // printf("\ncheguei na função %d\n", fabs(f(x0)) < tol);
  while(fabs(x0 - x1) > tol){
    
      fx0 = f(x0);
      fx1 = f(x1);
      fx2 = f(x2);

      L0 = (x0 * fx1 * fx2) / ((fx0 - fx1) * (fx0 - fx2));
      L1 = (x1 * fx0 * fx2) / ((fx1 - fx0) * (fx1 - fx2));
      L2 = (x2 * fx1 * fx0) / ((fx2 - fx0) * (fx2 - fx1));
      
      somaL = L0 + L1 + L2;
      x0 = somaL;
      x1 = x0;
      x2 = x1;
      iter += 1;
    
    if(iter >= MAX_ITER){
      return -1;
    }
  }

  *r = x0;
  return iter;

}

// void ajuste (int n, double* t, double* c, double* a, double* b){

// }
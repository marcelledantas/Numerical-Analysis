#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "massamola.h"
#include "vetor.h"

int main (void){

  double t, x, y;
  double *fx = (double *)malloc(sizeof(double));
  double *fy = (double *)malloc(sizeof(double));

  x = 2.0, y = 3.0, t = 1.0;

  forca (t, x, y, fx, fy);

  printf("\nForça total em Y: %lf\n", *fy);
  printf("\nForça total em X: %lf\n", *fx);


  int i;
  double x0, y0, n, h, t_final, *x_, *y_;
  x0 = 200.0, y = 0.0, h = 0.1, t_final = 100, n = 50.0;

  x_ = (double *)malloc(n * sizeof(double));
  y_ = (double *)malloc(n * sizeof(double));

  simula (x0, y0, t_final, n, x_, y_);

  for(i = 0; i < n; i++){
    printf("\nVetor x[%d] = %lf \n", i, x_[i]);
    printf("\nVetor y[%d] = %lf \n", i, y_[i]);
}
  
  return 0;
}
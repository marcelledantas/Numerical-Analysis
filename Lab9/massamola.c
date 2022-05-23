#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "massamola.h"
#include "vetor.h"

void forca (double t, double x, double y, double* fx, double* fy){
  
  double forcaTotalX, forcaTotalY;
  double k, gx, gy, m, r, wx, wy;

  k = 0.3, m = 2.0, gx = 0.0, gy = 9.8, r = 200, wx = 10.0, wy = 0.0;

  
  forcaTotalX = (m * gx) + (wx * exp(-t/20)) + (-k * (fabs(x) - r) * x/fabs(x));

  forcaTotalY = (m * gy) + (wy * exp(-t/20)) + (-k * (fabs(y) - r) * y/fabs(y));;

  *fy = forcaTotalY;
  *fx = forcaTotalX;
}


double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn ){

  double delta, *fx, *fy;
  delta = 0.002;

  double *fx = (double *)malloc(sizeof(double));
  double *fy = (double *)malloc(sizeof(double));

  forca(t, x, y, fx, fy);

  *xn = x + (1 - delta) * (x - xp) + h*h * (*fx)/m;
  *yn = y + (1 - delta) * (y - yp) + h*h * (*fy)/m;
  
  return (t + h);
}

void simula (double x0, double y0, double t_final, int n, double* x, double* y){


}
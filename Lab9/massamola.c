#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "massamola.h"
#include "vetor.h"

void forca (double t, double x, double y, double* fx, double* fy){
  
  double forcaTotalX, forcaTotalY;
  double k, gx, gy, m, r, wx, wy, xNorma;

  k = 0.3, m = 2.0, gx = 0.0, gy = 9.8, r = 200, wx = 10.0, wy = 0.0;
  xNorma = sqrt(x*x + y*y);
  
  forcaTotalX = (m * gx) + (wx * exp(-t/20)) + (-k * (xNorma - r) * x/xNorma);

  forcaTotalY = (m * gy) + (wy * exp(-t/20)) + (-k * (xNorma - r) * y/xNorma);

  *fy = forcaTotalY;
  *fx = forcaTotalX;
}


double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn ){

  double delta, *fx, *fy, m;
  delta = 0.002, m = 2.0;

  fx = (double *)malloc(sizeof(double));
  fy = (double *)malloc(sizeof(double));

  forca(t, x, y, fx, fy);

  *xn = x + (1 - delta) * (x - xp) + h*h * (*fx)/m;
  *yn = y + (1 - delta) * (y - yp) + h*h * (*fy)/m;
  
  return (t + h);
}

void simula (double x0, double y0, double t_final, int n, double* x, double* y){

  double h;
  double tempoCorrente, iter, tH, Xatual = x0, Xantes = x0, Yatual = y0, Yantes = y0;
  int i = 1.0;
  double *ex, *ey;

  iter = 1.0;

  ex = (double *)malloc(sizeof(double));
  ey = (double *)malloc(sizeof(double));

  x[0] = x0;
  y[0] = y0;

  while(iter <= n){
    

    h = t_final/n;
    tempoCorrente = (iter * h);
    
    
    tH = evolui(tempoCorrente, h, Xatual, Yatual, Xantes, Yantes, ex, ey);
    
    //Estado t + h
    x[i] = *ex;
    y[i] = *ey;

    //Estado atual
    Xatual = x[i];
    Yatual = y[i];

    //Estado anterior
    Xantes = x[i - 1];
    Yantes = y[i - 1];
    
    i++;
    iter++;
  }
  
}
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "ode.h"

double f (double t, double y){

  double derivadaY = t*y + t*t*t;
  return derivadaY;
}


int main(void){

  double h = 0.001;
  double tol = 1E-12;

  double t0, t1, y0;

  t0 = 0.0;
  t1 = 2.4;
  y0 = -1.0;

  double resultadoRungeKutta = RungeKutta (t0, t1, h, y0, f);
  printf("\nMétodo RungeKutta y(%.1lf) = %lf\n", t1, resultadoRungeKutta);

  double RungeKuttaAdapt (t0, t1, y0, f, tol);
  printf("\nMétodo RungeKuttaAdapt y(%.1lf) = %lf\n", RungeKuttaAdapt);

  return 0;
}
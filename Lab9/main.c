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

  return 0;
}
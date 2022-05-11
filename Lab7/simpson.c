#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.141593

double adaptsimpson (double a, double b, double (*f) (double x), double tol){

  double m = (a + b)/2;
  double deltaAB =  ((b - a)/6) * (f(a) + 4*f(m) + f(b));  
  double deltaAM =  ((m - a)/6) * (f(a) + 4*f((a+m)/2) + f(m));
  double deltaMB =  ((b - m)/6) * (f(m) + 4*f((m+b)/2) + f(b));

  double delta = deltaAB - deltaAM - deltaMB;

  if(fabs(delta) > 15 * tol){
    return adaptsimpson(a, m, f, tol/2) + adaptsimpson(m, b, f, tol/2);
  }
  else{
    return (deltaAM + deltaMB - delta/15);
  }

}

double g (double x){

  return exp(-x*x/2);
}


double probabilidade (double sigma){

  double tol = 1E-8;

  double resulAdapSimp = adaptsimpson (-sigma, sigma, g, tol);

  return (1/sqrt(2*PI)) * resulAdapSimp;

}
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


void regular (int n, double a, double b, double* xi){
  
  int i;
  double incr = b / n;
  double sum = 0.0;

  for(i = a; i < n; i++){
    
    if(i > a){
      sum += incr;
      xi[i] = sum;
    } else{
      xi[i] = i;
    }
  }
}

void chebyshev (int n, double a, double b, double* xi){

}

// void coeficientes (int n, double* xi, double (*f) (double), double* bi){

// }

// double avalia (int n, double* xi, double* bi, double x){

// } 

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX_ITER 50

#include "extra.h"
#include "mmq.h"
#include "vetor.h"
#include "matriz.h"

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

//   double sumt = 0.0;     
//   double sumt2 = 0.0;   
//   double sumtc = 0.0;                     
//   double sumc = 0.0;                     
//   double sumc2 = 0.0; 
//   int i;                    

//   for (int i=0;i<n;i++){ 
//     sumt  += t[i];       
//     sumt2 += sqrt(t[i]);  
//     sumtc += t[i] * c[i];
//     sumc  += c[i];      
//     sumc2 += sqrt(c[i]); 
//   } 

//   double denom = (n * sumt2 - sqrt(sumt));

//   *b = (n * sumtc  -  sumt * sumc) / denom;
//   *a = (sumc * sumt2  -  sumt * sumtc) / denom;
  
// }

void ajuste (int n, double* t, double* c, double* a, double* b){

  int i, j, m;
  m = 2;
  
  double *lnT = vet_cria(n);
  double *lnC = vet_cria(n);
  double *lnCT = vet_cria(n);
  double *k = vet_cria(n);
  double **A = mat_cria(n, m);
  double *x = vet_cria(m);


  for (i = 0; i < n; i++){
    lnT[i] = log( t[i] );
    lnC[i] = log( c[i] );
    lnCT[i] = lnC[i] - lnT[i];
    //printf("\nlnCT[%d] = %lf\n", i, lnCT[i]);
    k[i] = 1.0;
  }

  for (j = 0; j < n; j++){
    for (i = 0; i < m; i++){

      A[j][i] = k[j];
      i++;
      A[j][i] = t[j];
    }
  }

  double returnMmq = mmq (n, m, A, lnCT, x);
  // printf("\nreturnMmq = %lf\n", returnMmq);

  // for(i = 0; i < m; i++){
  //   // *a = x[i];
  //   // i ++;
  //   // *b = x[i];
  //   printf("\nx[%d] = %lf\n", i, x[i]);
  // }

  // for(i = 0; i < n; i++){
  //   for(j = 0; j < m; j++){
  //     printf("\nA[%d][%d] = %lf\n", i, j, A[i][j]);
  //   }
  // }


}
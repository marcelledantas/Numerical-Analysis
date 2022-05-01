#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "mmq.h"
#include "vetor.h"
#include "matriz.h"
#include "sistlinear.h"


#define Q 3

double mmq (int m, int n, double** A, double* b, double* x){

    double** T = mat_cria (m, n);
    double** AtA = mat_cria (m, n);
    double* Atb = vet_cria (n);
    double* Ax_bar = vet_cria (n);
    double* r = vet_cria (n);

    /*
    * Aplicação do MMQ
    */
    mat_transposta (m, n, A, T);
      int i, j;
      printf("\n**Exibindo a matriz T**\n");
    for(j = 0; j < n; j ++){

    for(i = 0; i < m; i ++){

      printf("A[%d][%d] = %lf\n", i, j, A[i][j]);

    }
  }
    
    mat_multm (m, n, Q, A, T, AtA);
    mat_multv (m, n, T, b, Atb);

    /*
    * Resolvendo o sistema linear pelo método de Gauss
    */
    gauss (n, AtA, b, x);

    /*
    * Substituindo no sistema original
    */
    mat_multv (m, n, A, x, Ax_bar);

    for(i = 0; i < n; i++){
      
      r[i] = b[i] - Ax_bar[i];
    }

    
  return vet_norma2 (n, r);

}



double ajuste_parabola (int n, double* px, double* py, double* a, double* b, double* c){
  return 0.0;
}

double ajuste_cubica (int n, double* px, double* py, double* a, double* b, double* c, double* d){
  return 0.0;
}
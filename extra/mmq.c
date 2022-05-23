#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "mmq.h"
#include "vetor.h"
#include "matriz.h"
#include "sistlinear.h"


#define Q 3
#define M 4
#define W 4
    /*
    * Testar e imprimir vetores e resultados
    */

double mmq (int m, int n, double** A, double* b, double* x){

    double** T = mat_cria (m, n);
    double** AtA = mat_cria (m, n);
    double* Atb = vet_cria (n);
    double* Ax_bar = vet_cria (n);
    double* r = vet_cria (n);
    int i, j;
    /*
    * Aplicação do MMQ
    */
    mat_transposta (m, n, A, T);

  //   for(i = 0; i < n; i++){
  //     for(j = 0; j < m; j++){
  //     printf("\nT[%d][%d] = %lf\n", i, j, T[i][j]);
  //   }
  // }
      
  //   printf("\n**Exibindo a matriz T**\n");
  //   for(j = 0; j < n; j ++){

  //   for(i = 0; i < m; i ++){

  //     printf("A[%d][%d] = %lf\n", i, j, A[i][j]);

  //   }
  // }
    
    mat_multm (m, n, m, A, T, AtA);

  //   for(i = 0; i < m; i++){
  //     for(j = 0; j < m; j++){
  //     printf("\nAtA[%d][%d] = %lf\n", i, j, AtA[i][j]);
  //   }
  // }


    mat_multv (n, m, T, b, Atb);
   
    // for(i = 0; i < n; i++){
    //   printf("\nAtb[%d] = %lf\n", i, Atb[i]);
    // }
    /*
    * Resolvendo o sistema linear pelo método de Gauss
    */
    gauss (n, AtA, Atb, x);

    // for(j = 0; j < n; j++){
    //   printf("\nxgauss[%d] = %lf\n", j, x[j]);
    // }

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
  
  double** A = mat_cria (M, n);
  int i, j;

  for(i = 0; i < M; i++){
    for(j = 0; j < n; j++){

      A[i][j] = 1.0;
      j++;
      A[i][j] = px[i];
      j++;
      A[i][j] = px[i] * px[i];

    }
  }

    printf("**\nExibindo a matriz A do ajuste de parábola**\n");
    for(i = 0; i < M; i ++){

      for(j = 0; j < n; j ++){

        printf("A[%d][%d] = %lf\n", i, j, A[i][j]);

      }
    }

  // double* x = vet_cria (n);
  // double residuo = mmq (M, n, A, py, x);

  return 0.0;

}


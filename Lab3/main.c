#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "sistlinear.h"
#include "matriz.h"
#include "vetor.h"

#define N 6

int main (void){

  double** A = mat_cria (N, N);
  double* b = vet_cria (N);
  double* x = vet_cria (N);

  int i, j;

  for(i = 0; i < N; i++){
    x[i] = 0.0;
  }

  printf("**Preenchendo o vetor b**\n");
  for(i = 0; i < N; i++){
    
    printf("Entre com o valor para vetor b[%d] = \n", i);
    scanf("%lf", &b[i]);

  }

  printf("\n**Exibindo o vetor b**\n");
  for(i = 0; i < N; i++){
    printf("b[%d] = %lf \n", i, b[i]);
  }


  printf("\n\n");


  printf("**Preenchendo a matriz A**\n");
  for(j = 0; j < N; j++){

    for(i = 0; i < N; i++){
      
      printf("Entre com o valor para matriz A[%d][%d] = \n", i, j);
      scanf("%lf", &A[i][j]);

    }
  }


  printf("**\nExibindo a matriz A**\n");
  for(j = 0; j < N; j ++){

    printf("\n");
    for(i = 0; i < N; i ++){

      printf("A[%d][%d] = %lf  ", i, j, A[i][j]);

    }
  }

  printf("\n");

  gauss (N, A, b, x);

  printf("\n**Resultado do sistema linear após a aplicação do Método de Gauss**\n");
  for(i = 0; i < N; i++){
    printf("x[%d] = %lf\n", i, x[i]);
  }

  printf("**\nExibindo a matriz A após a eliminação**\n");
  for(j = 0; j < N; j++){

    printf("\n");
    for(i = 0; i < N; i++){

      printf("A[%d][%d] = %lf   ", i, j, A[i][j]);

    }
  }

  printf("\n");
  
  mat_libera(N, A);
  vet_libera(b);
  vet_libera(x);

  return 0;
}
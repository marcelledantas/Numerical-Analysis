#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "mmq.h"
#include "vetor.h"
#include "matriz.h"

#define M 3
#define N 2

int main (void){

  int i, j;

  double** A = mat_cria (M, N);
  double* b = vet_cria (N);

  printf("**Preenchendo o vetor b**\n");
  for(i = 0; i < M; i++){
    
    printf("Entre com o valor para vetor b[%d] = \n", i);
    scanf("%lf", &b[i]);

  }

  printf("\n**Exibindo o vetor b**\n");
  for(i = 0; i < M; i++){
    printf("b[%d] = %lf \n", i, b[i]);
  }


  printf("\n\n");


  printf("**Preenchendo a matriz A**\n");
  for(j = 0; j < N; j++){

    for(i = 0; i < M; i++){
      
      printf("Entre com o valor para matriz A[%d][%d] = \n", i, j);
      scanf("%lf", &A[i][j]);

    }
  }


  printf("**\nExibindo a matriz A**\n");
  for(j = 0; j < N; j ++){

    for(i = 0; i < M; i ++){

      printf("A[%d][%d] = %lf\n", i, j, A[i][j]);

    }
  }

  double* x = vet_cria (N);
  printf("residuo calculado: %lf ", mmq (M, N, A, b, x));

  printf("\n\n");

  return 0;
}
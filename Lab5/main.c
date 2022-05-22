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

  // /*
  // * Teste para a função mmq
  // *
  // */

  // double** A = mat_cria (M, N);
  // double* b = vet_cria (N);

  // printf("**Preenchendo o vetor b**\n");
  // for(i = 0; i < M; i++){
    
  //   printf("Entre com o valor para vetor b[%d] = \n", i);
  //   scanf("%lf", &b[i]);

  // }

  // printf("\n**Exibindo o vetor b**\n");
  // for(i = 0; i < M; i++){
  //   printf("b[%d] = %lf \n", i, b[i]);
  // }

  // printf("\n\n");


  // printf("**Preenchendo a matriz A**\n");
  // for(j = 0; j < N; j++){

  //   for(i = 0; i < M; i++){
      
  //     printf("Entre com o valor para matriz A[%d][%d] = \n", i, j);
  //     scanf("%lf", &A[i][j]);

  //   }
  // }


  // printf("**\nExibindo a matriz A**\n");
  // for(j = 0; j < N; j ++){

  //   for(i = 0; i < M; i ++){

  //     printf("A[%d][%d] = %lf\n", i, j, A[i][j]);

  //   }
  // }

  // double* x = vet_cria (N);
  // printf("residuo calculado: %lf ", mmq (M, N, A, b, x));

  // printf("\n\n");



  /*
  * Teste para a função ajuste_parabola
  *
  */

  double* px = vet_cria (N);
  double* py = vet_cria (N);
  double *a, *b, *c;

  printf("**Preenchendo o vetor px e py**\n");
  for(i = 0; i < 3; i++){
    printf("\nEntre com o valor de px[%d]: ", i);
    scanf("%lf", &px[i]);
  }

  for(i = 0; i < 3; i++){
    printf("\nEntre com o valor de py[%d]: ", i);
    scanf("%lf", &py[i]);
  }

  printf("Resíduo ajuste_parabola: %lf", ajuste_parabola (3, px, py, a, b, c));

  return 0;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "matriz.h"
#include "gradconj.h"
#include "vetor.h"

int main(void)
{
  int n, i, j;
  n = 10;

  double **A = mat_cria(n, n);

  printf("**Preenchendo a matriz A**\n");
  for (j = 0; j < n; j++)
  {
    for (i = 0; i < n; i++)
    {
      printf("Entre com o valor para matriz A[%d][%d] = \n", i, j);
      scanf("%lf", &A[i][j]);
    }
  }

  // A[10][10] = {
  //     {1.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  //     {0.4, 2.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  //     {0.0, 0.4, 3.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  //     {0.0, 0.0, 0.4, 4.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0},
  //     {0.0, 0.0, 0.0, 0.4, 5.0, 0.4, 0.0, 0.0, 0.0, 0.0},
  //     {0.0, 0.0, 0.0, 0.0, 0.4, 6.0, 0.4, 0.0, 0.0, 0.0},
  //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 0.7, 0.4, 0.0, 0.0},
  //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 8.0, 0.4, 0.0},
  //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 9.0, 0.4},
  //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 10.0}};

  // double b[10] = {1.4, 2.8, 3.8, 4.8, 5.8, 6.8, 7.8, 8.8, 9.8, 10.4};

  double *b = vet_cria(n);

  printf("**Preenchendo o vetor b**\n");
  for (i = 0; i < n; i++)
  {
    printf("Entre com o valor para vetor b[%d] = \n", i);
    scanf("%lf", &b[i]);
  }

  double *x = vet_cria(n);

  double tol = 1E-10;

  printf("\n***Resultados aplicando Gradiente Conjugados - Sem Precondicionador***\n");

  int numItergradconj = gradconj(n, A, b, x, tol);

  printf("Número de iterações = %d\n", numItergradconj);

  for (i = 0; i < n; i++)
  {
    printf("x[%d] = %lf\n", i, x[i]);
  }

  int numItergradconjJacobi = gradconj_jacobi(n, A, b, x, tol);
  printf("\n****Resultados aplicando Gradiente Conjugados - Com Precondicionador****\n");

  printf("Número de iterações = %d\n", numItergradconjJacobi);

  for (i = 0; i < n; i++)
  {
    printf("x[%d] = %lf\n", i, x[i]);
  }

  return 0;
}
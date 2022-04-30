#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double** mat_cria (int m, int n){
  double **matrix = (double**)malloc(m * sizeof(double*));
  int i;

  for (i = 0; i < m; i++){
    matrix[i] = (double*)malloc(n * sizeof(double));
  }
  if(matrix == NULL){
    exit(1);
  }

  return matrix;
}

void mat_libera (int m, double** A){
  int i;

  for(i = 0; i < m; i++){
    free(A[i]);
  }
}

void mat_transposta (int m, int n, double** A, double** T){
  int i, j;

  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      T[j][i] = A[i][j];
    }
  }
}

void mat_multv (int m, int n, double** A, double* v, double* w){
  int i, j;
  double aux;

  for (i = 0; i < m; i++){
    aux = 0;
    for(j = 0; j < n; j++){
      aux += A[i][j] * v[j];
    }
    w[i] = aux;
  }
}

void mat_multm (int m, int n, int q, double** A, double** B, double** C){
  int i, j, k;
  double sum = 0.0;

  for (i = 0; i < m; i++){
    for(j = 0; j < q; j++){
      for (k = 0; k < n; k++){
        sum += A[i][k] * B[k][j]; 
      }
      C[i][j] = sum;
      sum = 0.0;
    }
  }
}

void mat_imprime (int m, int n, double** A){
  int i, j;

  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      printf("%lf  ", A[i][j]);
    }
      printf("\n");
  }
}
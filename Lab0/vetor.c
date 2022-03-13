#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double* vet_cria (int n){
  double *v = (double*)malloc(n * sizeof(double));

  if (v == NULL){
    exit(0);
  }
  return v;
}

void vet_libera (double* v){
  free(v);
}

double vet_escalar (int n, double* v, double* w){
  int i;
  double prodEsc = 0;

  for(i = 0; i < n; i++){
    prodEsc += v[i] * w[i];
  }
  
  return prodEsc;
}

double vet_norma2 (int n, double* v){
  int i;
  double norma = 0;

  for (i = 0; i < n; i++){
    norma += (v[i] * v[i]);
  }

  int norma2 = sqrt(norma);

  return norma2;
}


void vet_mults (int n, double* v, double s, double* w){
  int i;

  for(i = 0; i < n; i++){
    w[i] = v[i] * s;
  }
}

void vet_imprime (int n, double* v){
  int i;

  for(i = 0; i < n; i++){
    printf("%f  ", v[i]);
  }
  printf("\n");
}



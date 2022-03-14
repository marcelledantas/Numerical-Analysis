#include<stdio.h>
#include "vetor.h"
#include "matriz.h"
#define NUM_VECTOR 3

int main (void){

  //Vector

  double *v = vet_cria(NUM_VECTOR);
  double *w = vet_cria(NUM_VECTOR);

  for (int i = 0; i < NUM_VECTOR; i++){
    v[i] = 5;
    w[i] = 2;
  }

  // //Teste vet_escalar ok
  printf("O produtor escalar entre v e w é: \n%.5g", (vet_escalar(NUM_VECTOR, v, w)));

  // //Teste vet_mults ok
  vet_mults(NUM_VECTOR, v, 5, w);
  printf("\nMultiplicação entre v e w\n");
  vet_imprime(NUM_VECTOR, w);

  // //Teste vet_norma2 ok
  printf("\nNormal de v: %.5g\n", vet_norma2(NUM_VECTOR, v));

  vet_libera(v);
  vet_libera(w);

  //Matrix

  double **ma = mat_cria(2, 3);
  double **mb = mat_cria(3, 4);
  double **mc = mat_cria(2, 4);
   
  double **mt = mat_cria(3, 2);

  printf("\nMatriz ma:\n");
  for (int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      scanf("%lf", &ma[i][j]); 
    }
  }
  printf("\nMatriz mb:\n");
  for (int i = 0; i < 3; i++){ 
    for(int j = 0; j < 4; j++){
      scanf("%lf", &mb[i][j]); 
    }
  }
  
  //Teste mat_transposta ok
  printf("\nMatriz ma\n");
  mat_imprime(2, 3, ma);

  //Teste mat_transposta ok
  printf("\nMatriz mb\n");
  mat_imprime(3, 4, mb);
  mat_transposta(2, 3, ma, mt);
  printf("\nMatriz mt\n");
  mat_imprime(3, 2, mt);

  // Teste mat_multv ok
  mat_multv(2 ,3, ma, v, w);
  printf("\nVetor w\n");
  vet_imprime(2, w);


  mat_multm(2, 3, 4, ma, mb, mc);
  printf("\nMultiplicação\n");
  mat_imprime(2, 4, mc);

  //Teste mat_libera ok
  mat_libera(2, ma);
  mat_libera(2, mb);
  mat_libera(2, mc);
  mat_libera(2, mt);

  return 0;
}
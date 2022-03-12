#include<stdio.h>
#include "vetor.h"
#define NUM_VECTOR 4

int main (void){

  double *v = vet_cria(NUM_VECTOR);

  //Criando e populando o vetor
  for(int i = 0; i < NUM_VECTOR; i++){
    v[i] = 0;
  }
   
  for(int i = 0; i < NUM_VECTOR; i++){
    v[i] = v[i] + 1;
  }
  
  double *w = vet_cria(NUM_VECTOR);

  printf("O produtor escalar entre v e w é: \n%f", (vet_escalar(NUM_VECTOR, v, w)));

  vet_mults(NUM_VECTOR, v, 10, w);
  printf("\n");
  //Imprime e libera o espaço alocado dinamicamente
  vet_imprime(NUM_VECTOR, w);
  vet_libera(v);
  return 0;
}
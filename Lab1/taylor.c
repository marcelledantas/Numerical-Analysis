#include <stdio.h>
#include "taylor.h"
#include "vetor.h"


double avalia_taylor (int n, double *c, double x0, double x){

  int i;
  double fat = 1.0, denominador = 1.0, termo = 0.0, fatAux = 1.0;

  for(i = 0; i < n; i++){

    termo += c[i] * (denominador/fat);
    fat += fat * i;

    denominador *= (x - x0);
    
  }
  
  vet_libera(c);
  return termo;
}

double avalia_cosseno (int n, double x){

  double *c = vet_cria(n);
  double x0 = 0.0;
  int i;
  c = vet_cria(n);

  for (i = 0; i < n; i++){
    
    if(i == 0){
      c[i] = 1;
    }
    else if((i % 2) != 0){ //ímpar
      c[i] = 0;
    }
    else if (c[i - 2] == 1){
      c[i] = -1;
    }
    else if (c[i - 2] == -1){
      c[i] = 1;
    }
}
  return (avalia_taylor(n, c, x0, x));
}


double avalia_seno (int n, double x){
  double *c = vet_cria(n);
  double x0 = 0.0;
  int i;

  for (i = 0; i < n; i++){
    
    if((i % 2) == 0){ //par
      c[i] = 0;
    } 
    else{
      if(i == 1){
        c[i] = 1;
      }
      else if(c[i - 2] == 1){
        c[i] = -1;
      } 
      else if(c[i - 2] == -1){
        c[i] = 1;
      }
    }

  }
  return (avalia_taylor(n, c, x0, x));
}
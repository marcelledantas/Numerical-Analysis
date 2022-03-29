#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "raiz.h"

#define e_bis_reg 0.5e-8
#define emax_bis 1e-12

#define e_sec_reg 0.5e-10
#define e_sec_max 1e10-15
#define max_iteracao 50


int bissecao (double a, double b, double (*f) (double x), double* r){

  double c, fa = f(a), fb = f(b);
  int i = 1;

  if ((fa * fb) > 0.0){
    printf("\nNão houve inversão de f(x)\n");
    return 0;
  }

  if((fa * fb) < 0.0){
    
    *r = (a + b)/2;
   
    while(((b - a)/2) > e_bis_reg){
      
      c = (a + b)/2;
      *r = c;

      if((fabs(f(c))) < emax_bis){
        printf("\n Iteração atingiu o criterio fabs(f(c)) < e-12 e foi interrompida > retonando a raíz\n");
        break;
      }
      else if((fa * f(c)) < 0.0){
        b = c;
      }
      else{
        a = c;
      }

      i ++;
    }
  }
    return i; //Retorna o nº de iterações
}


int secante (double x0, double x1, double (*f) (double x), double* r){

  int i = 1;
  double x2;

    
  do{

    // if (fabs(f(x1) - f(x0)) < e_sec_max){
    //   x2 = (x0 + x1)/2;
    // }
    // else{
    //   x2 = x1 - ((f(x1) * (x1 - x0)) / (f(x1) - f(x0))); 
    // }

    x2 = (x0 * f(x1) - x1 * f(x0))/(f(x1)-f(x0));

    x0 = x1;
    x1 = x2;

    i++;
    *r = x2;

    if(i == max_iteracao){
      printf("\nAtingiu-se 50 iterações sem convergência\n");
      *r = -1;
      return 0;
    }
  }while(fabs(f(x2)) > e_sec_reg);

  return i;
}
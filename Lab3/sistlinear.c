
#include<stdio.h>
#include<stdlib.h>
#include "math.h"

#include "sistlinear.h"

void gauss (int n, double** A, double* b, double* x){

  int i, j, k, p;
  double fatorF, s, temp1, temp2;
  
  for(j = 0; j < n - 1; j ++){

    p = j;
    
    //pivoteamento - antes da eliminação da coluna j

    for(k = j + 1; k < n; k ++){
      
      if( fabs(A[k][j]) > fabs(A[p][j]) ){
        p = k;

      }//if
    } //for

    //troca linhas j e p
    for (k = j; k < n; k ++){
      
      temp1 = A[j][k];
      A[j][k] = A[p][k];
      A[p][k] = temp1;
    }

    temp2 = b[p];
    b[p] = b[j];
    b[j] = temp2;
    

    //Elimina coluna j

    for(i = j + 1; i < n; i ++){
      
      //Elimina aij
      fatorF = A[i][j] / A[j][j];

      for(k = j; k < n; k ++){

        A[i][k] = A[i][k] - A[j][k] * fatorF;

      } //for

      b[i] = b[i] - b[j] * fatorF;

    } //for

  } //for


  //Retro-substituição

  for (i = n - 1; i >= 0; i --){
   
    s = 0;

    for(j = n - 1; j > i; j --){

      s = s + A[i][j] * x[j];
    
    }//for

    x[i] = (b[i] - s) / A[i][i];

  }//for


}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 10
#define PI 3.142857

#include "taylor.h"
#include "vetor.h"


int main (void){

  double cossenoAprox = avalia_cosseno (N, PI/10);
  printf("\n Cosseno aproximado pi/10 é: %lf e o cos(PI/10) é: %lf\n", cossenoAprox, cos(PI/10));

  cossenoAprox = avalia_cosseno (N, PI/8);
  printf("\n Cosseno aproximado pi/8 é: %lf e o cos(PI/8) é: %lf\n", cossenoAprox, cos(PI/8));

  cossenoAprox = avalia_cosseno (N, PI/6);
  printf("\n Cosseno aproximado pi/6 é: %lf e o cos(PI/6) é: %lf\n", cossenoAprox, cos(PI/6));

  cossenoAprox = avalia_cosseno (N, PI/4);
  printf("\n Cosseno aproximado pi/4 é: %lf e o cos(PI/4) é: %lf\n", cossenoAprox, cos(PI/4));

  cossenoAprox = avalia_cosseno (N, PI/3);
  printf("\n Cosseno aproximado pi/3 é: %lf e o cos(PI/3) é: %lf\n",       cossenoAprox, cos(PI/3));

 printf("\n\n");
  
  double senoAprox = avalia_seno (N, PI/10);
  printf("\n Seno aproximado pi/10 é: %lf e o sen(PI/10) é: %lf\n",senoAprox, sin(PI/10));

  senoAprox = avalia_seno (N, PI/8);
  printf("\n Seno aproximado pi/8 é: %lf e o sen(PI/8) é: %lf\n", senoAprox, sin(PI/8));

  senoAprox = avalia_seno (N, PI/6);
  printf("\n Seno aproximado pi/6 é: %lf e o sen(PI/6) é: %lf\n", senoAprox, sin(PI/6));  
  
  senoAprox = avalia_seno (N, PI/4);
  printf("\n Seno aproximado pi/4 é: %lf e o sen(PI/4) é: %lf\n", senoAprox, sin(PI/4));  

  senoAprox = avalia_seno (N, PI/3);
  printf("\n Seno aproximado pi/3 é: %lf e o sen(PI/3) é: %lf\n", senoAprox, sin(PI/3));  

  return 0;
}







#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "otimizacao.h"

double f(double x)
{
  return (x * x * x * x * x * x - 11 * x * x * x + 17 * x * x - 7 * x + 1);
}

double g(double x)
{
  return (x * x + sin(x));
}

int main(void)
{
  double r, delta, *xmin;
  xmin = malloc(sizeof(double));

  r = 1;
  delta = -0.5;

  int nIteracoes = mips(r, delta, f, xmin);
  printf("\nNúmero de iterações pelo método Interpolação Parabólica Sucessiva: %d\n", nIteracoes);
  printf("\nValor mínimo da função encontrada pelo método: %lf\n", *xmin);

  free(xmin);
  return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "gradconj.h"
#include "vetor.h"
#include "matriz.h"

int gradconj(int n, double **A, double *b, double *x, double tol)
{
  double alphak, bethak, numerador, denominador;
  int k, i;

  double *rk0 = vet_cria(n);
  double *rk1 = vet_cria(n);
  double *dk0 = vet_cria(n);
  double *dk1 = vet_cria(n);
  double *Adk = vet_cria(n);
  double *xk1 = vet_cria(n);

  mat_multv(n, n, A, x, Adk);

  numerador = 0;
  denominador = 0;

  for (int i = 0; i < n; i++)
  {
    rk0[i] = b[i] - Adk[i];
    dk0[i] = rk0[i];
  }

  for (int k = 0; k < n; k++)
  {
    if (vet_norma2(n, rk0) < tol)
    {
      break;
    }

    mat_multv(n, n, A, dk0, Adk);

    for (i = 0; i < n; i++)
    {
      numerador += (rk0[i] * rk0[i]);
      denominador += (dk0[i] * Adk[i]);
    }

    alphak = (numerador / denominador);

    // xk+1 = xk + alphak*dk
    // rk+1 = rk + alphak*Adk
    for (i = 0; i < n; i++)
    {
      xk1[i] = x[i] + alphak * dk0[i];
      rk1[i] = rk0[i] - alphak * Adk[i];
    }

    numerador = 0;
    denominador = 0;

    for (i = 0; i < n; i++)
    {
      numerador += rk1[i] * rk1[i];
      denominador += rk0[i] * rk0[i];
    }

    bethak = (numerador / denominador);

    for (i = 0; i < n; i++)
    {
      dk1[i] = rk1[i] + bethak * dk0[i];
    }

    for (i = 0; i < n; i++)
    {
      x[i] = xk1[i];
      rk0[i] = rk1[i];
      dk0[i] = dk1[i];
    }
  }

  return k;
}

int gradconj_jacobi(int n, double **A, double *b, double *x, double tol)
{
  double alphak, bethak, numerador, denominador;
  int k, i;

  double *rk0 = vet_cria(n);
  double *rk1 = vet_cria(n);
  double *dk0 = vet_cria(n); // dk0 == zk0
  double *dk1 = vet_cria(n);
  double *zk0 = vet_cria(n);
  double *zk1 = vet_cria(n);
  double *Adk = vet_cria(n);
  double *xk1 = vet_cria(n);

  mat_multv(n, n, A, x, Adk);

  numerador = 0;
  denominador = 0;

  for (int i = 0; i < n; i++)
  {
    rk0[i] = b[i] - Adk[i];
    dk0[i] = (rk0[i] / A[i][i]);
    zk0[i] = (rk0[i] / A[i][i]);
  }

  for (int k = 0; k < n; k++)
  {
    if (vet_norma2(n, rk0) < tol)
    {
      break;
    }

    mat_multv(n, n, A, dk0, Adk);

    for (i = 0; i < n; i++)
    {
      numerador += (rk0[i] * zk0[i]);
      denominador += (dk0[i] * Adk[i]);
    }

    alphak = (numerador / denominador);

    // xk+1 = xk + alphak*dk
    // rk+1 = rk + alphak*Adk
    for (i = 0; i < n; i++)
    {
      xk1[i] = x[i] + alphak * dk0[i];
      rk1[i] = rk0[i] - alphak * Adk[i];
      zk1[i] = (rk1[i] / A[i][i]);
    }

    numerador = 0;
    denominador = 0;

    for (i = 0; i < n; i++)
    {
      numerador += rk1[i] * zk1[i];
      denominador += rk0[i] * zk0[i];
    }

    bethak = (numerador / denominador);

    for (i = 0; i < n; i++)
    {
      dk1[i] = zk1[i] + bethak * dk0[i];
    }

    for (i = 0; i < n; i++)
    {
      x[i] = xk1[i];
      rk0[i] = rk1[i];
      dk0[i] = dk1[i];
      zk0[i] = zk1[i];
    }
  }

  return k;
}
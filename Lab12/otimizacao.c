#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "otimizacao.h"

int mips(double r, double delta, double (*f)(double x), double *xmin)
{
  double ft, fr, fs, x, denominador, numerador, t, s, tol, paramConv;
  int nIter;

  s = r - delta;
  t = r + delta;
  nIter = 0;
  tol = 1E-10;

  fr = f(r);
  ft = f(t);
  fs = f(s);

  denominador = (fs - fr) * (t - r) * (t - s);
  numerador = 2 * ((s - r) * (ft - fs) - (fs - fr) * (t - s));

  paramConv = denominador;

  while (nIter <= 50)
  {
    if (paramConv < tol)
    {
      x = (r + s + t) / 3;
      // *xmin = (s + t) / 2;
      return nIter;
    }

    if (nIter >= 3)
    {
      paramConv = fabs(fs - ft);
      tol = 1E-6;
    }

    fr = f(r);
    ft = f(t);
    fs = f(s);

    denominador = (fs - fr) * (t - r) * (t - s);
    numerador = 2 * ((s - r) * (ft - fs) - (fs - fr) * (t - s));

    x = (((r + s) / 2) - (denominador / numerador));

    nIter++;

    *xmin = (s + t) / 2;

    r = s;
    s = t;
    t = x;
  }

  return 0;
}

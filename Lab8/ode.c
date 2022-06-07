#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "ode.h"
#define h0 1E-7

double RungeKutta(double t0, double t1, double h, double y0, double (*f)(double t, double y))
{

  double k1, k2, k3, k4;
  double y;
  int i, n;

  y = y0;
  n = (int)(t1 - t0) / h;

  for (i = 0; i < n; i++)
  {

    // Aplicando as fórmulas de Runge Kutta
    // Próximo valor de y
    k1 = h * f(t0, y);
    k2 = h * f(t0 + 0.5 * h, y + 0.5 * k1);
    k3 = h * f(t0 + 0.5 * h, y + 0.5 * k2);
    k4 = h * f(t0 + h, y + k3);

    y = y + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
    t0 = t0 + h;
  }

  return y;
}

double RungeKuttaAdapt(double t0, double t1, double y0, double (*f)(double t, double y), double tol)
{

  double k1, k2, k3, k4;
  double y, yaux, factor, delta, h;
  int t, n;

  y = y0;
  n = (int)(t1 - t0) / h0;

  while (t0 < t1)
  {

    factor = pow((tol / delta), 5.0);

    if (factor >= 1.0)
    {
      y += y + delta;
      h = 1.2 * factor * h;
    }
    else
    {
      h = 0.8 * factor * h;
    }

    // Aplicando as fórmulas de Runge Kutta
    // Próximo valor de y
    k1 = h * f(t0, y);
    k2 = h * f(t0 + 0.5 * h, y + 0.5 * k1);
    k3 = h * f(t0 + 0.5 * h, y + 0.5 * k2);
    k4 = h * f(t0 + h, y + k3);

    y += y + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
    t0 = t0 + h;
  }

  return y;
}
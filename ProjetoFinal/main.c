#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "pendulum.h"

int main(void)
{

  RungeKuttaAdaptativo(0.1, PI / 20, 3.0, 0.01, 0.2);
  RungeKuttaAdaptativo(0.1, PI / 30, 3.0, 0.01, 0.2);
  RungeKuttaAdaptativo(0.1, PI / 6, 3.0, 0.01, 0.2);
  RungeKuttaAdaptativo(0.1, PI / 3, 3.0, 0.01, 0.2);

  return 0;
}
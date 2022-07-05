#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "pendulum.h"

double ddTheta(double theta)
{
  return -(G / L) * sin(theta); // aproximando theta = seno(theta), considerando theta muito pequeno
}

double RungeKuttaPassoFixo(double h, double theta0, double *v)
{
  double ktheta1, ktheta2, ktheta3, ktheta4;
  double dV1, dV2, dV3, dV4;

  ktheta1 = h * (*v);
  dV1 = h * ddTheta(theta0);

  ktheta2 = h * (*v + (dV1 / 2.0));
  dV2 = h * ddTheta(theta0 + (ktheta1 / 2.0));

  ktheta3 = h * (*v + (dV2 / 2.0));
  dV3 = h * ddTheta(theta0 + (ktheta2 / 2.0));

  ktheta4 = h * (*v + dV3);
  dV4 = h * ddTheta(theta0 + ktheta3);

  *v += ((dV1 + (2 * dV2) + (2 * dV3) + dV4) / 6.0);

  return theta0 + ((ktheta1 + (2 * ktheta2) + (2 * ktheta3) + ktheta4) / 6.0);
}

double solucaoAnaliticaSimplificada(double theta0, double t)
{
  return (theta0 * cos(sqrt(G / L) * t));
}

void RungeKuttaAdaptativo(double h, double theta0, double tempo, double hMin, double hMax)
{
  // FILE *solucaoAnalitica = fopen("solucao-analitica.txt", "a");
  // FILE *solucaoNum = fopen("solucao-numerica.txt", "a");

  FILE *solucaoAnalitica = fopen("solucao-analitica.txt", "a");

  FILE *solucaoNum_i = fopen("solucao-numerica-i.txt", "a");
  FILE *solucaoNum_theta = fopen("solucao-numerica-theta.txt", "a");

  if (solucaoAnalitica == NULL || solucaoNum_i == NULL || solucaoNum_theta == NULL)
  {
    printf("Erro na criação do arquivo\n");
    exit(1);
  }

  double passo, ktheta1, ktheta2_1, ktheta2_2, theta;
  double i, delta, v1, v2, aux1;
  int numPassos;

  i = 0.0;
  theta = theta0;
  v1 = 0.0;
  v2 = 0.0;

  // fprintf(solucaoNum, "Solucão Numérica Runge Kutta Adaptativo\n");
  // fprintf(solucaoNum, "theta0 = %.5g:\n", theta0);
  // fprintf(solucaoNum, "c:=pointpot([");
  // fprintf(solucaoNum, "[%.5g, %.5g]", 0.0, theta0);

  fprintf(solucaoNum_i, "Solucão Numérica Runge Kutta Adaptativo - Pontos i\n");
  fprintf(solucaoNum_theta, "theta0 = %.5g:\n", theta0);
  fprintf(solucaoNum_i, "theta0 = %.5g:\n", theta0);
  // fprintf(solucaoNum, "c:=pointpot([");
  // fprintf(solucaoNum, "[%.5g, %.5g]", 0.0, theta0);
  fprintf(solucaoNum_i, "%.5g\n", 0.0);
  fprintf(solucaoNum_theta, "%.5g\n", theta0);

  fprintf(solucaoAnalitica, "Solucão Analítica Simplificada\n");
  fprintf(solucaoAnalitica, "theta0 = %.5g:\n", theta0);
  fprintf(solucaoAnalitica, "a:=pointplot([");
  fprintf(solucaoAnalitica, "[%.5g, %.5g]", 0.0, solucaoAnaliticaSimplificada(theta0, 0.0));

  while (i < tempo)
  {
    numPassos = 0;

    while (1)
    {
      aux1 = v1;
      v2 = v1;
      ktheta1 = RungeKuttaPassoFixo(passo, theta, &v1);
      ktheta2_1 = RungeKuttaPassoFixo(passo / 2, theta, &v2);
      ktheta2_2 = RungeKuttaPassoFixo(passo / 2, ktheta2_1, &v2);

      delta = fabs(ktheta2_2 - ktheta1);
      numPassos++;

      if (passo > hMax)
      {
        passo = hMax;
      }
      else if (passo < hMin)
      {
        passo = hMin;
      }

      if (delta < e || numPassos > 200)
      {
        break;
      }

      v1 = aux1;
      passo = sqrt(e / delta) * passo;
    }

    i += passo;
    theta = ktheta1;

    // fprintf(solucaoNum, ",[%.5g, %.5g]", i, theta);
    // fprintf(solucaoAnalitica, ",[%.5g, %.5g]", i, solucaoAnaliticaSimplificada(theta0, i));

    fprintf(solucaoNum_i, "%.5g ", i);
    fprintf(solucaoNum_theta, "%.5g ", theta);
    // fprintf(solucaoAnalitica, ",[%.5g, %.5g]", i, solucaoAnaliticaSimplificada(theta0, i));
  }

  // fprintf(solucaoNum, "],color=red,connect):\n\n");
  // fprintf(solucaoAnalitica, "],color=green,connect):\n\n");

  fclose(solucaoNum_theta);
  fclose(solucaoNum_i);
  fclose(solucaoAnalitica);
}
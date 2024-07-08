/**
  Sistema Dinâmico de Lorentz 
  By Alexandre e Joao 
  4 de Julho de 2024
**/
#include <stdio.h>
#include <stdlib.h>

// caso particular com parâmetros apresentados no livro de Strogatz:
double SIGMA = 10.0;
double TAU   = 28.0;
double BETA  = 8.0 / 3.0;

int main(void){
  double dt = 0.025;
  double x = 1.25;
  double y = 22.22; ;
  double z = 33.21;

  FILE *fd;
  
  fd = fopen("borboleta.dat","w");
  if (fd == NULL){
    printf("não pode abrir arquivo");
    exit(1);
  }
// discretização das 3 equações
  for (float t=0.0; t < 500.0 ; t+=dt){
    x = x + SIGMA * ( y - x ) * dt;
    y = y + (x * (TAU - z) - y ) * dt;
    z = z + (x * y - (BETA * z)) * dt;
    fprintf(fd, "%f  %f  %f\n", x, y, z);
  }
  fclose(fd);

  return 0;
}

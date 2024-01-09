#include <stdio.h>
#include <math.h>

#include "Metodos.h"

double Funcion(double x);

int main (void) {
    //? Declaramos las variables y a cada una le pondremos un nombre
    //? que reconozcamos facilmente
    double Rs, Ri, Tr, S_13, S_38;

    Rs = Riemman_sup(5, 50, 20);
    Ri = Riemman_inf(5, 50, 20);
    Tr = Trapecio(5, 50, 20);
    S_13 = Simpson_1_3(5, 50, 20);
    S_38 = Simpson_3_8(5, 50, 20);
    
    printf("El area es aproximadamente: \n");
    printf("Riemman Superior: %lf \n", Rs);
    printf("Riemman Inferior: %lf \n", Ri);
    printf("Trapecio: %lf \n", Tr);
    printf("Simpson 1/3: %lf \n", S_13);
    printf("Simpson 3/8: %lf \n", S_38);

    return 0;
}

double Funcion(double x) {
    double y, L, mu, d, rho, alpha, g, R_bolsa;
    L = 91.44;
    mu = 0.01;
    d = 0.1;
    rho = 1;
    alpha = 64*L*mu/(d*d*rho);
    g = 981;
    R_bolsa = 10;
    y = (1/(-alpha+sqrt(alpha*alpha+8*g*(x+L))));
    return y;
}
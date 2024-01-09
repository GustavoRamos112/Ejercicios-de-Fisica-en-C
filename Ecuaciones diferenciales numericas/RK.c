#include <stdio.h>
#include <math.h>

#include "funciones.h"

int main (void)
{
    double h, Adi, Bdi,x_i, y_i;
    double k_1, k_2, k_3, k_4;
    int Pasos;
    double Eulina;

    //? Definimos los valores iniciales
    x_i = 0;
    y_i = 1;
    Adi = 0;
    Bdi = 1;
    //? El numero de pasos
    Pasos = 100;
    h = (double)(Bdi-Adi)/Pasos;
    //? Establecemos el archivo donde se escribiran los datos
    FILE *open;
    open = fopen("datosK.dat", "w");
    
    for(int i = 0; i < Pasos; i++) {
        x_i += h;
        //? Definimos las constantes k_in
        k_1 = h*Freyja(x_i, y_i);
        k_2 = h*Freyja(x_i+h/2, y_i+k_1/2);
        k_3 = h*Freyja(x_i+h/2, y_i+k_2/2);
        k_4 = h*Freyja(x_i+h, y_i+k_3);
        y_i = (k_1+2*k_2+2*k_3+k_4)/6+y_i;
        //! Imprimimos en una archivo los datos
        //! fprintf(open,"%lf\t%lf\n",x_i, y_i);
		printf("%lf\t%lf\n", x_i, y_i);
    }
    fclose(open);
    return 0;
}
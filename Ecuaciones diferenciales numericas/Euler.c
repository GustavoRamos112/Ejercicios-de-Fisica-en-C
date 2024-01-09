#include <stdio.h>
#include <math.h>

#include "funciones.h"

int main(void)
{
    double y_i;
    double Adi, Bdi, Pasos, h;
    double Eulina;

    //? Definimos Adi  =  x_o
    Adi = 0;
    //? Definimos el final del intervalo como Bdi
    Bdi = 1;
    //? El numero de pasos
    Pasos = 100;
    //? Definimos y_o = y_i
    y_i = 1;
    h = (Bdi-Adi)/Pasos;
    //? Definimos el archivo a donde los datos seran enviados para luego graficarlos
    FILE *open;
    open = fopen("datosE.dat", "w");
    
    for (int i = 1; i <= Pasos; i++) {
        y_i = h*Falak(Adi+i*h, y_i)+y_i;
        fprintf(open, "%lf\t%lf\n", Adi+i*h, y_i);
        //! Para dar los datos por consola
		//! printf("%lf\t%lf\n", Adi+i*h, y_i);
    }
    
    fclose(open);
    return 0;
}

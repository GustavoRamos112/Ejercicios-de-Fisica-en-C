
//* Indicaciones:
//* Crea un programa que ejecute tres subfunciones:
//* 1.- Una que lea una ecuacion cuadratica de una rchivo de datos
//* 2.- Otra que resuelva la ecuacion cuadratica
//* 3.- Una que imprima las soluciones en un archivo de datos

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//? Declaramos las variables globales, al estar Adi, Bdi, etc. antes de la declaracion de las
//? subrutinas, se puede acceder a ellas desde cualquier parte del programa
double Adi, Bdi, Cdi, Xdip, Xdim;

void lec(void);
void rai(void);
void esc(void);


//? La funcion principal ejecuta solo las tres subrutinas
int main(void)
{
    lec();
    rai();
    esc();

    return 0;
}

//? La primera subrutina se encarga de leer los valores de las variables a, b y c
void lec()
{
    //? aqui si declaramos los archivos que vamos a usar de escritura (w) y de lectura (r)
    FILE *entrada;
    entrada=fopen("ecuacion.dat", "r");
    fscanf(entrada, "(%lf)x^2+(%lf)x+(%lf)=0", &Adi, &Bdi, &Cdi);
    fclose(entrada);
}

//? La segunda subrutina se encarga de calcular las raices de la ecuacion para cada uno de los casos
void rai()
{
    if(Adi == 0)
    {
        Xdip=-Cdi/Bdi;
    }
    //? Caso cuando el determinante es mayor a cero, la ecuacion tiene soluciones reales
    if(Adi != 0 && (Bdi*Bdi-4*Adi*Cdi)>0)
    {
        Xdip = (-Bdi+sqrt(Bdi*Bdi-4*Adi*Cdi))/(2*Adi);
        Xdim = (-Bdi-sqrt(Bdi*Bdi-4*Adi*Cdi))/(2*Adi);
    }
    //? Caso con detrminante menor a cero, la cuacion tiene soluciones complejas
    if(Adi != 0 && (Bdi*Bdi-4*Adi*Cdi)<0)
    {
        //? Esta variable es la aprte real de a solucion
        Xdip = (-Bdi)/(2*Adi);
        //? Esta es la parte imaginaria que se le agrega a la solucion
        Xdim = (sqrt(-Bdi*Bdi+4*Adi*Cdi))/(2*Adi);
    }
    //? Caso cuando el determinante es igual a cero, la ecuacion tiene soluciones dobles
    if(Adi!=0 && ((Bdi*Bdi-4*Adi*Cdi)==0))
    {
        Xdip = (-Bdi)/(2*Adi);
    }
}

//? La tercera subrutina se encarga de escribir los valores de las raices en el archivo raices.dat
//? Nada que escribir, solo escribe las soluciones en raices.dat
void esc()
{

    FILE *out1;

    out1=fopen("raices.dat","w");

    fprintf(out1, "====================================================================================\n");
    fprintf(out1, "La ecuacion leida es: (%lf)x^2+(%lf)x+(%lf)=0\n", Adi, Bdi, Cdi);

    if(Adi == 0)
    {
        fprintf(out1,"No es una ecuacion cuadratica, sino una lineal, pero su solucion es: %lf\n", Xdip);
        fprintf(out1, "====================================================================================\n");
    }
    //? Caso cuando la ecuacion tiene soluciones reales
    if(Adi != 0 && (Bdi*Bdi-4*Adi*Cdi) > 0)
    {
        fprintf(out1,"La ecuacion tiene soluciones reales: \nx_1=%lf y x_2=%lf\n", Xdip, Xdim);
        fprintf(out1, "====================================================================================\n");
    }
    //? Caso cuando la cuacion tiene soluciones complejas
    if(Adi != 0 && (Bdi*Bdi-4*Adi*Cdi) < 0)
    {
        fprintf(out1,"La ecuacion tiene soluciones imaginarias: \nx_1=%lf+%lfi y x_2=%lf-%lfi\n", Xdip, Xdim, Xdip, Xdim);
        fprintf(out1, "====================================================================================\n");
    }
    //? Caso cuando la ecuacion tiene una solucion doble
    if(Adi != 0 && ((Bdi*Bdi-4*Adi*Cdi) == 0))
    {
        fprintf(out1,"La ecuacion tiene una solucion doble:\nx=%lf\n", Xdip);
        fprintf(out1, "====================================================================================\n");
    }

    fclose(out1);
}

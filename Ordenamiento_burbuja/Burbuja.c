
//* Indicaciones:
//* Crea un programa con una funcion que ordene un arreglo numerico
//* por el metodo de ordenamiento burbuja

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//? Declaramos las variables que usaremos mas adelante
#define Num_total 10
int numeros[Num_total];

int Myrandom(int _in, int _fin);
void imprimir(int _a[], int _long);
void ordenamiento_burbuja(void);

int main(void) 
{
    //? Para que lso numeros no salgan repetidos
    srand(time(NULL));

    //? Indica el rango de los numeros a generar
    int Rand_in = 1, Rand_fin = 100;
    

    //? Generamos 10 numeros aleatorios usando la funcion Myrandom
    printf("Los %d numeros aleatorios generados entre %d y %d son: \n", Num_total, Rand_in,  Rand_fin);
    for(int i = 0; i < Num_total; i ++) {
	    numeros[i] = ceil((int)Myrandom(Rand_in,  Rand_fin));
	}

    imprimir(numeros, Num_total);
    
    printf("\n");

    ordenamiento_burbuja();

    printf ("Los numeros ordenados son:\n");
    imprimir(numeros, Num_total);

    return 0;
}

int Myrandom(int _in, int _fin) {
    int y;
    y = _in + rand() % (_fin-_in);
    return y;
}

void imprimir(int _a[], int _long) {
    printf("(");
    for (int i = 0; i < _long; i++) {
    (i == _long-1) ? printf("%i)", _a[i]) : printf("%i, ", _a[i]);
    }
}

void ordenamiento_burbuja(void) {
    int pivote = 0;

    //? Definimos un for principal con una unidad menos del total de numeros pues
    //? estos son los pasos que este necesitara para ordenarlos
    for (int i = 0; i < (Num_total -1); i ++) {
        //? Aqui, el segundo for se encargara de ejecutar la misma cantidad de pasos que de numeros
        //? Definiendo a j una unidad adelante de i para que el programa lea el i-esimo numero
        //? y posterior mente lo compare con el (i+1)-esimo numero
        for (int j = i+1; j < Num_total; j ++) {
            //? Aqui se comparan ambos numeros, si el numero de la posicion i es mayor que el 
            //? numero de la posicion j (i+1) entonces se intercambian los numeros, ademas el
            //? segundo numero se guarda en la variable pivote para que despues el programa
            //? lo compare con el siguiente numero
            if (numeros[j] < numeros[i]) {
                pivote = numeros[j];
                numeros[j] = numeros[i];
                numeros[i] = pivote;
            }
        }
    }
}
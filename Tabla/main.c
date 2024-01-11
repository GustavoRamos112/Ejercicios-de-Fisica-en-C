#include <stdio.h>

//? Definimos el struct
struct elemento {
    int Norma;
    char Nomb[20];
    float Atomica, Densi;
    char Simbol[4];
//? Aniadimos un array para el almacenamiento de todos los valores
}atomo[118];

int main(void) {
    int i, Nadia;
    FILE *entrada;
    entrada = fopen("Datos.dat", "r");
    //? Le pedimos al ususario que introduzca el elemento que quiere saber
    printf("Teclea el numero de elemento: ");
    scanf("%d", &Nadia);

    //? Por si el ususario escribe un elmento no valido
    if (Nadia > 118 || Nadia < 1) {
        printf("Hata donde se, no existe ese elemento... aun");
        return 1;
    }
    //? Para no leer datos de mas, solo le decimos al ciclo que lea hasta el
    //? dato pedido por el usuario
    for (i = 1; i <= Nadia; i++) {
        //? Dado que el fscan() puede leer datos de corrido
        //? (sin saltos de linea), usamos esto para leer por linea
        //? los datos escritos en Datos.txt 
        fscanf(entrada, "%d %s %f %f %s", &atomo[i].Norma, atomo[i].Nomb, &atomo[i].Atomica, &atomo[i].Densi, atomo[i].Simbol);
    }

    //? Imprimimos los datos en un buen formato
    printf("El elemento con %d electrones es el %s:\n", atomo[Nadia].Norma, atomo[Nadia].Nomb);
    printf("Simbolo: %s\n", atomo[Nadia].Simbol);
    printf("Masa atomica: %lf g/mol\n", atomo[Nadia].Atomica);
    printf("Densidad: %lf g/cm^3\n", atomo[Nadia].Densi);
    fclose(entrada);

    return 0;
}

//? (Adi, Bdi) indican el rango de integracion y Ara, el resultaado numerico de esta misma

double Funcion(double x);

double Riemman_sup(double Adi, double Bdi, double Pasos) {
	double h, suma, Ara;
	
	suma = 0;
	h = (Bdi-Adi)/Pasos;

	for(int i = 0; i < Pasos; i++) {
        suma += Funcion(Adi+i*h);
    }
    Ara = h*suma;
	return Ara;
}

double Riemman_inf(double Adi, double Bdi, double Pasos) {
	double h, suma = 0, Ara;

	h = (Bdi-Adi)/Pasos;

	for(int i = 1; i <= Pasos; i++) {
        suma += Funcion(Adi+i*h);
    }

	Ara = h*suma;
	return Ara;
}

double Trapecio(double Adi, double Bdi, double Pasos) {
	double suma = 0, h, Ara;
	
	h = (Bdi-Adi)/Pasos;

	for (int i = 0; i <= Pasos; i++) {
        suma += Funcion(Adi+h*i)+Funcion(Adi+h*(i+1));
    }

    Ara = (h/2)*suma;
	return Ara;
}

double Simpson_1_3(double Adi, double Bdi, double Pasos) {
	int i;
	double suma = 0, suma_2 = 0, h, Ara;

	h = (Bdi-Adi)/Pasos;

    for (i = 1; i <= (Pasos/2-1); i++) {
        suma = 2*Funcion(Adi+2*i*h)+suma;
    }
	
    for (i = 1; i <= (Pasos/2); i++) {
        suma_2 = 4*Funcion(Adi+(2*i-1)*h)+suma_2;
    }

    Ara = (h/3)*(Funcion(Adi)+suma+suma_2+Funcion(Bdi));
    return Ara;
}

double Simpson_3_8(double Adi, double Bdi, double Pasos) {
    int i;
	double suma_1 = 0, suma_2 = 0, suma_3 = 0, h, Ara;

    h = (Bdi-Adi)/Pasos;

    for (i = 0; i <= (Pasos/3-1); i++) {
        suma_1 = 3*Funcion(Adi+((3*i+1)*h))+suma_1;
    }

    for (i = 0; i <= (Pasos/3-1); i++) {
        suma_2 = 3*Funcion(Adi+(3*i+2)*h)+suma_2;
    }

    for (i = 0; i <= (Pasos/3-2); i++) {
        suma_3 = 2*Funcion(Adi+(3*i+3)*h)+suma_3;
    }

    Ara = ((3*h)/8)*(Funcion(Adi)+suma_1+suma_2+suma_3+Funcion(Bdi));
    return Ara;
}
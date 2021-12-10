/*
Programa: Ej03.c
Descripción: Escriba una función que devuelva la estación del año que se ha leído del teclado. 
La función debe de ser del tipo declarado en el ejercicio 2.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>

enum estaciones{verano, otonio, invierno, primavera};
void eleccion(enum estaciones est);

int main()
{
    enum estaciones est;
    eleccion(est);
}

void eleccion(enum estaciones est)
{
    printf("Ingrese un numero del 0 al 3 para elegir su estacion del anio favorita: ");
    scanf("%d", &est);
    switch (est)
    {
    case verano:
        printf("Eligio verano.");
        break;
    case otonio:
        printf("Eligio otonio.");
        break;
    case invierno:
        printf("Eligio invierno.");
        break;
    case primavera:
        printf("Eligio primavera.");
        break;
    
    default:
        printf("Opcion incorrecta.");
        break;
    }
}
/*
Programa: Ej08.c
Descripción: Definir dos variables correspondientes a los dos tipos de datos 
declarados en el ejercicio anterior y asignarles un nombre.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>

struct alumno
{
    char nombre[30];
    char curso[10];
    unsigned int edad;
    char direccion[30];
    int notas[10];
};

struct profesor
{
    char nombre[30];
    char asignatura[15][5];
    char direccion[30];
};


int main()
{
    struct alumno alum1, alum2;
    struct profesor prof1, prof2;

}



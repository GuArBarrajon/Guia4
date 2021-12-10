/*
Programa: Ej07.c
Descripción: Declara un tipo de dato estructura para representar un alumno; los campos que tiene que tener son: nombre, 
curso, edad, dirección y notas de las 10 asignaturas. Declara otro tipo estructura para representar un profesor; 
los campos que debe tener son: nombre, asignaturas que imparte y dirección.
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

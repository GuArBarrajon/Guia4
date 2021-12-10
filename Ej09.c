/*
Programa: Ej09.c
Descripción: Escribe una función que devuelva un alumno cuyos datos se introducen por teclado.
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

struct alumno cargarAlumno();

int main()
{
    struct alumno alum1;
    alum1=cargarAlumno();
}

struct alumno cargarAlumno()
{
    struct alumno x;
    printf("Ingrese el nombre: ");
    gets(x.nombre);
    printf("Ingrese el curso: ");
    gets(x.curso);
    printf("Ingrese la edad: ");
    scanf("%d", &x.edad);
    fflush(stdin);
    printf("Ingrese la dirección: ");
    gets(x.direccion);
    for(int i=0; i<10; i++)
    {
        printf("Ingrese una nota: ");
        scanf("%d", &x.notas[i]);
    }
    fflush(stdin);
    return x;
}
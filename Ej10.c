/*
Programa: Ej10.c
Descripción: Escribe una función que tenga como entrada una estructura alumno, y escriba sus campos por pantalla.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>
#include<string.h>

struct alumno
{
    char nombre[30];
    char curso[10];
    unsigned int edad;
    char direccion[30];
    int notas[10];
};

struct alumno cargarAlumno();
void imprimirAlumno(struct alumno x);

int main()
{
    struct alumno alum1;
    alum1 = cargarAlumno();
    imprimirAlumno(alum1);
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
    printf("Ingrese la direccion: ");
    gets(x.direccion);
    for(int i=0; i<10; i++)
    {
        x.notas[i]=0;
    }
    for(int i=0; i<10; i++)
    {
        printf("Ingrese una nota: ");
        scanf("%d", &x.notas[i]);
    }
    fflush(stdin);
    return x;
}

void imprimirAlumno(struct alumno x)
{
    printf("Nombre: %s\n", x.nombre);
    printf("Curso: %s\n", x.curso);
    printf("Edad: %d\n", x.edad);
    printf("Direccion: %s\n", x.direccion);
    printf("Notas: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d - ", x.notas[i]);
    }
}
/*
Programa: Ej05.c
Descripción: Encuentra los errores del siguiente código.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>
struct fecha
    {
        int dia;
        int mes;
        int anyo;                          //declaracion de estructura fuera del main
        char mes2[];
    }ff;

void escribe(struct fecha f);

int main()
{
    ff.dia = 1;
    ff.mes = 1;
    ff.anyo = 2000;
    strcpy(ff.mes2, "ENERO");       //no se puede asignar una variable char con igual
    escribe(ff);
    return 1;
}

void escribe(struct fecha f)
{
    printf("%d, %d, %d, %s", ff.dia, ff.mes, ff.anyo, ff.mes2);
}
/*
Programa: Ej20.c
Descripción: A menudo, en el tratamiento de bases de datos es necesario unir los datos de dos bases distintas cuyos registros tienen la misma estructura. 
Para estudiar los aspectos involucrados en tal operación de mezcla de bases de datos, suponga que tiene dos arrays del tipo descrito en el 
ejercicio propuesto 1 y codifique el programa en C que los una en uno solo, eliminando los duplicados que puedan existir entre los dos.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>
#include<string.h>
#define TAM 5

struct hormiga
{
    int patas;                              //Estructura del ejercicio 1 sin lógica aparente
    char especie[41];
    float tiempo;
}colonia1[TAM], colonia2[TAM], colonia3[2*TAM];

void cargarStruct(struct hormiga x[]);
void imprimirStruct(struct hormiga x[]);
void copiarStruct(struct hormiga x1[], struct hormiga x2[], struct hormiga x3[]);

void main()
{
    
    cargarStruct(colonia1);
    cargarStruct(colonia2);
    
    printf("\nColonias de hormigas\n\nColonia 1:\n");
    imprimirStruct(colonia1);
    printf("\nColonia 2:\n");
    imprimirStruct(colonia2);
    printf("\nColonia 3:\n");
    copiarStruct(colonia1, colonia2, colonia3);
}

void cargarStruct(struct hormiga x[])
{
    printf("Carga de datos de la colonia de hormigas\n");
    for(int i=0; i<TAM; i++)
    {
        printf("Ingrese cantidad de patas: ");
        scanf("%d", &x[i].patas);
        fflush(stdin);
        printf("Ingrese la especie: ");
        gets(x[i].especie);
        printf("Ingrese el tiempo: ");
        scanf("%f", &x[i].tiempo);
        fflush(stdin);
    }
}

void imprimirStruct(struct hormiga x[])
{
    for(int i=0; i<TAM; i++)
    {
        puts("-------------------------------");
        printf("Patas: %d\n", x[i].patas);
        printf("Especie: %s\n", x[i].especie);
        printf("Tiempo: %0.2f\n", x[i].tiempo);
    }
}

void copiarStruct(struct hormiga x1[], struct hormiga x2[], struct hormiga x3[])
{
    for(int i=0; i<TAM; i++)
    {
        x3[i].patas=x1[i].patas;
        strcpy(x3[i].especie, x1[i].especie);     //copio primera estructura
        x3[i].tiempo=x1[i].tiempo;
    }

    for(int i=0; i<TAM; i++)
    {
        int bandera=0;
        for(int j=0; j<TAM; j++)
        {
            if(strcmp(x2[i].especie, x1[j].especie)==0)       //reviso si hay duplicados en especies
            {
                bandera=1;
            }
        }
        if(bandera==0)
        {
            x3[i+TAM].patas=x2[i].patas;
            strcpy(x3[i+TAM].especie, x2[i].especie);          //copio segunda estructura
            x3[i+TAM].tiempo=x2[i].tiempo;
        }
    }

    for(int i=0; i<2*TAM; i++)
    {
        if(strcmp(x3[i].especie, "")!=0)                        //Imprimo 3 estructura
        {
            puts("-------------------------------");
            printf("Patas: %d\n", x3[i].patas);
            printf("Especie: %s\n", x3[i].especie);
            printf("Tiempo: %0.2f\n", x3[i].tiempo);
        }
    }
}
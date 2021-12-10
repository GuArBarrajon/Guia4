/*
Programa: Ej15.c
Descripción:  Se quiere informatizar los resultados obtenidos por los equipos de baloncesto de Córdoba.
La información de cada equipo:
• Nombre del equipo.
• Número de victorias.
• Número de derrotas.
• Número de pérdidas de balón.
• Número de rebotes cogidos.
• Nombre del mejor anotador de triples.
• Número de triples del mejor triplista.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>
#include<string.h>
#define MAX 5

struct baloncesto
{
    char nombre[15];
    int victorias, derrotas, perdidas, rebotes;
    char anotadorTriples[25];
    int triples;
};

struct baloncesto cargarEquipo();
void imprimir(struct baloncesto x[]);

void main()
{
    struct baloncesto equipo[MAX];
    for(int i=0; i<MAX; i++)
    {
        equipo[i]=cargarEquipo();
    }
    printf("\nEstadisticas de la Liga de Baloncesto de Cordoba\n");
    imprimir(equipo);
}

struct baloncesto cargarEquipo()
{
    struct baloncesto equipo;
    printf("Equipo: ");
    gets(equipo.nombre);
    fflush(stdin);
    printf("Partidos ganados: ");
    scanf("%d", &equipo.victorias);
    printf("Partidos perdidos: ");
    scanf("%d", &equipo.derrotas);
    printf("Perdidas de pelota: ");
    scanf("%d", &equipo.perdidas);
    printf("Rebotes atrapados: ");
    scanf("%d", &equipo.rebotes);
    fflush(stdin);
    printf("Anotador de triples: ");
    gets(equipo.anotadorTriples);
    printf("Triples del mejor triplista: ");
    scanf("%d", &equipo.triples);
    fflush(stdin);
    return equipo;
}

void imprimir(struct baloncesto x[])
{
    for(int i=0; i<MAX; i++)
    {
        printf("\n");
        printf("Nombre del equipo: %s\n", x[i].nombre);
        printf("Partidos ganados: %d\n", x[i].victorias);
        printf("Partidos perdidos: %d\n", x[i].derrotas);
        printf("Perdidas de pelota: %d\n", x[i].perdidas);
        printf("Rebotes atrapados: %d\n", x[i].rebotes);
        printf("Anotador de triples: %s\n", x[i].anotadorTriples);
        printf("Triples del mejor triplista: %d\n", x[i].triples);
    }
}
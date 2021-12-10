/*
Programa: Ej16.c
Descripción:  Modificar el programa 15 para obtener los siguientes informes o datos.
• Listado de los mejores triplistas de cada equipo.
• Máximo goleador de la liga.
• Equipo ganador de la liga de baloncesto.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>
#include<string.h>
#include<limits.h>

#define EQUIP 4             //cantidad de equipos
#define FECHAS EQUIP-1      //cantidad de fechas del torneo

enum resultPartido {perdio, gano};

struct fecha
{
    enum resultPartido resultado;
    char golaeador[25];
    int goles;
    char anotadorTriples[25];
    int triples;
}fecha[FECHAS];

struct baloncesto
{
    char nombre[15];
    int victorias, derrotas, perdidas, rebotes;
    struct fecha fecha[FECHAS];
}equipo[EQUIP];

struct baloncesto cargarEquipo();
void imprimir(struct baloncesto x[]);
void mejorTriplista(struct baloncesto equipo[]);
void goleadorMax(struct baloncesto equipo[]);
void ganadorLiga(struct baloncesto equipo[]);

void main()
{
    for(int i=0; i<EQUIP; i++)
    {
        equipo[i]=cargarEquipo();
    }
    printf("\nLiga de Baloncesto de Cordoba\n");
    imprimir(equipo);
    printf("\nEstadisticas al finalizar el torneo\n");
    mejorTriplista(equipo);
    goleadorMax(equipo);
    ganadorLiga(equipo);
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
    
    
    for(int i=0; i<FECHAS; i++)
    {
        
        printf("Fecha %d\n", i+1);
        fflush(stdin);
        printf("Indique el resultado(0 = perdio/1 = gano): ");
        scanf("%d", &equipo.fecha[i].resultado);
        fflush(stdin);
        printf("Goleador de la fecha: ");
        gets(equipo.fecha[i].golaeador);
        printf("Cantidad de goles: ");
        scanf("%d", &equipo.fecha[i].goles);
        fflush(stdin);
        printf("Anotador de triples: ");
        gets(equipo.fecha[i].anotadorTriples);
        fflush(stdin);
        printf("Triples del mejor triplista: ");
        scanf("%d", &equipo.fecha[i].triples);
        fflush(stdin);
    }

    return equipo;
}

void imprimir(struct baloncesto x[])
{
    for(int i=0; i<EQUIP; i++)
    {
        printf("\n");
        printf("Nombre del equipo: %s\n", x[i].nombre);
        printf("Partidos ganados: %d\n", x[i].victorias);
        printf("Partidos perdidos: %d\n", x[i].derrotas);
        printf("Perdidas de pelota: %d\n", x[i].perdidas);
        printf("Rebotes atrapados: %d\n", x[i].rebotes);

        for(int j=0; j<FECHAS; j++)
        {
            puts("------------------------------------------");
            printf("Fecha %d\n", j+1);
            printf("Resultado: ");
            switch (x[i].fecha[j].resultado)
            {
            case 0:
                printf("perdio");
                break;
    
            case 1:
                printf("gano");
                break;
            }
            printf("\n");
            printf("Anotador de triples: %s\n", x[i].fecha[j].anotadorTriples);
            printf("Triples del mejor triplista: %d\n", x[i].fecha[j].triples);
            printf("Goleador de la fecha: %s\n", x[i].fecha[j].golaeador);
            printf("Goles: %d\n", x[i].fecha[j].goles);
        }    
    }
}

//Función mejor triplista del equipo
void mejorTriplista(struct baloncesto equipo[])
{
    char mejortriplis[25];
    int cantMaxtriples=INT_MIN;
    for(int i=0; i<EQUIP; i++)
    {
        for(int j=0; j<FECHAS; j++)
        {
            if(equipo[i].fecha[j].triples>cantMaxtriples)
            {
                cantMaxtriples=equipo[i].fecha[j].triples;
                strcpy(mejortriplis, equipo[i].fecha[j].anotadorTriples);
            }
        }
        printf("El mejor triplista del equipo %d es %s\n", i+1, mejortriplis);
        cantMaxtriples=INT_MIN;
    }
}

//Función goleador de la liga
void goleadorMax(struct baloncesto equipo[])
{
    char goleador[EQUIP][25];
    char goleadorMax[25];
    int cantMaxgoles=INT_MIN;


    //Comparación entre los goleadores de cada equipo para ver si se repiten y sumar goles
    for(int a=0; a<EQUIP; a++)
    {
        for(int b=0; b<FECHAS-1; b++)
        {
            for(int c=1; c<FECHAS; c++)
            {
                if(strcmp(equipo[a].fecha[b].golaeador, equipo[a].fecha[c].golaeador)==0)
                {
                    equipo[a].fecha[b].goles+=equipo[a].fecha[c].goles;
                }
            }
        }
    }

    //Determino el goleador máximo de cada equipo
    int golesMax[EQUIP];
    for(int i=0; i<EQUIP; i++)
    {
        for(int j=0; j<FECHAS; j++)
        {
            if(equipo[i].fecha[j].goles>cantMaxgoles)
            {
                cantMaxgoles=equipo[i].fecha[j].goles;
                strcpy(goleador[i], equipo[i].fecha[j].golaeador);
            }
        }
        golesMax[i]=cantMaxgoles;  
    }

    //Determino el goleador máximo de la liga
    cantMaxgoles=INT_MIN;
    for(int i=0; i<EQUIP; i++)
    {
        if(golesMax[i]>cantMaxgoles)
        {
            cantMaxgoles=golesMax[i];
            strcpy(goleadorMax, goleador[i]);
        }
    }
    printf("El goleador maximo de la liga es: %s\n", goleadorMax);
}

//Función ganador de la liga (podría haberla hecho con las victorias del ejercicio 15, pero lo hice sumando los partidos ganados por fecha)
void ganadorLiga(struct baloncesto equipo[])
{
    int cantidadGano[EQUIP];
    int campeon=0;
    char gano[25];
    for(int i=0; i<EQUIP; i++)
    {
        cantidadGano[i]=0;
    }

    for(int i=0; i<EQUIP; i++)
    {
        for(int j=0; j<FECHAS; j++)
        {
            if(equipo[i].fecha[j].resultado==1)
            {
                cantidadGano[i]++;
            }
        }
    }
    for(int i=0; i<EQUIP; i++)
    {
        if(cantidadGano[i]>campeon)
        {
            campeon=cantidadGano[i];
            strcpy(gano, equipo[i].nombre);
        }
    }
    printf("El ganador de la liga es: %s\n", gano);
}
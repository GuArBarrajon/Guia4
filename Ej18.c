/*
Programa: Ej18.c
Descripción: Escribir un programa que gestione una agenda de direcciones. 
Los datos de la agenda se almacenan en memoria en un array de estructuras, cada una de las cuales tiene los siguientes campos:
nombre
dirección
teléfono fijo
teléfono móvil
dirección de correo electrónico
El programa debe permitir añadir una nueva entrada a la agenda, borrar una entrada, 
buscar por nombre y eliminar una entrada determinada por el nombre.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>
#include<string.h>
#define MAX 10             // Cantidad de contactos de la agenda como constante

struct contacto
{
    char nombre[25], direccion[30], telFijo[10], telMovil[10], email[15];
}agenda[MAX];

struct contacto cargarContacto();
void buscarContacto(struct contacto cc[]);
void imprimirContacto(struct contacto cc);
struct contacto eliminarContacto();
struct contacto eliminarContPorNombre();

void main()
{
    int opcion, i=0;
    char continuar;
    do
    {
        printf("Ingrese:\n1. Agregar contactos\n2. Buscar contacto\n3. Eliminar contacto\n4. Eliminar contacto por nombre\n5. Salir de la agenda\n");
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion)
        {
        case 1:
            do
            {
                if(strcmp(agenda[i].nombre, "")==0)
                {
                    agenda[i]=cargarContacto();
                    i++;
                    printf("Desea continuar? (s/n) ");
                    scanf(" %c", &continuar);
                }
                
            } while (continuar=='s' && i<MAX);
            break;
    
        case 2:
            buscarContacto(agenda);
            break;

        case 3:
            eliminarContacto();
            break;

        case 4:
            eliminarContPorNombre();
            break;
        }
        puts("---------------------------------------------------------------------------");
        fflush(stdin);
    } while (opcion!=5);
}

struct contacto cargarContacto()
{
    struct contacto pers;
    fflush(stdin);
    printf("Datos de contacto:\n");
    printf("Nombre: ");
    gets(pers.nombre);
    printf("Direccion: ");
    gets(pers.direccion);
    printf("Telefono fijo: ");
    gets(pers.telFijo);
    printf("Celular: ");
    gets(pers.telMovil);
    printf("Email: ");
    gets(pers.email);
    
    return pers;
}

void buscarContacto(struct contacto cc[])
{
    char contact[20];
    int bandera=0;
    printf("Ingrese el nombre del contacto: ");

    gets(contact);
    for(int i=0; i<MAX; i++)
    {
        if(strcmp(cc[i].nombre, contact)==0)
        {
            imprimirContacto(cc[i]);
            bandera=1;
        }
    }
    if(bandera==0)
    {
        printf("No se encontro el contacto\n");
    }
}

void imprimirContacto(struct contacto cc)
{
    puts("--------------------------------------------------");
    printf("Contacto:\n");
    printf("Nombre: %s\n", cc.nombre);
    printf("Direccion: %s\n", cc.direccion);
    printf("Telefono fijo: %s\n", cc.telFijo);
    printf("Celular: %s\n", cc.telMovil);
    printf("Email: %s\n", cc.email);
}

struct contacto eliminarContacto()
{
    char option;
    int i;
    printf("Ingrese la posicion a eliminar de la agenda: ");
    scanf("%d", &i);
    if(strcmp(agenda[i].nombre, "")==0)
    {
        printf("La posicion ingresada esta vacia\n");
    }
    else
    {
        imprimirContacto(agenda[i]);
        printf("Esta seguro de eliminarlo? (s/n) ");
        scanf(" %c", &option);
        if(option=='s'|| option=='S')
        {
            strcpy(agenda[i].nombre, "");
            strcpy(agenda[i].direccion, "");
            strcpy(agenda[i].telFijo, "");
            strcpy(agenda[i].telMovil, "");
            strcpy(agenda[i].email, "");
            printf("El contacto fue eliminado\n");
        }
    }
    return agenda[MAX];
}

struct contacto eliminarContPorNombre()
{
    int i, bandera=0;
    char option;
    char name[25];
    printf("Ingrese el nombre del contacto a eliminar de la agenda: ");
    gets(name);

    for(i=0; i<MAX; i++)
    {
        if(strcmp(agenda[i].nombre, name)==0)
        {
            imprimirContacto(agenda[i]);
            printf("Esta seguro de eliminarlo? (s/n) ");
            scanf(" %c", &option);
            if(option=='s'|| option=='S')
            {
                strcpy(agenda[i].nombre, "");
                strcpy(agenda[i].direccion, "");
                strcpy(agenda[i].telFijo, "");
                strcpy(agenda[i].telMovil, "");
                strcpy(agenda[i].email, "");
                printf("El contacto fue eliminado\n");
            }
            bandera=1;
        }
    }

    if(bandera==0)
    {
        printf("No se encontro el contacto\n");
    }
    
    return agenda[MAX];
}
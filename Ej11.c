/*
Programa: Ej11.c
Descripción: Escribir un programa de facturación de clientes. Los clientes tienen un nombre, 
el número de unidades solicitadas, el precio de cada unidad y el estado en que se encuentra: moroso, atrasado, pagado. 
El programa debe generar los diversos clientes.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>
#define MAX 5                           //cantidad de clientes a ingresar

enum estado {moroso, atrasado, pagado};

struct cliente
{
    char nombre[30];
    int unidades;
    float precio;
    enum estado est;
};

struct cliente cargarCliente();
void imprimirCliente(struct cliente x[]);

int main()
{
    struct cliente client[MAX];
    for(int i=0; i<MAX; i++)
    {
        client[i] = cargarCliente();
    }
    imprimirCliente(client);
    return 0;
}

struct cliente cargarCliente()
{
    struct cliente x;
    printf("Ingrese el nombre: ");
    gets(x.nombre);
    printf("Ingrese las unidades: ");
    scanf("%d", &x.unidades);
    printf("Ingrese le precio: ");
    scanf("%f", &x.precio);
    fflush(stdin);
    printf("Ingrese el estado (0=moroso, 1=atrasado, 2=pagado): ");
    scanf("%d", &x.est);
    fflush(stdin);
    return x;
}

void imprimirCliente(struct cliente x[])
{
    printf("Listado de Clientes\n");
    for (int i = 0; i < MAX; i++)
    {
        puts("-------------------------------------------------");
        printf("Nombre: %s\n", x[i].nombre);
        printf("Unidades: %d\n", x[i].unidades);
        printf("Precio: %0.2f\n", x[i].precio);
        printf("Estado: ");
        switch (x[i].est)
        {
        case 0:
            printf("moroso");
            break;
    
        case 1:
            printf("atrasado");
            break;

        case 2:
            printf("pagado");
            break;
        }
        printf("\n");
    }
}
/*
Programa: Ej12.c
Descripción:  Modifique el programa de facturación de clientes de tal modo que se puedan obtener los siguientes listados.
• Clientes en estado moroso.
• Clientes en estado pagado con factura mayor de una determinada cantidad.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>
#include<string.h>
#define MAX 5

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
void morosos(struct cliente x[]);
void pago(struct cliente x[]);

int main()
{
    struct cliente client[MAX];
    for(int i=0; i<MAX; i++)
    {
        client[i] = cargarCliente();
    }

    int opcion;
    do
    {
        printf("\nIngrese:\n1. Imprimir lista de clientes.\n2. Imprimir clientes morosos.\n3. Imprimir clientes pagados.\n4. Salir.\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            imprimirCliente(client);
            break;
        
        case 2:
            morosos(client);
            break;
        
        case 3:
            pago(client);
            break;
        
        }
    } while (opcion!=4);
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
    for (int i = 0; i < MAX; i++)
    {
        puts("------------------------------------------------");
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

void morosos(struct cliente x[])
{
    printf("\nClientes morosos:\n");
    for (int i = 0; i < MAX; i++)
    {
        if(x[i].est==0)
        {
            printf("Nombre: %s\n", x[i].nombre);
            printf("Monto: %0.2f\n", x[i].precio*x[i].unidades);
        }
    }
}

void pago(struct cliente x[])
{
    int montoMin;
    printf("Ingrese el monto a partir del cual desea visualizar los clientes pagados: ");
    scanf("%d", &montoMin);
    printf("\nClientes en estado pagado con facturacion mayor a %d:\n", montoMin);
    for (int i = 0; i < MAX; i++)
    {
        if(x[i].est==2 && x[i].precio*x[i].unidades >= montoMin)
        {
            printf("Nombre: %s\n", x[i].nombre);
            printf("Monto: %0.2f\n", x[i].precio*x[i].unidades);
        }
    }
}
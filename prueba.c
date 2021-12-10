#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

enum estado {moroso, atrasado, pagado};

struct cliente
{
    char nombre[30];
    int unidades;
    float precio;
    enum estado est;
}client[MAX];

struct cliente listaExistente();
struct cliente cargarCliente();
void imprimirCliente(struct cliente x[]);
void morosos(struct cliente x[]);
void pago(struct cliente x[]);

int main()
{
    struct cliente client[MAX];
    listaExistente();
    int opcion, i=0;
    char continuar;
    
    do
    {
        printf("\nIngrese:\n1. Agregar clientes a lista existente.\n2. Imprimir lista de clientes.\n3. Imprimir clientes morosos.\n4. Imprimir clientes pagados.\n5. Salir.\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:

            do
            {
                if(strcmp(client[i].nombre, "")==0)
                {
                    client[i]=cargarCliente();
                    i++;
                    printf("Desea otro cliente? (s/n) ");
                    scanf(" %c", &continuar);
                }
                
            } while (continuar=='s' && i<MAX);
            break;
            /*fflush(stdin);
            for(int i=0; i<MAX; i++)
            {
                if(strcmp(client[i].nombre, "")==0)
                {
                    fflush(stdin);
                    client[i] = cargarCliente();
                }
                printf("Desea agregar otro cliente? (s/n) ");
                scanf(" %c", &continuar);
                if(continuar=='n' || continuar=='N')
                {
                    break;
                }
            } 
            
            break;*/

        case 2:
            imprimirCliente(client);
            break;
        
        case 3:
            morosos(client);
            break;
        
        case 4:
            pago(client);
            break;
        
        }
    } while (opcion!=5);
    return 0;
}

struct cliente listaExistente()
{
    struct cliente client1={"Roberto", 10, 100, 0};
    struct cliente client2={"Ana", 10, 100, 1};
    struct cliente client3={"Pedro", 10, 100, 2};
    client[0]=client1;
    client[1]=client2;
    client[2]=client3;

    return client[MAX];
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
        if(strcmp(x[i].nombre, "")!=0)
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
}

void morosos(struct cliente x[])
{
    printf("\nClientes morosos:\n");
    for (int i = 0; i < MAX; i++)
    {
        if(x[i].est==0 && strcmp(x[i].nombre, "")!=0)
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
        if(x[i].est==2 && x[i].precio*x[i].unidades >= montoMin && strcmp(x[i].nombre, "")!=0)
        {
            printf("Nombre: %s\n", x[i].nombre);
            printf("Monto: %0.2f\n", x[i].precio*x[i].unidades);
        }
    }
}
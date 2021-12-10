/*
Programa: Ej17.c
Descripción: Un punto en el plano se puede representar mediante una estructura con dos campos. Escribir un programa que realice las siguientes operaciones con puntos en el plano.
• Dados dos puntos calcular la distancia entre ellos.
• Dados dos puntos determinar el punto medio de la línea que los une.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>
#include<math.h>

struct punto
{
    float x, y;
};

struct punto cargarPunto();
void calcularDistancia(struct punto p1, struct punto p2);
void calcularPuntoMedio(struct punto p1, struct punto p2);

void main()
{
    struct punto punto1, punto2;
    punto1=cargarPunto();
    punto2=cargarPunto();
    calcularDistancia(punto1, punto2);
    calcularPuntoMedio(punto1, punto2);
}

struct punto cargarPunto()
{
    struct punto p;
    printf("Ingrese la coordenada x: ");
    scanf("%f", &p.x);
    printf("Ingrese la coordenada y: ");
    scanf("%f", &p.y);
    return p;
}

void calcularDistancia(struct punto p1, struct punto p2)
{
    double distancia = sqrt((p2.x*p2.x-2*p1.x*p2.x+p1.x*p1.x)+(p2.y*p2.y-2*p1.y*p2.y+p1.y*p1.y));
    printf("La distancia entre los dos puntos ingresados es: %0.2f\n", distancia);
}

void calcularPuntoMedio(struct punto p1, struct punto p2)
{
    float x, y;
    x=(p1.x+p2.x)/2;
    y=(p1.y+p2.y)/2;
    printf("El punto medio entre los puntos ingresados es: (%0.2f, %0.2f)\n", x, y);
}
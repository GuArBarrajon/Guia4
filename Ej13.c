/*
Programa: Ej13.c
Descripción:  Escribir un programa que permita hacer las operaciones de suma, resta y multiplicación de números complejos. 
El tipo complejo ha de definirse como una estructura.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>

struct complejo
{
    int real, imaginaria;
};

struct complejo cargarNum();
void operacion (struct complejo num1, struct complejo num2);

void main()
{
    struct complejo z1, z2;
    z1=cargarNum();
    z2=cargarNum();
    operacion(z1, z2);    
}

struct complejo cargarNum()
{
    struct complejo z;
    printf("Ingrese la parte real del numero: ");
    scanf("%d", &z.real);
    printf("Ingrese la parte imaginaria del numero: ");
    scanf("%d", &z.imaginaria);
    return z;
}

void operacion (struct complejo num1, struct complejo num2)
{
    char operacion;
    int r1, r2, r3, r4, r5, r6;
    printf("Indique la operacion (+ - *) ");
    scanf(" %c", &operacion);
    switch (operacion)
    {
    case '+':
        printf("%d %di + %d %di = %d %di", num1.real, num1.imaginaria, num2.real, num2.imaginaria, num1.real+num2.real, num1.imaginaria+num2.imaginaria);
        break;
    
    case '-':
        printf("%d %di - %d %di = %d %di", num1.real, num1.imaginaria, num2.real, num2.imaginaria, num1.real-num2.real, num1.imaginaria-num2.imaginaria);
        break;
    
    case '*':
        r1= num1.real*num2.real;
        r2= num1.real*num2.imaginaria;
        r3= num1.imaginaria*num2.real;
        r4= num1.imaginaria*num2.imaginaria*(-1);
        r5= r1+r4;
        r6= r2+r3;
        printf("%d %di x %d %di = %d %di", num1.real, num1.imaginaria, num2.real, num2.imaginaria, r5, r6);
        break;
    
    
    default:
        printf("La operacion ingresada no es valida\n");
        break;
    }
}
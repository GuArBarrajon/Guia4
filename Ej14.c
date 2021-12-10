/*
Programa: Ej14.c
Descripción:  Un número racional se caracteriza por el numerador y denominador. Escriba un programa para operar con números racionales. 
Las operaciones a definir son la suma, resta, multiplicación y división; además de una función para simplificar cada número racional.
Autor: Gustavo Barrajón
Modificó:
*/

#include<stdio.h>

struct fraccion
{
    int numerador, denominador;
};

struct fraccion cargarNum();
void operacion (struct fraccion num1, struct fraccion num2);
void simplificar(struct fraccion f);

void main()
{
    struct fraccion n1, n2;
    n1=cargarNum();
    n2=cargarNum();
    operacion(n1, n2);    
}

struct fraccion cargarNum()
{
    struct fraccion f;
    printf("Ingrese el numerador de la fraccion: ");
    scanf("%d", &f.numerador);
    printf("Ingrese el denominador de la fraccion: ");
    scanf("%d", &f.denominador);
    return f;
}

void operacion (struct fraccion num1, struct fraccion num2)
{
    struct fraccion result;
    char operacion;
    printf("Indique la operacion (+ - * /) ");
    scanf(" %c", &operacion);
    switch (operacion)
    {
    case '+':
        if(num1.denominador==num2.denominador)
        {
            result.numerador=num1.numerador+num2.numerador;
            result.denominador=num1.denominador;
        }
        else
        {
            result.denominador=num1.denominador*num2.denominador;
            result.numerador=(result.denominador/num1.denominador)*num1.numerador+(result.denominador/num2.denominador)*num2.numerador;
        }
        printf("%d/%d + %d/%d = ", num1.numerador, num1.denominador, num2.numerador, num2.denominador);
        simplificar(result);
        break;
    
    case '-':
        if(num1.denominador==num2.denominador)
        {
            result.numerador=num1.numerador-num2.numerador;
            result.denominador=num1.denominador;
        }
        else
        {
            result.denominador=num1.denominador*num2.denominador;
            result.numerador=(result.denominador/num1.denominador)*num1.numerador-(result.denominador/num2.denominador)*num2.numerador;
        }
        printf("%d/%d - %d/%d = ", num1.numerador, num1.denominador, num2.numerador, num2.denominador);
        simplificar(result);
        break;
    
    case '*':
        result.numerador=num1.numerador*num2.numerador;
        result.denominador=num1.denominador*num2.denominador;
        
        printf("%d/%d x %d/%d = ", num1.numerador, num1.denominador, num2.numerador, num2.denominador);
        simplificar(result);
        break;
    
    case '/':
        result.numerador=num1.numerador*num2.denominador;
        result.denominador=num1.denominador*num2.numerador;
        
        printf("%d/%d / %d/%d = ", num1.numerador, num1.denominador, num2.numerador, num2.denominador);
        simplificar(result);
        break;
    
    default:
        printf("La operacion ingresada no es valida\n");
        break;
    }
}


void simplificar(struct fraccion f)
{
    for (;;)
    {
        if(f.numerador%2==0 && f.denominador%2==0)
        {
            f.numerador=f.numerador/2;
            f.denominador=f.denominador/2;
        }
        else
        {
            if(f.numerador%3==0 && f.denominador%3==0)
            {
                f.numerador=f.numerador/3;
                f.denominador=f.denominador/3;
            }
            else 
            {
                if(f.numerador%5==0 && f.denominador%5==0)
                {
                    f.numerador=f.numerador/5;
                    f.denominador=f.denominador/5;
                }
                else
                {
                    if(f.numerador%7==0 && f.denominador%7==0)
                    {
                    f.numerador=f.numerador/7;
                    f.denominador=f.denominador/7;
                    }
                    else 
                    {
                        if(f.numerador%10==0 && f.denominador%10==0)
                        {
                            f.numerador=f.numerador/10;
                            f.denominador=f.denominador/10;
                        }
                        else
                        {
                            if(f.numerador%11==0 && f.denominador%11==0)
                            {
                                f.numerador=f.numerador/11;
                                f.denominador=f.denominador/11;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d/%d", f.numerador, f.denominador);
}
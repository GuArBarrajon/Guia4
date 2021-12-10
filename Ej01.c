/*
Programa: Ej01.c
Descripción: Encuentre los errores en la siguiente declaración de estructura y posterior definición de variable.
Autor: Gustavo Barrajón
Modificó:*/



struct hormiga
{
int patas;
char especie[41];
float tiempo;
};
struct hormiga colonia[100];   //falta la palabra reservada struct en la declaracion de variables
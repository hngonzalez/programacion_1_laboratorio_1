#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prototipos.h"

/**
 * Muestra un mensaje por pantalla y solicita un valor entero al usuario
 * @param array msg el texto para mostrar al usuario de lo que se le pide
 * @return valor entero ingresado por usuario
 */
 int utn_getInt (char msg[])
 {
    int aux;
    printf("%s",msg);
    scanf("%d",&aux);
    return aux;
 }






/**
 * Verifico si la cadena de caracteres recibida son letras
 * @param cadena a verificar
 * @return (0) si son letras | (1) si no lo es
 */
int utn_isLetter(char* cadena)
{
    int i=0;
    while (cadena[i] != '\0')
    {
        if ((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            return 0;
        }
    i++;
    }
    return 1;
}







/**
 * Obtengo una cadena de caracteres
 * @param msg muestra un mensaje por consola
 * @param input puntero a donde se guardará la cadena
 * @return
 */
void utn_getString(char* msg, char* input)
{
    printf(msg);
    scanf("%s", input);
}







/**
 *  Obtiene una cadena de caracteres con letras
 * @param msg muestra un mensaje por consola
 * @param input puntero a donde se guardará la cadena
 * @return
 */
int utn_getStringLetter(char* msg, char* input)
{
    int retorno;
    char aux[256];
    do
    {
        utn_getString(msg, aux);
        if (utn_isLetter(aux))
        {
            strcpy(input,aux);
            retorno=1;
        }
        else
        {
            retorno=0;
            printf("\n   *Ingrese solo letras* \n");
        }
    } while (retorno != 1);

    return retorno;
}







/**
 * Muestra un mensaje por pantalla y solicita un valor flotante al usuario
 * @param array msg el texto para mostrar al usuario de lo que se le pide
 * @return valor flotante ingresado por usuario
 */
float utn_getFloat (char* msg)
 {
    float aux;
    printf("%s",msg);
    scanf("%f",&aux);
    fflush(stdin);
    return aux;
 }

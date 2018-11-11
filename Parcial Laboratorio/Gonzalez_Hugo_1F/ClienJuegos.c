#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prototipos.h"


/**
 *  Inicializo los array asignando al flag isEmpty 1 (es vacío)
 * @param arrayCliente array de clientes
 * @param arrayJuegos array de juegos
 * @param arrayAlquiler array de alquileres
 * @param cantElementClientes cantidad de elementos que tiene el array de clientes
 * @param cantElementJuegos cantidad de elementos que tiene el array de juegos
 * @param cantAlquileres cantidad de elementos que tiene el array de alquileres
 * @return (0) si se pudo inicializar | (-1) si no se pudo realizar
 */
int initArray (tCliente* arrayCliente, tJuegos* arrayJuegos, tAlquileres* arrayAlquiler, int cantElementClientes, int cantElementJuegos, int cantAlquileres)
{
    int i;
    int retorno=-1;
    for(i=0;i<cantElementClientes;i++)
    {
        arrayCliente[i].isEmpty=1;
        retorno=0;
    }

    for(i=0;i<cantElementJuegos;i++)
    {
        arrayJuegos[i].isEmpty=1;
        retorno=0;
    }

    for(i=0;i<cantAlquileres;i++)
    {
        arrayAlquiler[i].isEmpty=1;
        retorno=0;
    }

    return retorno;
}






 /**
 * Obtener un espacio libre (posición) en el array
 * @param   array de clientes
 * @param   cantidadElementos cantidad de elementos que tiene el array
 * @return  devuelve indice/posición en donde hay lugar | (-1) si no hay más espacios disponibles
 */
int obtenerEspacioLibre(tCliente* array, int cantidadElementos)
{
    int i;
    int retorno = -1;
    for (i=0;i<cantidadElementos;i++)
    {
        if(array[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }
    if(retorno == -1 ){
            printf("* No hay mas espacios disponibles *");
    }

    return retorno;
}






/**
 * Obtener un espacio libre (posición) en el array
 * @param   array de empleados
 * @param   cantidadElementos cantidad de elementos que tiene el array
 * @return (-1) si no hay lugar |  devuelve indice/posición en donde hay lugar
 */
int obtenerEspacioLibreJuego (tJuegos* array, int cantidadElementos)
{
    int i;
    int retorno = -1;
    for (i=0;i<cantidadElementos;i++)
    {
        if(array[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }
    if(retorno == -1 ){
            printf("* No hay mas espacios disponibles *");
    }

    return retorno;
}







/**
 *
 * @param
 * @param
 * @param
 * @return
 */
/*int assignId (tCliente* array, int cantidadElementos, int searchID)
{
    int i;
    int retorno=-1;


    for (i=0;i<cantidadElementos;i++)
    {
        if (array[i].isEmpty == 1)
        {

        }
        if (array[i].isEmpty == 0)
        {

        }
    }


    return retorno;
}*/









/**
 * Muestro msj de solicitud de datos de cliente y los agrego al array correspondiente
 * @param array es el array de clientes
 * @param cantidadElementos cantidad de clientes
 * @param auxID auxiliar para asignar un ID como contador
 * @param auxName auxiliar para el nombre
 * @param auxlastName auxiliar para el apellido
 * @param auxDomicilio auxiliar para el domicilio
 * @param auxTelefono auxiliar para el telefono
 * @param indiceDeEspacioLibre indice del array en donde hay espacio para cargar el nuevo dato
 * @return (0) si se cargó correctamente | (-1) si hubo error en la carga
 */
int altaCliente (tCliente* array, int cantidadElementos,
                 int auxID, char* auxNombre, char* auxApellido,
                 char* auxDomicilio, int auxTelefono)
{
    int indiceDeEspacioLibre;
    indiceDeEspacioLibre=obtenerEspacioLibre(array, cantidadElementos);

    if (array[indiceDeEspacioLibre].isEmpty == 1)
    {
        array[indiceDeEspacioLibre].isEmpty=0;
        array[indiceDeEspacioLibre].idCliente=auxID;

        utn_getStringLetter("\n    Nombre: ", auxNombre);
        strcpy(array[indiceDeEspacioLibre].nombre,auxNombre);
        strlwr(array[indiceDeEspacioLibre].nombre);
        array[indiceDeEspacioLibre].nombre[0]=toupper(array[indiceDeEspacioLibre].nombre[0]);

        utn_getStringLetter("    Apellido: ", auxApellido);
        strcpy(array[indiceDeEspacioLibre].apellido,auxApellido);
        strlwr(array[indiceDeEspacioLibre].apellido);
        array[indiceDeEspacioLibre].apellido[0]=toupper(array[indiceDeEspacioLibre].apellido[0]);

        utn_getStringLetter("    Domicilio: ", auxDomicilio);
        strcpy(array[indiceDeEspacioLibre].domicilio,auxDomicilio);
        strlwr(array[indiceDeEspacioLibre].domicilio);
        array[indiceDeEspacioLibre].domicilio[0]=toupper(array[indiceDeEspacioLibre].domicilio[0]);

        auxTelefono=utn_getInt("    Telefono: ");
        array[indiceDeEspacioLibre].telefono=auxTelefono;

        system("cls");
        printf(" * CARGA EXITOSA *");
        return 0;
    }

    return -1;
}








/**
 * Muestro msj de solicitud de datos del juego y los agrego al array correspondiente
 * @param array es el array de juegos
 * @param cantidadElementos es la cantidad juegos
 * @param auxIdJuegos es el auxiliar para ID
 * @param auxDescripcion es el auxiliar para la descripcion
 * @param auxImporte es el auxiliar para el importe
 * @return (0) si se pudo hacer la carga | (-1) si no se pudo
 */
int altaJuegos (tJuegos* array, int cantidadElementos, int auxIdJuegos,
                char* auxDescripcion, float auxImporte)
{
    int indiceDeEspacioLibre;
    int retorno = -1;
    indiceDeEspacioLibre=obtenerEspacioLibreJuego(array, cantidadElementos);

    if (array[indiceDeEspacioLibre].isEmpty == 1)
    {
        array[indiceDeEspacioLibre].isEmpty=0;
        array[indiceDeEspacioLibre].idJuego=auxIdJuegos;

        utn_getStringLetter("\n    Descripcion: ", auxDescripcion);
        strcpy(array[indiceDeEspacioLibre].descripJuego,auxDescripcion);
        strlwr(array[indiceDeEspacioLibre].descripJuego);
        array[indiceDeEspacioLibre].descripJuego[0]=toupper(array[indiceDeEspacioLibre].descripJuego[0]);

        auxImporte=utn_getFloat("    Importe: ");
        array[indiceDeEspacioLibre].importeJuego=auxImporte;

        system("cls");
        printf(" * CARGA EXITOSA *");
        retorno = 0;
    }

    return retorno;
}








/**
 *
 * @param
 * @param
 * @return (-1) si hubo error en la carga | (0) si se cargó correctamente
 */
int altaAlquiler (tCliente* clientes,tJuegos* juegos, tAlquileres* alquiler,
                  int cantidadElementos, int cantElementClientes, int cantElementJuegos,
                  int auxIdAlquiler)
{
    int retorno = -1;
    int i;
    int searchIDCliente;
    int searchIDJuego;
    int indiceDeEspacioLibre;

    indiceDeEspacioLibre=obtenerEspacioLibreJuego(alquiler, cantidadElementos);

    searchIDCliente = utn_getInt("\n\n  Ingrese ID del cliente: ");

    searchIDJuego = utn_getInt("\n\n  Ingrese ID del juego: ");

    if (alquiler[indiceDeEspacioLibre].isEmpty == 1)
    {
        alquiler[indiceDeEspacioLibre].isEmpty = 0;
        alquiler[indiceDeEspacioLibre].codAlquiler = auxIdAlquiler;

        for (i=0;i<cantElementClientes;i++)
        {
            if (clientes[i].idCliente == searchIDCliente)
            {
                alquiler[indiceDeEspacioLibre].codCliente = clientes[i].idCliente;
            }
        }
        for (i=0;i<cantElementJuegos;i++)
        {
            if (juegos[i].idJuego == searchIDJuego)
            {
                alquiler[indiceDeEspacioLibre].codJuego = juegos[i].idJuego;
            }
        }

    alquiler[indiceDeEspacioLibre].fecha = utn_getInt("\n\n  Fecha de alquiler (formato DMXX): ");

    retorno = 0;

    }

    return retorno;
}









/**
 * Localiza la posición del array en donde coincide el ID
 * @param array es array de clientes tipo tCliente
 * @param cantidadElementos cantidad de empleados
 * @return (i) posición del ID encontrado | (-1) si no se pudo encontrar el ID
 */
int encontrarPorId (tCliente* array, int cantidadElementos, int searchID)
{
    int i;
    int retorno;

        searchID = utn_getInt("\n\n  Ingrese ID del cliente: ");

        if (searchID > 0 && searchID <= 1000)
        {
            for (i=0;i<cantidadElementos;i++)
            {
                if(array[i].idCliente == searchID)
                {
                    retorno = i;
                    break;
                }
            }
        }
        else
        {
            retorno = -1;
        }

    return retorno;
}



/**
 * Localiza la posición del array en donde coincide el ID
 * @param array es array de juegos de tipo tJuegos
 * @param cantidadElementos cantidad de juegos
 * @param searchID auxiliar para asignar un ID como contador
 * @return retorna (i) posición del ID encontrado | (-1) si no se pudo encontrar el ID
 */
int encontrarPorIdJuegos (tJuegos* array, int cantidadElementos, int searchID)
{
    int i;
    int retorno;

        searchID = utn_getInt("\n\n  Ingrese ID del juego: ");

        if (searchID > 0 && searchID <= 1000)
        {
            for (i=0;i<cantidadElementos;i++)
            {
                if(array[i].idJuego == searchID)
                {
                    retorno = i;
                    break;
                }
                else
                {
                    retorno = -1;
                    break;
                }

            }
        }

    return retorno;
}





/**
 * Modifica el array de empleados de un ID en específico según datos ingresados por el usuario
 * @param array es array de empleados de tipo Employee
 * @param indiceParaModificar el indice del array con el que coincide el ID
 * @return campos modificados
 */
int editCliente (tCliente* array, int indiceParaModificar)
{
    char auxNombre[51];
    char auxApellido[51];
    char auxDomicilio[51];
    int auxTelefono;
    int option;
    int retorno=-1;

    if (indiceParaModificar != -1)
    {
        option=utn_getInt("\n\n Por favor, indique el campo a modificar: \n            1)Apellido\n            2)Nombre\n            3)Domicilio\n            4)Telefono\n\n          Opcion: ");

        switch (option)
        {
        case 1:
            utn_getStringLetter("    Apellido: ", auxApellido);
            strcpy(array[indiceParaModificar].apellido,auxApellido);
            strlwr(array[indiceParaModificar].apellido);
            array[indiceParaModificar].apellido[0]=toupper(array[indiceParaModificar].apellido[0]);
            break;
        case 2:
            utn_getStringLetter("\n    Nombre: ", auxNombre);
            strcpy(array[indiceParaModificar].nombre,auxNombre);
            strlwr(array[indiceParaModificar].nombre);
            array[indiceParaModificar].nombre[0]=toupper(array[indiceParaModificar].nombre[0]);
            break;
        case 3:
            utn_getStringLetter("    Domicilio: ", auxDomicilio);
            strcpy(array[indiceParaModificar].domicilio,auxDomicilio);
            strlwr(array[indiceParaModificar].domicilio);
            array[indiceParaModificar].domicilio[0]=toupper(array[indiceParaModificar].domicilio[0]);
            break;
        case 4:
            auxTelefono=utn_getInt("    Telefono: ");
            array[indiceParaModificar].telefono=auxTelefono;
            break;
        default:
            printf("  OPCION INCORRECTA - REINTENTE");
            break;
        }
        retorno = 0;
        system("cls");
        printf(" * CLIENTE MODIFICADO *");
    }
    else
    {
        system("cls");
        printf(" * ID INEXISTENTE *");
    }
    return retorno;
}





/**
 * Modifica el array de empleados de un ID en específico según datos ingresados por el usuario
 * @param array es array de empleados de tipo Employee
 * @param indiceParaModificar el indice del array con el que coincide el ID
 * @return campos modificados
 */
int editJuegos (tJuegos* array, int indiceParaModificar)
{
    char auxDescripcion[51];
    float auxImporte;
    int option;
    int retorno=-1;

    if (indiceParaModificar != -1)
    {
        option=utn_getInt("\n\n Por favor, indique el campo a modificar: \n            1)Descripcion\n            2)Importe\n\n          Opcion: ");

        switch (option)
        {
        case 1:
            utn_getStringLetter("    Descripcion: ", auxDescripcion);
            strcpy(array[indiceParaModificar].descripJuego,auxDescripcion);
            strlwr(array[indiceParaModificar].descripJuego);
            array[indiceParaModificar].descripJuego[0]=toupper(array[indiceParaModificar].descripJuego[0]);
            break;
        case 2:
            auxImporte=utn_getFloat("    Importe: ");
            array[indiceParaModificar].importeJuego=auxImporte;
            break;
        default:
            printf("  OPCION INCORRECTA - REINTENTE");
            break;
        }
        retorno = 0;
        system("cls");
        printf(" * JUEGO MODIFICADO *");
    }
    else
    {
        system("cls");
        printf(" * ID INEXISTENTE *");
    }
    return retorno;
}







/**
 *
 * @param
 * @param
 * @param
 * @return
 */
int removeCliente (tCliente* array, int cantidadElementos, int searchID)
{
    int i;
    int retorno=-1;

    searchID = utn_getInt("\n\n  Ingrese ID del cliente: ");

    if (searchID > 0 && searchID <= 1000)
    {
        for (i=0;i<cantidadElementos;i++)
        {
            if(array[i].idCliente == searchID)
            {
                array[i].isEmpty=1;
                retorno = 0;
                system("cls");
                printf(" * EMPLEADO ELIMINADO *");
                break;
            }
            else
            {
                system("cls");
                printf(" * ID INEXISTENTE *");
            }
        }
    }


    return retorno;
}






/**
 *
 * @param
 * @param
 * @param
 * @return
 */
int removeJuego (tJuegos* array,int cantidadElementos, int searchID)
{
    int i;
    int retorno=-1;

    searchID = utn_getInt("\n\n  Ingrese ID del juego: ");

    if (searchID > 0 && searchID <= 1000)
    {
        for (i=0;i<cantidadElementos;i++)
        {
            if(array[i].idJuego == searchID)
            {
                array[i].isEmpty=1;
                retorno = 0;
                system("cls");
                printf(" * JUEGO ELIMINADO *");
                break;
            }
            else
            {
                system("cls");
                printf(" * ID INEXISTENTE *");
            }
        }
    }


    return retorno;
}




/**
 * Ordenado por apellido del array de clientes
 * @param array de clientes de tipo tCliente
 * @param cantidadElementos cantidad de elementos del array
 * @return (0) si se pudo realizar, (-1) en caso de que no
 */
int ordenamientoJuegos (tJuegos* array, int cantidadElementos)
{
    tJuegos auxArray[cantidadElementos];
    int i;
    int j;
    int order;
    int retorno = -1;


    order=utn_getInt("\n\n Indique el modo de ordenamiento por ID: \n            1)Ascendente\n            0)Descendente\n");

    system("cls");
    for(i=0; i<cantidadElementos;i++)  // Inicializo para recorrer al array en la posición i
    {
        if (array[i].isEmpty == 0) // Recorro solo los isEmpty en 0 (campo ocupado)
        {
            for(j=i+1; j<cantidadElementos;j++) // Recorro la pos i + 1 para hacer las comparaciones
            {
                if (array[i].idJuego > array[j].idJuego && order == 1) // VERIFICO PARA ORDENAR ASCENDENTE
                {
                    *auxArray=array[i];
                    array[i]=array[j];
                    array[j]=*auxArray;
                    retorno=0;
                }
                if (array[j].idJuego > array[i].idJuego && order == 0) // VERIFICO PARA ORDENAR DESCENDENTE
                {
                        *auxArray=array[j];
                        array[j]=array[i];
                        array[i]=*auxArray;
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}








/**
 * Ordenado por apellido del array de clientes
 * @param array de clientes de tipo tCliente
 * @param cantidadElementos cantidad de elementos del array
 * @return (0) si se pudo realizar, (-1) en caso de que no
 */
int ordenamientoClientes (tCliente* array, int cantidadElementos)
{
    tCliente auxArray[cantidadElementos];
    int i;
    int j;
    int order;
    int retorno = -1;


    order=utn_getInt("\n\n Indique el modo de ordenamiento por Apellido: \n            1)Ascendente\n            0)Descendente\n");

    system("cls");
    for(i=0; i<cantidadElementos;i++)  // Inicializo para recorrer al array en la posición i
    {
        if (array[i].isEmpty == 0) // Recorro solo los isEmpty en 0 (campo ocupado)
        {
            for(j=i+1; j<cantidadElementos;j++) // Recorro la pos i + 1 para hacer las comparaciones
            {
                if ((strcmp(array[i].apellido,array[j].apellido)>0) && order == 1) // VERIFICO PARA ORDENAR ASCENDENTE
                {
                    *auxArray=array[i];
                    array[i]=array[j];
                    array[j]=*auxArray;
                    retorno=0;
                }
                if (strcmp(array[i].apellido,array[j].apellido)==0 && order == 1)
                {
                    if(strcmp(array[i].nombre,array[j].nombre)>0)
                    {
                        *auxArray=array[i];
                        array[i]=array[j];
                        array[j]=*auxArray;
                        retorno=0;
                    }
                    if(strcmp(array[i].nombre,array[j].nombre)==0)
                    {
                        *auxArray=array[i];
                        array[i]=array[j];
                        array[j]=*auxArray;
                        retorno=0;
                    }
                    retorno=0;
                }
                if ((strcmp(array[j].apellido,array[i].apellido)>0) && order == 0) // VERIFICO PARA ORDENAR DESCENDENTE
                {
                        *auxArray=array[j];
                        array[j]=array[i];
                        array[i]=*auxArray;
                        retorno=0;
                }
                if (strcmp(array[j].apellido, array[i].apellido)==0  && order == 0)
                {
                    if(strcmp(array[i].nombre,array[j].nombre)>0)
                    {
                        *auxArray=array[j];
                        array[j]=array[i];
                        array[i]=*auxArray;
                        retorno=0;
                    }
                    if(strcmp(array[i].nombre,array[j].nombre)==0)
                    {
                        *auxArray=array[j];
                        array[j]=array[i];
                        array[i]=*auxArray;
                        retorno=0;
                    }
                    retorno=0;
                }

            }
        }
    }
    return retorno;
}







/**
 *
 * @param
 * @return
 */
int listarClientes (tCliente* array, int cantidadElementos, int contadorCargas)
{
    int i;

    if (contadorCargas !=0)
    {
        ordenamientoClientes(array, cantidadElementos);

        printf("\n ---------- Listar ----------\n");

        for (i=0;i<cantidadElementos;i++)
        {
            if (array[i].isEmpty==0)
            {
                printf("    o ID%03d  %s, %s\n", array[i].idCliente, array[i].apellido, array[i].nombre);
            }
        }
        printf(" ----------------------------\n");
     }
    if (contadorCargas==0)
    {
        printf("\n ---------- Listar ----------\n");
        printf(" NO EXISTEN DATOS PARA MOSTRAR\n");
        printf(" ----------------------------\n");

    }
    return 0;
}




/**
 *
 * @param
 * @return
 */
int listarJuegos (tJuegos* array, int cantidadElementos, int contCargasJuegos)
{
    int i;

    if (contCargasJuegos !=0)
    {

        ordenamientoJuegos(array, cantidadElementos);

        printf("\n ---------- Listar ----------\n");

        for (i=0;i<cantidadElementos;i++)
        {
            if (array[i].isEmpty==0)
            {
                printf("    o ID%03d - %s  $%.2f\n", array[i].idJuego, array[i].descripJuego, array[i].importeJuego);
            }
        }
        printf(" ----------------------------\n");
    }
    if (contCargasJuegos == 0)
    {
        printf("\n ---------- Listar ----------\n");
        printf(" NO EXISTEN DATOS PARA MOSTRAR\n");
        printf(" ----------------------------\n");
    }

    return 0;
}


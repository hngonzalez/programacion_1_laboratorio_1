#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "ClienJuegos.h"
#include "input.h"
#define CANT_CLIENTES 5
#define CANT_JUEGOS 5
#define CANT_CyJ  CANT_CLIENTES*CANT_JUEGOS


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
 * Obtener un espacio libre (posición) en el array
 * @param   array de empleados
 * @param   cantidadElementos cantidad de elementos que tiene el array
 * @return (-1) si no hay lugar |  devuelve indice/posición en donde hay lugar
 */
int obtenerEspacioLibreAlquiler (tAlquileres* array, int cantidadElementos)
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
    int retorno = -1;
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
        retorno = 0;
    }

    return retorno;
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
    int i,j,x;
    int searchIDCliente;
    int searchIDJuego;
    int indiceDeEspacioLibre;
    int auxDia;
    int auxMes;
    int auxAnio;
    bool idClienteEncontrado=false;
    bool idJuegoEncontrado=false;

    indiceDeEspacioLibre=obtenerEspacioLibreAlquiler(alquiler, cantidadElementos);

    searchIDCliente = utn_getInt("\n  Ingrese ID del cliente: ");   // Busco ID Cliente, si existe, paso a buscar el ID del Juego
    for (j=0;j<cantElementClientes;j++)
    {
        if (clientes[j].idCliente == searchIDCliente)
        {
            idClienteEncontrado=true;
        }
    }
    if (idClienteEncontrado == true)
    {
        searchIDJuego = utn_getInt("  Ingrese ID del juego: "); // Busco ID del Juego, si existe, paso a solicitar fecha
        for (x=0;x<cantElementJuegos;x++)
        {
            if (juegos[x].idJuego == searchIDJuego)
            {
                idJuegoEncontrado=true;
                break;
            }
        }

        if (idJuegoEncontrado == true)
        {
            auxDia = utn_getInt("  Dia (XX): ");
            if (auxDia <= 31 && auxDia > 0)
            {
                auxMes = utn_getInt("  Mes (XX): ");
                if (auxMes <= 12 && auxMes > 0)
                {
                    auxAnio = utn_getInt("  Anio (XXXX): ");
                    if (auxAnio <= 9999 && auxAnio > 999) // Se coloca de esta manera para detectar 4 digitos
                    {
                        if (alquiler[indiceDeEspacioLibre].isEmpty == 1)
                        {
                            alquiler[indiceDeEspacioLibre].isEmpty = 0;
                            alquiler[indiceDeEspacioLibre].codAlquiler = auxIdAlquiler;
                            alquiler[indiceDeEspacioLibre].fecha.dia=auxDia;
                            alquiler[indiceDeEspacioLibre].fecha.mes=auxMes;
                            alquiler[indiceDeEspacioLibre].fecha.anio=auxAnio;

                            for (i=0;i<cantElementClientes;i++)
                            {
                                if (clientes[i].idCliente == searchIDCliente)
                                {
                                    alquiler[indiceDeEspacioLibre].codCliente = searchIDCliente;
                                }
                            }
                            for (i=0;i<cantElementJuegos;i++)
                            {
                                if (juegos[i].idJuego == searchIDJuego)
                                {
                                    alquiler[indiceDeEspacioLibre].codJuego = searchIDJuego;
                                }
                            }

                            system("cls");
                            printf(" * ALQUILER CARGADO *");
                            retorno = 0;
                        }
                    }
                    else
                    {
                        system("cls");
                        printf("* ANIO INCORRECTO *");
                    }
                }
                else
                {
                    system("cls");
                    printf("* MES INCORRECTO *");
                }
            }
            else
            {
                system("cls");
                printf("* DIA INCORRECTO *");
            }
        }
        else
        {
            system("cls");
            printf("* ID DE JUEGO NO ENCONTRADO *");
        }
    }
    else
    {
        system("cls");
        printf("* ID DE CLIENTE NO ENCONTRADO *");
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
    int i,j;
    int retorno;
    bool idClienteEncontrado=false;


    searchID = utn_getInt("\n\n  Ingrese ID del cliente: ");
    for (j=0;j<cantidadElementos;j++)
    {
        if (array[j].idCliente == searchID)
        {
            idClienteEncontrado=true;
        }
    }

    if ((searchID > 0 && searchID <= 1000) && idClienteEncontrado == true)
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

            }system("cls");
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
int removeJuego (tJuegos* array,int cantidadElementos, int searchID, int contCargasJuegos)
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
                contCargasJuegos--;
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
 * Ordena el array de juegos de manera descendente por importe
 * @param array es array de tipo juego
 * @param cantidadElementos cantidad de elementos del array
 * @return (0) si se pudo realizar el ordenamiento, (-1) en caso de que no
 */
int ordenamientoJuegos (tJuegos* array, int cantidadElementos)
{
    int retorno = -1;
    tJuegos auxArray[cantidadElementos];
    int i,j;


    system("cls");
    for(i=0; i<cantidadElementos;i++)
    {
        if (array[i].isEmpty == 0)
        {
            for(j=i+1; j<cantidadElementos;j++)
            {
                if ((array[j].importeJuego > array[i].importeJuego) && array[j].isEmpty == 0)
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
 * Ordenado por apellido al array de clientes por inserción
 * @param array de clientes de tipo tCliente
 * @param cantidadElementos cantidad de elementos del array
 * @return (0) si se pudo ordenar, (-1) en caso de que no
 */
int ordenamientoClientes (tCliente* array, int cantidadElementos)
{
    int retorno = -1;
    tCliente auxArray;
    int i,j;

    for (i=0; i<cantidadElementos;i++)
    {
        if (array[i].isEmpty == 0)
        {
            auxArray = array[i];
            j = i - 1;
            while ((j >= 0) && (stricmp(array[j].apellido,array[i].apellido))>0)
            {
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = auxArray;
            retorno = 0;
        }
    }

    return retorno;
}







/**
 * Imprime los clientes con un ordenamiento específico
 * @param array es el array de clientes
 * @param cantidadElementos es la cantidad de elementos que tiene el array clientes
 * @return (0) si se pudo realizar | (-1) en caso de que no
 */
int listarClientes (tCliente* array, int cantidadElementos, int contadorCargas)
{
    int retorno = -1;
    int i;

    if (contadorCargas != 0)
    {
        printf("\n ---------- Listar ----------\n");

        for (i=0;i<cantidadElementos;i++)
        {
            if (array[i].isEmpty==0)
            {
                ordenamientoClientes(array, cantidadElementos);
                printf("    o ID%03d  %s, %s\n", array[i].idCliente, array[i].apellido, array[i].nombre);
            }
        }
        printf(" ----------------------------\n");
        retorno = 0;
     }
    if (contadorCargas==0)
    {
        printf("\n ---------- Listar ----------\n");
        printf(" NO EXISTEN DATOS PARA MOSTRAR\n");
        printf(" ----------------------------\n");
        retorno = 0;
    }
    return retorno;
}




/**
 *
 * @param
 * @return
 */
int listarJuegos (tJuegos* array, int cantidadElementos, int contCargasJuegos)
{
    int i;
    int retorno = -1;

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
        retorno = 0;
    }
    if (contCargasJuegos == 0)
    {
        printf("\n ---------- Listar ----------\n");
        printf(" NO EXISTEN DATOS PARA MOSTRAR\n");
        printf(" ----------------------------\n");
    }

    return retorno;
}






/**
 *
 * @param
 * @return
 */
int promeTotal (tAlquileres* array, tJuegos* juegos, int cantidadElementosJuegos,
                int cantidadElementosAlquilados,float promJuegosAlquilados,
                int cantidadJuegosAlquilados, int totalImporte)
{
    int retorno = 0;
    int i,j,x;
    int identificadorID;
    int cantImporteMenorAlPromedio=0;

    for (i=0;i<cantidadElementosAlquilados;i++)
    {
        if (array[i].isEmpty == 0)
        {
            cantidadJuegosAlquilados++;
            identificadorID=array[i].codJuego;

            for (j=0;j<cantidadElementosJuegos;j++)
            {
                if (identificadorID == juegos[j].idJuego)
                {
                    totalImporte = totalImporte + juegos[j].importeJuego;
                }
            }
        }
    }

    promJuegosAlquilados = totalImporte / cantidadJuegosAlquilados;



    for (x=0;x<cantidadElementosJuegos;x++)
    {
        if (juegos[x].importeJuego<=promJuegosAlquilados && juegos[x].isEmpty == 0)
        {
            cantImporteMenorAlPromedio++;
        }
    }

    printf("\n a) Monto total de juegos alquilados: $%.2d", totalImporte);
    printf("\n    Monto promedio: $%.2f", promJuegosAlquilados);
    printf("\n b) Cantidad de juegos de importe menor al promedio: %d", cantImporteMenorAlPromedio);




    return retorno;
}

/**
 * Lista juegos alquilados por un ID de cliente
 * @param array de alquileres
 * @param cantidadElementos del array de alquileres
 * @return (0) si se pudo realizar el listado | (-1) si no
 */
int listarJuegoDeterminado (tAlquileres* array, int cantidadElementos, tCliente* clientes, int cantElementClientes)
{
    int i,j;
    int searchID;
    int retorno=-1;

    fflush(stdin);
    searchID = utn_getInt("\n\n  Ingrese ID del juego: ");

    printf("\n c)Este juego fue alquilado por los clientes: ");
    if (searchID > 0 && searchID <= 1000)
    {
        for (i=0;i<cantidadElementos;i++)
        {
            if (array[i].codJuego == searchID && array[i].isEmpty == 0)
            {
                for (j=0;j<cantElementClientes;j++)
                {
                    if (array[i].codCliente == clientes[j].idCliente)
                    {
                        printf("\n         - ID%03d | %s, %s\n                  Domicilio: %s | Telefono: %d ", clientes[j].idCliente, clientes[j].apellido,
                                                                                                        clientes[j].nombre, clientes[j].domicilio,
                                                                                                        clientes[j].telefono);
                    }
                }

            }
        }
    retorno = 0;
    }

    else
    {
        printf("no existe este id");
    }
    printf("\n\n");
    return retorno;
}






/**
 * Lista clientes que alquilaron x ID juego
 * @param array de alquileres
 * @param cantidadElementos del array de alquileres
 * @return 0 si se pudo realizar | -1 si no
 */
int listarClienteDeterminado (tAlquileres* array, int cantidadElementos, tJuegos* juegos, int cantidadElementosJuegos)
{
    int i,j;
    int searchID;
    int retorno=-1;

    fflush(stdin);
    searchID = utn_getInt("\n\n  Ingrese ID del cliente: ");

    printf("\n d)Este cliente alquilo los juegos: ");
    if (searchID > 0 && searchID <= 1000)
    {
        for (i=0;i<cantidadElementos;i++)
        {
            if ((array[i].codCliente == searchID) && (array[i].isEmpty == 0))
            {
                for (j=0;j<cantidadElementosJuegos;j++)
                {
                    if (array[i].codJuego == juegos[j].idJuego)
                    {
                        printf("\n         - ID%03d | %s\n                 Importe: $%.2f",juegos[j].idJuego,
                                                                                           juegos[j].descripJuego,
                                                                                          juegos[j].importeJuego);
                    }
                }
            }
        }
        retorno = 0;
    }

    else
    {
        printf("no existe este id");
    }
    printf("\n\n");
    return retorno;
}







/**
 * Lista juegos de x fecha
 * @param array de alquileres
 * @param cantidadElementos del array de alquileres
 * @return 0 si se pudo realizar | -1 si no
 */
int listarJuegosPorFechaDeterminada (tAlquileres* array, int cantidadElementos, tJuegos* juegos, int cantElementJuegos)
{
    int i,j;
    int retorno=-1;
    int auxDia;
    int auxMes;
    int auxAnio;

    fflush(stdin);
    printf("\n\n  g)Filtrar juegos por fecha determinada, indique ");

    if(!((auxDia = utn_getInt("\n         Dia: "))<=31))
    {
        printf("Dia incorrecto");
    }

    if(!((auxMes = utn_getInt("         Mes: "))<=12))
    {
        printf("Mes incorrecto");
    }

    if(!((auxAnio = utn_getInt("         Anio (XXXX): "))<=9999)) //Coloco 9999 solo para detectar 4 dígitos
    {
        printf("Anio incorrecto");
    }

    printf("\n En esta fecha se alquilaron los juegos: ");

    for (i=0;i<cantidadElementos;i++)
    {
       for (j=0;j<cantElementJuegos;j++)
        {
            if (array[i].fecha.dia == auxDia && array[i].fecha.mes == auxMes && array[i].fecha.anio == auxAnio && array[i].isEmpty == 0 && juegos[j].idJuego==array[i].codJuego)
            {
             printf("\n         - ID%03d | %s ($%.2f)",array[j].codJuego, juegos[j].descripJuego, juegos[j].importeJuego);

            }
        }
    }
    retorno = 0;

    printf("\n\n");
    return retorno;
}






/**
 * Lista clientes que alquilaron en una fecha determinada
 * @param array de alquileres
 * @param cantidadElementos del array de alquileres
 * @return (0) si se pudo realizar el listado | (-1) si no
 */
int listarClientePorFechaDeterminada (tAlquileres* array, int cantidadElementos, tCliente* clientes, int cantElementClientes)
{
    int i,j;
    int retorno=-1;
    int auxDia;
    int auxMes;
    int auxAnio;

    fflush(stdin);

    printf("\n\n  h)Filtrar clientes por fecha determinada, indique ");

    if(!((auxDia = utn_getInt("\n         Dia: "))<=31))
    {
        printf("Dia incorrecto");
    }

    if(!((auxMes = utn_getInt("         Mes: "))<=12))
    {
        printf("Mes incorrecto");
    }

    if(!((auxAnio = utn_getInt("         Anio (XXXX): "))<=9999)) //Coloco 9999 solo para detectar 4 dígitos
    {
        printf("Anio incorrecto");
    }
    printf("\n Esta fecha alquilaron los clientes: ");

    for (i=0;i<cantidadElementos;i++)
    {
        for (j=0;j<cantElementClientes;j++)
        {
            if (array[i].fecha.dia == auxDia && array[i].fecha.mes == auxMes && array[i].fecha.anio == auxAnio && array[i].isEmpty == 0 && clientes[j].idCliente==array[i].codCliente)
            {
             printf("\n         - ID%03d | %s, %s",array[j].codCliente, clientes[j].apellido, clientes[j].nombre);

            }
        }
    }

    printf("\n\n");
    return retorno;
}



void cantidadVecesAlquiloJuego(Alquileres* alquilerJuegos,tAlquileres* alquiler,tJuegos* juego,int cantElementJuegos,int cantidadElementosAlquilados){
    int i,h;
    for(h=0;h<cantidadElementosAlquilados;h++){
        alquilerJuegos[h].cantDeAlquileres=0;
        alquilerJuegos[h].idJuego=0;
        alquilerJuegos[h].isEmpty=1;
    }
    for(i=0;i<cantidadElementosAlquilados;i++){
        for(h=0;h<cantidadElementosAlquilados;h++){
            if(alquiler[i].isEmpty==0&&(juego[i].idJuego==alquiler[h].codJuego)){
                alquilerJuegos[i].isEmpty=0;
                alquilerJuegos[i].idJuego=alquiler[h].codJuego;
                alquilerJuegos[i].cantDeAlquileres++;
            }
        }
    }
}


int juegosMenosAlquilados(Alquileres* alquilerJuegos,tAlquileres* alquiler,tJuegos* juego,int cantElementJuegos,int cantidadElementosAlquilados){
    int retorno=-1;
    int i, j;
    int valMinimo = cantidadElementosAlquilados;

    cantidadVecesAlquiloJuego(alquilerJuegos,alquiler,juego,cantElementJuegos,cantidadElementosAlquilados);

    for (j=0;j<cantidadElementosAlquilados;j++){
        if ((alquilerJuegos[j].cantDeAlquileres < valMinimo&&alquiler[j].isEmpty == 0)){
            valMinimo = alquilerJuegos[j].cantDeAlquileres;
        }
    }

    for (i=0;i<cantidadElementosAlquilados;i++){
        for (j=0;j<cantidadElementosAlquilados;j++){
            if (alquilerJuegos[i].isEmpty == 0 &&(alquilerJuegos[i].idJuego==alquiler[j].codJuego) &&
                (alquilerJuegos[i].cantDeAlquileres <= valMinimo) && alquiler[j].isEmpty==0){


                printf("\n\n  )El juego menos alquilado: - ID%03d | %s \n", juego[j].idJuego, juego[j].descripJuego,
                                                                            juego[j].importeJuego);
                retorno=i;
            }
        }
    }

    return retorno;
}


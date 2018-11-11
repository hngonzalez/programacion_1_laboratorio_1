#include <stdio.h>
#include <stdlib.h>
#include "ClienJuegos.h"
#include "input.h"
#define CANT_CLIENTES 5
#define CANT_JUEGOS 5
#define CANT_CyJ  CANT_CLIENTES*CANT_JUEGOS

int main()
{
//---------- DECLARO VARIABLES
    tCliente clientes[CANT_CLIENTES];
        int auxID=0;
        int searchID=0;
        char auxNombre[51];
        char auxApellido[51];
        char auxDomicilio[51];
        int auxTelefono;

    tJuegos juegos[CANT_JUEGOS];
        int auxIdJuegos=0;
        char auxDescripcion[51];
        float auxImporte;

    tAlquileres alquiler[CANT_CyJ];
        int auxFecha;
        int auxIdAlquiler=0;
    int x,n,b;
    int optionMenu;
    int optionSubMenu;
    int indiceParaModificar;
    int contadorCargas=0;
    int contCargasJuegos=0;
    int contCargasAlquileres=0;
    float promJuegosAlquilados;
    int cantidadJuegosAlquilados=0;
    int totalImporte=0;
//---------- INICIALIZO LOS ARRAY COMO VACIO ASIGNANDO VALOR A LA BANDERA isEmpty
    initArray (clientes, juegos, alquiler, CANT_CLIENTES, CANT_JUEGOS, CANT_CyJ);
//---------- PIDO OPCION DE ACCESO AL USUARIO
    do
    {

        fflush(stdin);
        printf("\n\n ----- MENU ABM -----");
        optionMenu=utn_getInt("\n\n   1.- JUEGOS\n   2.- CLIENTES\n   3.- ALQUILERES\n   4.- INFORMES\n\n          Opcion: ");

        switch (optionMenu)
        {

            case 1: //====== JUEGOS
                printf("\n\n   o MENU JUEGOS -----");
                optionSubMenu=utn_getInt("\n\n      1.- ALTA\n      2.- MODIFICAR\n      3.- BAJA\n      4.-LISTAR\n\n          Opcion: ");
                switch (optionSubMenu)
                {
                    case 1: //====== SUBMENU ALTA JUEGOS
                        auxIdJuegos++;

                        if (altaJuegos (juegos, CANT_JUEGOS, auxIdJuegos,
                                        auxDescripcion, auxImporte) == 0)
                        {
                            contCargasJuegos++;
                            break;
                        }

                        break;
                    case 2: //====== SUBMENU MODIFICAR JUEGOS
                        if (contCargasJuegos != 0)
                        {

                            indiceParaModificar = encontrarPorIdJuegos (juegos, CANT_JUEGOS,
                                                                        searchID);

                            editJuegos (juegos, indiceParaModificar);

                            break;
                        }
                        else
                        {
                             system("cls");
                             printf(" * NO EXISTEN JUEGOS AUN *");
                             break;
                        }
                    case 3: //====== SUBMENU BAJA JUEGOS
                        if (contCargasJuegos != 0)
                        {
                            removeJuego (juegos, CANT_JUEGOS, searchID, contCargasJuegos);
                            break;
                        }
                        else
                        {
                             system("cls");
                             printf(" * NO EXISTEN JUEGOS AUN *");
                             break;
                        }

                        break;
                    case 4: //====== SUBMENU LISTAR JUEGOS
                        system("cls");

                        listarJuegos (juegos, CANT_JUEGOS, contCargasJuegos);
                        break;
                    default:
                        system("cls");
                        printf("  OPCION INCORRECTA - REINTENTE");
                        break;
                }
                break;

            case 2: //====== CLIENTES
                printf("\n\n   o MENU CLIENTES -----");
                optionSubMenu=utn_getInt("\n\n      1.- ALTA\n      2.- MODIFICAR\n      3.- BAJA\n      4.-LISTAR\n\n          Opcion: ");
                switch (optionSubMenu)
                {
                    case 1: //====== SUBMENU ALTA CLIENTES
                        auxID++;

                        if (altaCliente (clientes, CANT_CLIENTES,
                                         auxID,  auxNombre, auxApellido, auxDomicilio,
                                         auxTelefono) == 0)
                        {
                            contadorCargas++;
                            break;
                        }
                        break;
                    case 2: //====== SUBMENU MODIFICAR CLIENTES

                        if (contadorCargas != 0)
                        {
                            indiceParaModificar = encontrarPorId (clientes, CANT_CLIENTES,
                                                                  searchID);

                            editCliente(clientes, indiceParaModificar);

                            break;
                        }
                        else
                        {
                             system("cls");
                             printf(" * NO EXISTEN EMPLEADOS AUN *");
                             break;
                        }
                    case 3: //====== SUBMENU BAJA CLIENTES
                        if (contadorCargas != 0)
                        {
                            removeCliente(clientes, CANT_CLIENTES, searchID);
                            break;
                        }
                        else
                        {
                             system("cls");
                             printf(" * NO EXISTEN EMPLEADOS AUN *");
                             break;
                        }
                        break;

                    case 4: //====== SUBMENU LISTAR CLIENTES
                        system("cls");

                        listarClientes (clientes, CANT_CLIENTES, contadorCargas);
                        break;
                    default:
                        system("cls");
                        printf("  OPCION INCORRECTA - REINTENTE");
                        break;
                }
                break;

            case 3: //====== ALQUILERES
                auxIdAlquiler++;

                if (altaAlquiler (clientes, juegos, alquiler, CANT_CyJ, CANT_CLIENTES, CANT_JUEGOS, auxIdAlquiler) == 0)
                {
                    contCargasAlquileres++;
                    break;
                }

                break;


            case 4: //====== PARA VERIFICAR ALQUILERES

                if (contCargasAlquileres != 0)
                {
                    promeTotal (alquiler, juegos,  CANT_JUEGOS,
                                CANT_CyJ, promJuegosAlquilados,
                                cantidadJuegosAlquilados, totalImporte);

                    listarJuegoDeterminado (alquiler, CANT_CyJ, clientes, CANT_CLIENTES);
                    listarClienteDeterminado (alquiler, CANT_CyJ, juegos, CANT_JUEGOS);
                    listarJuegosPorFechaDeterminada (alquiler, CANT_CyJ, juegos, CANT_JUEGOS);
                    listarClientePorFechaDeterminada (alquiler, CANT_CyJ, clientes, CANT_CLIENTES);

                    juegoMenosAlquilado (alquiler,CANT_CyJ, juegos, CANT_JUEGOS);
                }
                else
                {
                     system("cls");
                     printf(" * NO EXISTEN ALQUILERES CARGADOS AUN *");
                     break;
                }

                break;

                /*for (int i=0;i<CANT_CyJ;i++)
                {
                    if(alquiler[i].isEmpty == 0)
                    {
                        printf("ID Alquiler: %d - Cliente: %d Juego: %d Fecha: %d", alquiler[i].codAlquiler, alquiler[i].codCliente, alquiler[i].codJuego, alquiler[i].fecha);
                    }
                }
                break;
            */
            default: //======
                system("cls");
                printf("  OPCION INCORRECTA - REINTENTE");
                break;
        }

    } while (optionMenu != 5);

    system("cls");
    printf("\n\n    HASTA\n    LUEGO\n\n\n");



    return 0;
}

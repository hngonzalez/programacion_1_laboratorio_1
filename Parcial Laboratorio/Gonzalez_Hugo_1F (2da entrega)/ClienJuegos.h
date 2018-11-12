#ifndef CLIENJUEGOS_H_INCLUDED
#define CLIENJUEGOS_H_INCLUDED

typedef struct
{
    int idJuego;
    char descripJuego[51];
    float importeJuego;
    int isEmpty;
} tJuegos;

typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char domicilio[51];
    int telefono;
    int isEmpty;
} tCliente;

typedef struct
{
    int dia;
    int mes;
    int anio;
} tFecha;

typedef struct
{
    int codAlquiler;
    int codJuego;
    int codCliente;
    tFecha fecha;
    int isEmpty;
} tAlquileres;

typedef struct {
    int idJue;
    int idClie;
    int cantidadDeAlquileres;
    int isEmpty;
} Alquileres;


int initArray (tCliente* arrayCliente, tJuegos* arrayJuegos, tAlquileres* arrayAlquiler,
               int cantElementClientes, int cantElementJuegos, int cantAlquileres);

int altaCliente (tCliente* array, int cantidadElementos,
                 int auxID, char* auxNombre, char* auxApellido,
                 char* auxDomicilio, int auxTelefono);

int encontrarPorId (tCliente* array, int cantidadElementos,int searchID);
int encontrarPorIdJuegos (tJuegos* array, int cantidadElementos,int searchID);
int editCliente (tCliente* array, int indiceParaModificar);
int editJuegos (tJuegos* array, int indiceParaModificar);
int removeCliente (tCliente* array, int cantidadElementos, int searchID);
int removeJuego (tJuegos* array,int cantidadElementos, int searchID, int contCargasJuegos);

int altaJuegos (tJuegos* array, int cantidadElementos, int auxIdJuegos,
                char* auxDescripcion,float auxImporte);


int obtenerEspacioLibre(tCliente* array, int cantidadElementos);
int ordenamientoJuegos (tJuegos* array, int cantidadElementos);
int ordenamientoClientes (tCliente* array, int cantidadElementos);
int obtenerEspacioLibreAlquiler (tAlquileres* array, int cantidadElementos);
int listarClientes (tCliente* array, int cantidadElementos, int contadorCargas);
int listarJuegos (tJuegos* array,int cantidadElementos, int contCargasJuegos);

int altaAlquiler (tCliente* clientes, tJuegos* juegos, tAlquileres* alquiler,
                  int cantidadElementos, int cantElementClientes, int cantElementJuegos,
                  int auxIdAlquiler);

int promeTotal (tAlquileres* array, tJuegos* juegos, int cantidadElementosJuegos,
                int cantidadElementosAlquilados,float promJuegosAlquilados,
                int cantidadJuegosAlquilados, int totalImporte);
int listarJuegoDeterminado (tAlquileres* array, int cantidadElementos, tCliente* clientes, int cantElementClientes);
int listarClienteDeterminado (tAlquileres* array, int cantidadElementos,tJuegos* juegos, int cantidadElementosJuegos);
int listarJuegosPorFechaDeterminada (tAlquileres* array, int cantidadElementos,tJuegos* juegos, int cantElementJuegos);
int listarClientePorFechaDeterminada (tAlquileres* array, int cantidadElementos, tCliente* clientes, int cantElementClientes);

void cantidadVecesAlquiloJuego(Alquileres* alquilerJuegos,tAlquileres* alquiler,tJuegos* juego,int cantElementJuegos,int cantidadElementosAlquilados);
int juegosMenosAlquilados(Alquileres*,tAlquileres*,tJuegos*,int,int);

#endif  // CLIENJUEGOS_H_INCLUDED

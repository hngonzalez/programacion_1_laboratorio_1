#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

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
    int codAlquiler;
    int codJuego;
    int codCliente;
    int fecha;
    int isEmpty;
} tAlquileres;

int utn_getInt (char* msg);
int utn_isLetter(char* cadena);
void utn_getString(char* msg, char* input);
int utn_getStringLetter(char* msg, char* input);
float utn_getFloat (char* msg);

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
int removeJuego (tJuegos* array,int cantidadElementos, int searchID);

int altaJuegos (tJuegos* array, int cantidadElementos, int auxIdJuegos,
                char* auxDescripcion,float auxImporte);


int obtenerEspacioLibre(tCliente* array, int cantidadElementos);
int ordenamientoJuegos (tJuegos* array, int cantidadElementos);
int ordenamientoClientes (tCliente* array, int cantidadElementos);
int listarClientes (tCliente* array, int cantidadElementos, int contadorCargas);
int listarJuegos (tJuegos* array,int cantidadElementos, int contCargasJuegos);

int altaAlquiler (tCliente* clientes, tJuegos* juegos, tAlquileres* alquiler,
                  int cantidadElementos, int cantElementClientes, int cantElementJuegos,
                  int auxIdAlquiler);


#endif // PROTOTIPOS_H_INCLUDED

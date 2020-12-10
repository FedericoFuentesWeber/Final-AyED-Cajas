#ifndef FINALCAJAS2019_CAJAS_H
#define FINALCAJAS2019_CAJAS_H
#include "clientes.h"

struct CajaStruct{
    int numero_de_caja;
    int dinero_al_comenzar;
    int valores_cobrados_por_ventana;
};

struct NodoCajaStruct{
    CajaStruct una_caja;
    NodoClienteStruct *cola_de_clientes;
    NodoCajaStruct *siguiente_caja;
};

//Lee las N [1 .. 40] cajas desde el archivo Cajas.dat
NodoCajaStruct* cajas_habilitadas(NodoCajaStruct *&lista_de_cajas);

//Hace que el primer cliente de la cola sea atendido en la caja, se actualizan los valores de la caja
void atender_cliente(int numero_de_caja_asignado);

//Se reasigna a un cliente de una caja llena a otra vacia
void reasignar_caja(int numero_de_caja_actual, int numero_de_caja_destino);


int calcular_importes(int numero_de_carrito_a_calcular);

#endif //FINALCAJAS2019_CAJAS_H

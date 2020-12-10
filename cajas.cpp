#include "cajas.h"
#include <iostream>
#include <stdio.h> //archivos
#include "clientes.h"

#define ARCHIVO "Cajas.dat"

NodoCajaStruct* buscar_nodo(NodoCajaStruct *lista_de_cajas, int numero_de_caja_buscado)
{
    while (lista_de_cajas && (lista_de_cajas -> una_caja.numero_de_caja != numero_de_caja_buscado))
    {
        lista_de_cajas = lista_de_cajas -> siguiente_caja;
    }
    return lista_de_cajas;
}

//Crea una lista con los datos guardados en el archivo
NodoCajaStruct* cajas_habilitadas(NodoCajaStruct *&lista_de_cajas){

    FILE *archivo_de_cajas;
    NodoCajaStruct *nodo_auxiliar_de_cajas;
    archivo_de_cajas = fopen(ARCHIVO, "rb");
    CajaStruct nueva_caja;

    while(fread(&nueva_caja, sizeof(CajaStruct), 1, archivo_de_cajas)){

        NodoClienteStruct *cola_de_clientes = NULL;
        if(!lista_de_cajas){  //if(lista_de_cajas == NULL)
            lista_de_cajas = new NodoCajaStruct();
            lista_de_cajas -> una_caja = nueva_caja;
            lista_de_cajas -> cola_de_clientes = inicializar_cola_de_clientes(cola_de_clientes);
            lista_de_cajas -> siguiente_caja = NULL;
        }
        else{
            nodo_auxiliar_de_cajas = lista_de_cajas;
            while(nodo_auxiliar_de_cajas && nodo_auxiliar_de_cajas -> siguiente_caja){
                nodo_auxiliar_de_cajas = nodo_auxiliar_de_cajas -> siguiente_caja;
            }
            nodo_auxiliar_de_cajas -> siguiente_caja = new NodoCajaStruct();
            nodo_auxiliar_de_cajas = nodo_auxiliar_de_cajas -> siguiente_caja;
            nodo_auxiliar_de_cajas -> una_caja = nueva_caja;
            lista_de_cajas -> cola_de_clientes = inicializar_cola_de_clientes(cola_de_clientes);
            nodo_auxiliar_de_cajas -> siguiente_caja = NULL;
        }
    }
    return lista_de_cajas;
}

//int calcular_importes(int numero_de_carrito_a_calcular);

void actualizar_valores_de_caja(NodoCajaStruct *&caja_a_actualizar, NodoClienteStruct *cliente_asignado){

    int importes = calcular_importes(cliente_asignado -> numero_de_carrito_asignado);

    caja_a_actualizar -> una_caja.valores_cobrados_por_ventana += importes;

    return;
}

void atender_cliente(int numero_de_caja_asignado){

    //Inicializo las cajas
    NodoCajaStruct *lista_de_cajas_habilitadas = cajas_habilitadas(lista_de_cajas_habilitadas);

    //Busco la caja asignada
    NodoCajaStruct *caja_asignada = buscar_nodo(lista_de_cajas_habilitadas, numero_de_caja_asignado);

    while(caja_asignada -> cola_de_clientes){ //Mientras que la lista de clientes no sea NULL, actualizar valores
        NodoClienteStruct *auxiliar_cola_de_clientes = caja_asignada -> cola_de_clientes;
        actualizar_valores_de_caja(caja_asignada, auxiliar_cola_de_clientes);

        auxiliar_cola_de_clientes = auxiliar_cola_de_clientes -> siguiente_cliente;
    }

    return;
}

void reasignar_caja(int numero_de_caja_actual, int numero_de_caja_destino){

    NodoCajaStruct *lista_de_cajas_habilitadas = cajas_habilitadas(lista_de_cajas_habilitadas);

    NodoCajaStruct *caja_actual = buscar_nodo(lista_de_cajas_habilitadas, numero_de_caja_actual);
    NodoCajaStruct *caja_de_destino = buscar_nodo(lista_de_cajas_habilitadas, numero_de_caja_destino);

    if(caja_actual -> cola_de_clientes){ //Si la cola de clientes de la caja actual no esta vacia

        NodoClienteStruct *auxiliar_cliente_caja_actual = caja_actual -> cola_de_clientes;
        int numero_de_carrito_a_trasladar = enqueue(auxiliar_cliente_caja_actual);

        nuevo_cliente(caja_de_destino -> cola_de_clientes, numero_de_carrito_a_trasladar);
    }
    return;
}
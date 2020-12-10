#include "clientes.h"
#include <iostream>

using namespace  std;


int enqueue(NodoClienteStruct *&cola_de_clientes){

    int numero_de_carrito_a_quitar;
    NodoClienteStruct *auxiliar_de_cliente;
    if(cola_de_clientes){

        numero_de_carrito_a_quitar = cola_de_clientes -> numero_de_carrito_asignado;
        auxiliar_de_cliente = cola_de_clientes -> siguiente_cliente;
        delete cola_de_clientes;
        cola_de_clientes = auxiliar_de_cliente;
        return numero_de_carrito_a_quitar;
    }
    else{
        cout << "ERROR: COLA VACIA" << endl;
        return 0;
    }
}

NodoClienteStruct *obtener_ultimo_cliente(NodoClienteStruct *cola){

    while(cola && cola -> siguiente_cliente){
        cola = cola -> siguiente_cliente;
    }
    return cola;
}

void nuevo_cliente(NodoClienteStruct *&cola_de_clientes, int nuevo_carrito_asignado_a_un_cliente){
    //queue(cola_de_clientes, nuevo_cliente);
    NodoClienteStruct *nodo_auxiliar_de_cliente;

    if(cola_de_clientes){
        nodo_auxiliar_de_cliente = obtener_ultimo_cliente(cola_de_clientes);
        nodo_auxiliar_de_cliente -> siguiente_cliente = new NodoClienteStruct();
        nodo_auxiliar_de_cliente = nodo_auxiliar_de_cliente -> siguiente_cliente;
        nodo_auxiliar_de_cliente -> numero_de_carrito_asignado = nuevo_carrito_asignado_a_un_cliente;
        nodo_auxiliar_de_cliente -> siguiente_cliente = NULL;
    }
    else{
        nodo_auxiliar_de_cliente = new NodoClienteStruct();
        nodo_auxiliar_de_cliente -> numero_de_carrito_asignado = nuevo_carrito_asignado_a_un_cliente;
        nodo_auxiliar_de_cliente -> siguiente_cliente = NULL;
    }
    return;
}

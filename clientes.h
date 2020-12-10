#ifndef FINALCAJAS2019_CLIENTES_H
#define FINALCAJAS2019_CLIENTES_H
/*
struct Cliente{
    int numero_de_carrito_de_compras;
};
*/
struct NodoClienteStruct{
    //Cliente un_cliente;
    int numero_de_carrito_asignado;
    NodoClienteStruct *siguiente_cliente;
};

//Actualiza la cola unica de clientes con el nuevo cliente
//void nuevo_cliente(NodoClienteStruct *&cola_de_clientes, Cliente nuevo_cliente);
void nuevo_cliente(NodoClienteStruct *&cola_de_clientes, int nuevo_carrito_asignado_a_un_cliente);

NodoClienteStruct *inicializar_cola_de_clientes(NodoClienteStruct *&lista_de_clientes);


int enqueue(NodoClienteStruct *&cola_de_clientes);

#endif //FINALCAJAS2019_CLIENTES_H

#include <fstream>
#include <iostream>
#include <string>

#include "../cliente/cliente.h"
#include "./archivo.h"

Archivo::Archivo(std::string _pathClientes, std::string _pathTransacciones) : pathClientes(_pathClientes), pathTransacciones(_pathTransacciones) {}

void Archivo::iniciarNuevoArchivo() {
  // Abre los archivos para leer si es que existen.
  transacciones.open(pathTransacciones, std::ios::in);
  clientes.open(pathClientes, std::ios::in);

  /* Primero se chequea si el archivo existe.
    Si ya hubiese un archivo entonces se habria abierto en las dos lineas
    anteriores por lo tanto esta funcion terminaria su ejecucion.
    En caso de no haber archivo lo crea y lo abre en las dos primeras lineas
    del if */
  if (!transacciones.is_open() && !clientes.is_open()) {
    /* En caso de no haber archivo lo crea y lo abre en las siguientes dos
      lineas*/
    transacciones.open(pathTransacciones, std::ios::out);
    clientes.open(pathClientes, std::ios::out);

    transacciones << "NroCliente  NroTransaccion  Monto Tipo  Fecha";
    clientes << "NroCliente  Nombre  Apellido  Categoria  Anio  Estado";

    transacciones.close();
    clientes.close();
  }
}

void Archivo::actualizarArchivo(int, int, int, std::string, int, int, int) {
  /*Primero se abre el archivo en modo de lectura para chequear si 
  este existe, y en caso de que exista lo cierra y lo vuelve a abrir
  en modo'append'*/
}

void Archivo::cargarDesdeArchivo() {
  std::string lectura;

  std::ifstream transacciones(pathTransacciones);
  std::ifstream clientes(pathClientes);
  
  if (transacciones.is_open() && clientes.is_open()) {
  }
}

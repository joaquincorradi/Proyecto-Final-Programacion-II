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

    transacciones << "La wea funciona.";
    clientes << "La wea funciona.";

    transacciones.close();
    clientes.close();
  }
}

void Archivo::actualizarArchivo(int, int, int, std::string, int, int, int) {}

void Archivo::cargarDesdeArchivo() {
  transacciones.open("transacciones.txt", std::ios::in);
  clientes.open("clientes.txt", std::ios::in);

  if (transacciones.is_open() && clientes.is_open()) {
  }
}

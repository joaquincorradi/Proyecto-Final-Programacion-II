#include <fstream>
#include <iostream>
#include <string>

#include "../cliente/cliente.h"
#include "./archivo.h"

Archivo::Archivo(std::string _pathClientes, std::string _pathTransacciones)
    : pathClientes(_pathClientes), pathTransacciones(_pathTransacciones) {}

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

void Archivo::cargarDesdeArchivo(int *pContadorCantidadCliente,
                                 Cliente *objCliente[20]) {
  std::string lectura;
  std::string tmp;
  int cambioDeTipo;

  std::ifstream transacciones(pathTransacciones);
  std::ifstream clientes(pathClientes);

  if (transacciones.is_open() && clientes.is_open()) {
    for (int i = 0; i < 6; i++) {
      clientes >> tmp;
    }

    while (clientes >> lectura) {
      ++*pContadorCantidadCliente;

      cambioDeTipo = std::stoi(lectura);
      objCliente[*pContadorCantidadCliente]->setNumeroDeCliente(cambioDeTipo);

      clientes >> lectura;
      objCliente[*pContadorCantidadCliente]->setNombreDelCliente(lectura);

      clientes >> lectura;
      objCliente[*pContadorCantidadCliente]->setApellidoDelCliente(lectura);

      clientes >> lectura;
      if (lectura == "plata") {
        objCliente[*pContadorCantidadCliente]->setClientePlata(true);
        objCliente[*pContadorCantidadCliente]->setClienteOro(false);
        objCliente[*pContadorCantidadCliente]->setClienteBlack(false);
      } else if (lectura == "oro") {
        objCliente[*pContadorCantidadCliente]->setClientePlata(false);
        objCliente[*pContadorCantidadCliente]->setClienteOro(true);
        objCliente[*pContadorCantidadCliente]->setClienteBlack(false);
      } else if (lectura == "black") {
        objCliente[*pContadorCantidadCliente]->setClientePlata(false);
        objCliente[*pContadorCantidadCliente]->setClienteOro(false);
        objCliente[*pContadorCantidadCliente]->setClienteBlack(true);
      }

      clientes >> lectura;
      cambioDeTipo = std::stoi(lectura);
      objCliente[*pContadorCantidadCliente]->setAnioDeIngresoDelCliente(
          cambioDeTipo);

      clientes >> lectura;
      if (lectura == "activo") {
        objCliente[*pContadorCantidadCliente]->setEstadoDelCliente(true);
      } else if (lectura == "inactivo") {
        objCliente[*pContadorCantidadCliente]->setEstadoDelCliente(false);
      }
    }

    if (*pContadorCantidadCliente >= 0) {
      std::cout << "Se importaron " << *pContadorCantidadCliente + 1
                << " clientes de la sesion anterior.\n\n";
    }

    transacciones.close();
    clientes.close();
  }
}

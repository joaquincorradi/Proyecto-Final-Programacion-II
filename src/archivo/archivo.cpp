#include <fstream>
#include <ios>
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

    transacciones << "NroCliente  NroTransaccion  Monto Tipo  Dia  Mes  Anio";
    clientes << "NroCliente  Nombre  Apellido  Categoria  Anio  Estado DineroEnCuenta";

    transacciones.close();
    clientes.close();
  }
}

void Archivo::actualizarArchivoClientes(Cliente *objCliente[20],
                                        int *pContadorCantidadCliente) {
  std::string lectura;
  std::ofstream clientes(pathClientes, std::ios::app);

  if (clientes.is_open()) {
    clientes << '\n'
             << objCliente[*pContadorCantidadCliente]->getNumeroDeCliente()
             << " ";
    clientes << " "
             << objCliente[*pContadorCantidadCliente]->getNombreDelCliente()
             << " ";
    clientes << " "
             << objCliente[*pContadorCantidadCliente]->getApellidoDelCliente()
             << " ";

    if (objCliente[*pContadorCantidadCliente]->getClientePlata()) {
      clientes << " plata ";
    } else if (objCliente[*pContadorCantidadCliente]->getClienteOro()) {
      clientes << " oro ";
    } else if (objCliente[*pContadorCantidadCliente]->getClienteBlack()) {
      clientes << " black ";
    }

    clientes
        << " "
        << objCliente[*pContadorCantidadCliente]->getAnioDeIngresoDelCliente()
        << " ";

    if (objCliente[*pContadorCantidadCliente]->getEstadoDelCliente()) {
      clientes << " activo ";
    } else {
      clientes << " inactivo ";
    }

    clientes << " "
             << objCliente[*pContadorCantidadCliente]->getDineroEnCuenta()
             << '\n';
  }
  clientes.close();
}

void Archivo::actualizarArchivoTransacciones(Cliente *objCliente[20],
                                             int *pEleccionDelUsuario,
                                             int *pTempCantidadDeTrasacciones,
                                             int *pContadorNroTransaccion) {
  std::string lectura;
  std::ofstream transacciones(pathTransacciones, std::ios::app);

  if (transacciones.is_open()) {
    transacciones << '\n' << *pEleccionDelUsuario << " ";
    transacciones << " " << *pContadorNroTransaccion << " ";
    transacciones << " "
                  << objCliente[*pEleccionDelUsuario]
                         ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
                         .getMontoDeTransaccion()
                  << " ";

    if (objCliente[*pEleccionDelUsuario]
            ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
            .getDeposito()) {
      transacciones << " deposito ";
    } else if (objCliente[*pEleccionDelUsuario]
                   ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
                   .getExtraccion()) {
      transacciones << " extraccion ";
    }

    transacciones << " "
                  << objCliente[*pEleccionDelUsuario]
                         ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
                         .getDiaDetransaccion()
                  << " ";
    transacciones << " "
                  << objCliente[*pEleccionDelUsuario]
                         ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
                         .getMesDeTransaccion()
                  << " ";
    transacciones << " "
                  << objCliente[*pEleccionDelUsuario]
                         ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
                         .getAnioDeTransaccion()
                  << '\n';
  }
  transacciones.close();
}

void Archivo::cargarDesdeArchivoClientes(int *pContadorCantidadCliente,
                                 Cliente *objCliente[20]) {
  std::string lectura;
  std::string tmp;
  int cambioDeTipo;
  float cambioDeTipoF;

  std::ifstream clientes(pathClientes);

  if (clientes.is_open()) {
    for (int i = 0; i < 7; ++i) {
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

      clientes >> lectura;
      cambioDeTipo = std::stoi(lectura);
      objCliente[*pContadorCantidadCliente]->setDineroEnCuenta(cambioDeTipo);
    }

    if (*pContadorCantidadCliente >= 0) {
      std::cout << "Se importaron " << *pContadorCantidadCliente + 1
                << " clientes de la sesion anterior.\n\n";
    }
  }
    clientes.close();
}

void Archivo::cargarDesdeArchivoTransacciones(Cliente *objCliente[20], int *pContadorNroTransaccion) {
  std::ifstream transacciones(pathTransacciones);

  std::string lectura;
  std::string tmp;

  int cambioDeTipo;
  float cambioDeTipoF;

  if (transacciones.is_open()) {
    for (int i = 0; i < 7; ++i) {
      transacciones >> tmp;
    }

  while (transacciones >> lectura) {
      ++*pContadorNroTransaccion;
      /*Se guarda el numero del cliente al que corresponde la transaccion para
       asi poder asignarle la misma*/
      int numeroDeClienteTmp = std::stoi(lectura);

      if (objCliente[numeroDeClienteTmp]->getCantidadDeTransacciones() == -1) {
        objCliente[numeroDeClienteTmp]->setCantidadDeTransacciones(0);
      }

      int cantidadDeTransaccionesTmp =
          objCliente[numeroDeClienteTmp]->getCantidadDeTransacciones();

      transacciones >> lectura;
      cambioDeTipo = std::stoi(lectura);
      objCliente[numeroDeClienteTmp]
          ->objTransaccionCliente[cantidadDeTransaccionesTmp]
          .setNumeroDeTransaccion(cambioDeTipo);

      transacciones >> lectura;
      cambioDeTipoF = std::stof(lectura);
      objCliente[numeroDeClienteTmp]
          ->objTransaccionCliente[cantidadDeTransaccionesTmp]
          .setMontoDeTransaccion(cambioDeTipoF);

      transacciones >> lectura;

      if (lectura == "extraccion") {
        objCliente[numeroDeClienteTmp]
            ->objTransaccionCliente[cantidadDeTransaccionesTmp]
            .setExtraccion(true);

        objCliente[numeroDeClienteTmp]
            ->objTransaccionCliente[cantidadDeTransaccionesTmp]
            .setDeposito(false);
      } else if (lectura == "deposito") {
        objCliente[numeroDeClienteTmp]
            ->objTransaccionCliente[cantidadDeTransaccionesTmp]
            .setDeposito(true);

        objCliente[numeroDeClienteTmp]
            ->objTransaccionCliente[cantidadDeTransaccionesTmp]
            .setExtraccion(false);
      }

      transacciones >> lectura;
      cambioDeTipo = std::stoi(lectura);
      objCliente[numeroDeClienteTmp]
          ->objTransaccionCliente[cantidadDeTransaccionesTmp]
          .setDiaDeTransaccion(cambioDeTipo);

      transacciones >> lectura;
      cambioDeTipo = std::stoi(lectura);
      objCliente[numeroDeClienteTmp]
          ->objTransaccionCliente[cantidadDeTransaccionesTmp]
          .setMesDeTransaccion(cambioDeTipo);

      transacciones >> lectura;
      cambioDeTipo = std::stoi(lectura);
      objCliente[numeroDeClienteTmp]
          ->objTransaccionCliente[cantidadDeTransaccionesTmp]
          .setAnioDeTransaccion(cambioDeTipo);

      ++cantidadDeTransaccionesTmp;
      objCliente[numeroDeClienteTmp]->setCantidadDeTransacciones(
          cantidadDeTransaccionesTmp);
    }

    transacciones.close();
 }
}

void Archivo::actulizarALaBaja(Cliente *objCliente[20], int *pContadorCantidadCliente){
  std::ofstream clientes(pathClientes, std::ios::out);

  if (clientes.is_open()) {
    clientes << "NroCliente  Nombre  Apellido  Categoria  Anio  Estado DineroEnCuenta";
    
    for (int i = 0; i <= *pContadorCantidadCliente; ++i){
    clientes << '\n'
             << objCliente[i]->getNumeroDeCliente()
             << " ";
    clientes << " "
             << objCliente[i]->getNombreDelCliente()
             << " ";
    clientes << " "
             << objCliente[i]->getApellidoDelCliente()
             << " ";

    if (objCliente[i]->getClientePlata()) {
      clientes << " plata ";
    } else if (objCliente[i]->getClienteOro()) {
      clientes << " oro ";
    } else if (objCliente[i]->getClienteBlack()) {
      clientes << " black ";
    }

    clientes
        << " "
        << objCliente[i]->getAnioDeIngresoDelCliente()
        << " ";

    if (objCliente[i]->getEstadoDelCliente()) {
      clientes << " activo ";
    } else if (!objCliente[i]->getEstadoDelCliente()) {
      clientes << " inactivo ";
    }

    clientes << " "
             << objCliente[i]->getDineroEnCuenta()
             << '\n';
  }
  }
  clientes.close();
}


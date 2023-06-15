#ifndef PROYECTOFINAL_SRC_ARCHIVO_ARCHIVO_H_
#define PROYECTOFINAL_SRC_ARCHIVO_ARCHIVO_H_

#include "../cliente/cliente.h"

#include <fstream>
#include <string>

class Archivo {
  std::fstream transacciones;
  std::fstream clientes;
  std::string pathTransacciones;
  std::string pathClientes;

public:
  Archivo(std::string, std::string);
  void iniciarNuevoArchivo();
  void actualizarArchivoClientes(Cliente *objCliente[20], int *);
  void actualizarArchivoTransacciones(Cliente *objCliente[20], int *, int *,
                                      int *);
  void cargarDesdeArchivo(int *, Cliente *objCliente[20], int *);
  void actulizarALaBaja(Cliente *objCliente[20], int *);
};

#endif

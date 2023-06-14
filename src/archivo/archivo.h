#ifndef PROYECTOFINAL_SRC_ARCHIVO_ARCHIVO_H_
#define PROYECTOFINAL_SRC_ARCHIVO_ARCHIVO_H_

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
  void actualizarArchivo(int, int, int, std::string, int, int, int);
  void cargarDesdeArchivo();
};

#endif

#ifndef PROYECTOFINAL_SRC_CLIENTE_CLIENTE_H_
#define PROYECTOFINAL_SRC_CLIENTE_CLIENTE_H_

#include <string>

class cliente {
private:
  int numeroDeCliente;
  std::string nombreDelCliente;
  std::string apellidoDelCliente;
  int anioDeIngresoDelCliente;
  bool estadoDelCliente;

public:
  cliente(std::string, std::string);

  int getNumeroDeCliente();
  std::string getNombreDelCliente;
  std::string getApellidoDelCliente;
  int getAnioDeIngresoDelCliente;
  bool getEstadoDelCliente;

  void setNumeroDeCliente(int);
  void setNombreDelCliente(std::string);
  void setApellidoDelCliente(std::string);
  void setAnioDeIngresoDelCliente(int);
  void setEstadoDelCliente(bool);
};

#endif

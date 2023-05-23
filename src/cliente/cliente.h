#ifndef PROYECTOFINAL_SRC_CLIENTE_CLIENTE_H_
#define PROYECTOFINAL_SRC_CLIENTE_CLIENTE_H_

#include <string>

class Cliente {
private:
  int numeroDeCliente;
  std::string nombreDelCliente;
  std::string apellidoDelCliente;
  bool clientePlata;
  bool clienteOro;
  bool clienteBlack;
  int anioDeIngresoDelCliente;
  bool estadoDelCliente;

public:
  Cliente(std::string, std::string);

  int getNumeroDeCliente();
  std::string getNombreDelCliente();
  std::string getApellidoDelCliente();
  bool getClientePlata();
  bool getClienteOro();
  bool getClienteBlack();
  int getAnioDeIngresoDelCliente();
  bool getEstadoDelCliente();

  void setNumeroDeCliente(int);
  void setNombreDelCliente(std::string);
  void setApellidoDelCliente(std::string);
  void setAnioDeIngresoDelCliente(int);
  void setEstadoDelCliente(bool);

  void imprimirInformacionDelCliente();

  void operator++(int);
  void operator--(int);
};

#endif

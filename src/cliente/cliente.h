#ifndef PROYECTOFINAL_SRC_CLIENTE_CLIENTE_H_
#define PROYECTOFINAL_SRC_CLIENTE_CLIENTE_H_

#include "../transaccion/transaccion.h"

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
  float dineroEnCuenta;
  int cantidadDeTransacciones;

public:
  Cliente(std::string, std::string, bool, int, float);

  int getNumeroDeCliente();
  std::string getNombreDelCliente();
  std::string getApellidoDelCliente();
  bool getClientePlata();
  bool getClienteOro();
  bool getClienteBlack();
  int getAnioDeIngresoDelCliente();
  bool getEstadoDelCliente();
  float getDineroEnCuenta();
  int getCantidadDeTransacciones();

  void setNumeroDeCliente(int);
  void setNombreDelCliente(std::string);
  void setApellidoDelCliente(std::string);
  void setAnioDeIngresoDelCliente(int);
  void setEstadoDelCliente(bool);
  void setDineroEnCuenta(float);
  void setCantidadDeTransacciones(int);

  void imprimirInformacionDelCliente();

  void operator++();
  void operator--();
  void reactivarCliente();

  void listarTodosLosClientes();

  Transaccion objTransaccionCliente[10];
};

#endif

#include "./transaccion.h"

#include <iostream>

Transaccion::Transaccion() {}
Transaccion::Transaccion(int _numeroDeTransaccion)
    : numeroDeTransaccion(_numeroDeTransaccion) {}
int Transaccion::getNumeroDeTransaccion() { return numeroDeTransaccion; }
float Transaccion::getMontoDeTransaccion() { return montoDeTransaccion; }
bool Transaccion::getExtraccion() { return extraccion; }
bool Transaccion::getDeposito() { return deposito; }
int Transaccion::getDiaDetransaccion() { return diaDeTransaccion; }
int Transaccion::getMesDeTransaccion() { return mesDeTransaccion; }
int Transaccion::getAnioDeTransaccion() { return anioDeTransaccion; }

void Transaccion::setNumeroDeTransaccion(int _numeroDeTransaccion) {
  numeroDeTransaccion = _numeroDeTransaccion;
}

void Transaccion::setMontoDeTransaccion(float _montoDeTransaccion) {
  montoDeTransaccion = _montoDeTransaccion;
}

void Transaccion::setExtraccion(bool _extraccion) { extraccion = _extraccion; }

void Transaccion::setDeposito(bool _deposito) { deposito = _deposito; }

void Transaccion::setDiaDeTransaccion(int _diaDeTransaccion) {
  diaDeTransaccion = _diaDeTransaccion;
}

void Transaccion::setMesDeTransaccion(int _mesDeTransaccion) {
  mesDeTransaccion = _mesDeTransaccion;
}

void Transaccion::setAnioDeTransaccion(int _anioDeTransaccion) {
  anioDeTransaccion = _anioDeTransaccion;
}

void Transaccion::realizarExtraccion(float *dineroEnCuenta) {
  float montoDeExtraccion = 0;
  float *pMontoDeExtraccion = &montoDeExtraccion;

  std::cout << "Ingrese la fecha de la extraccion [dia mes anio]: ";
  std::cin >> diaDeTransaccion >> mesDeTransaccion >>
      anioDeTransaccion; // agregar chequeo de anio
  std::cout << "Ingrese el monto a extraer: $";
  std::cin >> *pMontoDeExtraccion;

  if ((*dineroEnCuenta - *pMontoDeExtraccion) >= 0) {
    *dineroEnCuenta -= *pMontoDeExtraccion;
    std::cout << "La extraccion se realizo con exito.\n";
    std::cout << "Dinero restante en cuenta: $" << *dineroEnCuenta << '\n';
    montoDeTransaccion = *pMontoDeExtraccion;
  } else {
    std::cout
        << "No hay suficiente monto en la cuenta para hacer la extraccion.\n";
    std::cout << "$" << -(*dineroEnCuenta - *pMontoDeExtraccion)
              << " faltante(s) para poder realizar esta accion.\n";
  }
  extraccion = true;
  deposito = false;
}

void Transaccion::realizarDeposito(float *dineroEnCuenta) {
  float montoDeDeposito = 0;
  float *pMontoDeDeposito = &montoDeDeposito;

  std::cout << "Ingrese la fecha de la extraccion [dia mes anio]: ";
  std::cin >> diaDeTransaccion >> mesDeTransaccion >>
      anioDeTransaccion; // agregar chequeo de anio
  std::cout << "Ingrese el monto a depositar: $";
  std::cin >> *pMontoDeDeposito;

  while (*pMontoDeDeposito <= 0) {
    std::cout << "Ingrese un monto valido";
    std::cin >> *pMontoDeDeposito;
  }

  *dineroEnCuenta += *pMontoDeDeposito;
  std::cout << "El deposito de realizo con exito.\n";
  std::cout << "Dinero en cuenta: $" << *dineroEnCuenta << '\n';
  montoDeTransaccion = *pMontoDeDeposito;
  extraccion = false;
  deposito = true;
}

void Transaccion::listarTransaccion() {
  std::cout << "\tTransacion nro. " << numeroDeTransaccion << ", ";
  if (deposito && !extraccion) {
    std::cout << "deposito ";
  } else {
    std::cout << "extraccion ";
  }
  std::cout << "por el monto de $" << montoDeTransaccion << " el dia "
            << diaDeTransaccion << " / " << mesDeTransaccion << " / "
            << anioDeTransaccion << '\n';
}

void Transaccion::listarSeisMeses(int *pMesActual, int *pAnioActual) {
  int tempMes = *pMesActual, tempAnio = *pAnioActual;
  int *pTempMes = &tempMes, *pTempAnio = &tempAnio;

  *pTempMes -= 6;

  if (*pTempMes <= 0) {
    *pTempMes += 12;
    *pTempAnio -= 1;
  }

  if (*pTempMes == mesDeTransaccion && *pTempAnio == anioDeTransaccion) {
    listarTransaccion();
    std::cout << "se ejecuto el if";
  }
}

void Transaccion::ListarPorAnio(int *pAnioSeleccionado) {
  if (*pAnioSeleccionado == anioDeTransaccion) {
    listarTransaccion();
  }
}

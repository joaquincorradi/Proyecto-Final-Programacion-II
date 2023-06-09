#include "./cliente.h"

#include <iostream>
#include <string>

Cliente::Cliente(std::string _nombreDelCliente,
                 std::string _apelllidoDelCliente, bool _estadoDelCliente,
                 int _numeroDeCliente, float _dineroEnCuenta,
                 int _cantidadDeTransacciones)
    : nombreDelCliente(_nombreDelCliente),
      apellidoDelCliente(_apelllidoDelCliente),
      estadoDelCliente(_estadoDelCliente), numeroDeCliente(_numeroDeCliente),
      dineroEnCuenta(_dineroEnCuenta),
      cantidadDeTransacciones(_cantidadDeTransacciones) {}

int Cliente::getNumeroDeCliente() { return numeroDeCliente; }
std::string Cliente::getNombreDelCliente() { return nombreDelCliente; }
std::string Cliente::getApellidoDelCliente() { return apellidoDelCliente; }
int Cliente::getAnioDeIngresoDelCliente() { return anioDeIngresoDelCliente; }
bool Cliente::getClientePlata() { return clientePlata; }
bool Cliente::getClienteOro() { return clienteOro; }
bool Cliente::getClienteBlack() { return clienteBlack; }
bool Cliente::getEstadoDelCliente() { return estadoDelCliente; }
float Cliente::getDineroEnCuenta() { return dineroEnCuenta; }
int Cliente::getCantidadDeTransacciones() { return cantidadDeTransacciones; }

void Cliente::setNumeroDeCliente(int _numeroDelCliente) {
  numeroDeCliente = _numeroDelCliente;
}
void Cliente::setNombreDelCliente(std::string _nombreDelCliente) {
  nombreDelCliente = _nombreDelCliente;
}
void Cliente::setApellidoDelCliente(std::string _apellidoDelCliente) {
  apellidoDelCliente = _apellidoDelCliente;
}

void Cliente::setClientePlata(bool _clientePlata) {
  clientePlata = _clientePlata;
}
void Cliente::setClienteOro(bool _clienteOro) { clienteOro = _clienteOro; }
void Cliente::setClienteBlack(bool _clienteBlack) {
  clienteBlack = _clienteBlack;
}

void Cliente::setAnioDeIngresoDelCliente(int _anioDeIngresoDelCliente) {
  anioDeIngresoDelCliente = _anioDeIngresoDelCliente;
}
void Cliente::setEstadoDelCliente(bool _estadoDelCliente) {
  estadoDelCliente = _estadoDelCliente;
}
void Cliente::setDineroEnCuenta(float _dineroEnCuenta) {
  dineroEnCuenta = _dineroEnCuenta;
}
void Cliente::setCantidadDeTransacciones(int _cantidadDeTransacciones) {
  cantidadDeTransacciones = _cantidadDeTransacciones;
}

void Cliente::imprimirInformacionDelCliente() {
  std::cout << "- Cliente numero: " << numeroDeCliente << '\n';
  std::cout << "- Nombre y apellido: " << nombreDelCliente << " "
            << apellidoDelCliente << '\n';
  std::cout << "- Beneficiario de la categoria ";
  if (clientePlata) {
    std::cout << "plata\n";
  } else if (clienteOro) {
    std::cout << "oro\n";
  } else {
    std::cout << "black\n";
  }
  std::cout << "- Anio de ingreso: " << anioDeIngresoDelCliente << '\n';
  std::cout << "- Estado del cliente: ";
  if (estadoDelCliente) {
    std::cout << "activo\n";
  } else {
    std::cout << "inactivo\n";
  }
  std::cout << "- Dinero en cuenta: $" << dineroEnCuenta << '\n';
}

void Cliente::operator++() {
  std::string respuestaACategoria;
  bool NaN = false;

  std::cout << "Alta de nuevo cliente:\n\n";
  std::cout << "Ingrese nombre: ";
  std::cin >> nombreDelCliente;
  std::cout << "Ingrese apellido: ";
  std::cin >> apellidoDelCliente;
  do {
    try {
      std::cout << "Ingrese el anio de ingreso: ";
      std::cin >> anioDeIngresoDelCliente;

      if (std::cin.fail()) {
        throw 1;
      } else {
        NaN = false;
      }
    } catch (int e) {
      NaN = true;
      std::cout << "Por favor, ingrese un numero.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (NaN);
  std::cout << "¿Que categoria posee el cliente? [plata/oro/black]: ";
  std::cin >> respuestaACategoria;

  while ((2023 - anioDeIngresoDelCliente) < 3 &&
         respuestaACategoria == "black") {
    std::cout << "\nEl cliente " << nombreDelCliente << " "
              << apellidoDelCliente << " tiene una antiguedad de "
              << (2023 - anioDeIngresoDelCliente) << " anio(s).\n";
    std::cout << "Solo los clientes con mas de 3 anios de antiguedad pueden "
                 "acceder a los beneficios de la categoria 'black'.\n";
    std::cout << "Por favor ingrese una categoria correcta para continuar "
                 "[plata/oro]: ";
    std::cin >> respuestaACategoria;
  }
  if (respuestaACategoria == "plata" || respuestaACategoria == "Plata") {
    clientePlata = true;
    clienteOro = false;
    clienteBlack = false;
  } else if (respuestaACategoria == "oro" || respuestaACategoria == "Oro") {
    clientePlata = false;
    clienteOro = true;
    clienteBlack = false;
  } else if (respuestaACategoria == "black" || respuestaACategoria == "Black") {
    clientePlata = false;
    clienteOro = false;
    clienteBlack = true;
  } else {
    std::cout << "Ingreso una opcion incorrecta. El sistema autoasignara plata "
                 "al cliente.\n";
    /* corregir esto y ponerlo adentro de un do while para que el usuario pueda
     * volver a ingresar una opcion */
    clientePlata = true;
    clienteOro = false;
    clienteBlack = false;
  }
  estadoDelCliente = true;
  if (estadoDelCliente) {
    std::cout << "¡Cliente creado con exito!\n\n";
    std::cout << "Resumen del cliente dado de alta: \n";
    imprimirInformacionDelCliente();
  } else {
    std::cout << "Ocurrio un error.\n";
  }
}

void Cliente::operator--() {
  std::cout << "Se procedera a dar de baja al cliente " << nombreDelCliente
            << " " << apellidoDelCliente << '\n';
  estadoDelCliente = false;
  dineroEnCuenta = 0.0;
  if (!estadoDelCliente) {
    std::cout << "La baja fue realizada con exito.\n";
  } else {
    std::cout << "Ocurrio un error.\n";
  }
}

void Cliente::listarTodosLosClientes() {
  std::cout << " - [Nro. " << numeroDeCliente << "] " << nombreDelCliente << " "
            << apellidoDelCliente << ", "
            << "estado: ";
  if (estadoDelCliente) {
    std::cout << "activo. ";
    std::cout << "- Dinero en cuenta: $" << dineroEnCuenta << '\n';
  } else {
    std::cout << "inactivo.\n";
  }
}

void Cliente::reactivarCliente() {
  if (estadoDelCliente == false) {
    std::cout << "Se procedera a reactivar al cliente " << nombreDelCliente
              << " " << apellidoDelCliente << '\n';
    estadoDelCliente = true;
    if (estadoDelCliente) {
      std::cout << "Se reactivo el cliente con exito.\n";
    } else {
      std::cout << "Ocurrio un error y no se pudo reactivar al cliente.\n";
    }
  } else {
    std::cout << "El cliente ya se encuentra activo.\n";
  }
}

void Cliente::listarTransaccionesDelCliente() {
  for (int i = 0; i <= cantidadDeTransacciones; ++i) {
    objTransaccionCliente[i].listarTransaccion();
  }
}

void Cliente::listarTransaccionesDelClienteSeisMeses(int *pMesActual,
                                                     int *pAnioActual) {
  std::cout << "- Transacciones para el cliente " << nombreDelCliente << " "
            << apellidoDelCliente << " en los ultimos seis meses: \n";
  for (int i = 0; i <= cantidadDeTransacciones; ++i) {
    objTransaccionCliente[i].listarSeisMeses(pMesActual, pAnioActual);
  }
}

void Cliente::listarTransaccionesDelClientePorAnio(int *pAnioSeleccionado) {
  std::cout << "- Transacciones para el cliente " << nombreDelCliente << " "
            << apellidoDelCliente << " para el anio seleccionado: \n";
  for (int i = 0; i <= cantidadDeTransacciones; ++i) {
    objTransaccionCliente[i].ListarPorAnio(pAnioSeleccionado);
  }
}

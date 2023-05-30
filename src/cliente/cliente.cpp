#include "./cliente.h"

#include <iostream>
#include <string>

Cliente::Cliente(std::string _nombreDelCliente, std::string _apelllidoDelCliente, bool _estadoDelCliente, int _numeroDeCliente, float _dineroEnCuenta) : nombreDelCliente(_nombreDelCliente), apellidoDelCliente(_apelllidoDelCliente), estadoDelCliente(_estadoDelCliente), numeroDeCliente(_numeroDeCliente), dineroEnCuenta(_dineroEnCuenta) {}

int Cliente::getNumeroDeCliente() { return numeroDeCliente; }
std::string Cliente::getNombreDelCliente() { return nombreDelCliente; }
std::string Cliente::getApellidoDelCliente() { return apellidoDelCliente; }
int Cliente::getAnioDeIngresoDelCliente() { return anioDeIngresoDelCliente; }
bool Cliente::getClientePlata() { return clientePlata; }
bool Cliente::getClienteOro() { return clienteOro; }
bool Cliente::getClienteBlack() { return clienteBlack; }
bool Cliente::getEstadoDelCliente() { return estadoDelCliente; }
float Cliente::getDineroEnCuenta() { return dineroEnCuenta; }

void Cliente::setNumeroDeCliente(int _numeroDelCliente) {
  numeroDeCliente = _numeroDelCliente;
}
void Cliente::setNombreDelCliente(std::string _nombreDelCliente) {
  nombreDelCliente = _nombreDelCliente;
}
void Cliente::setApellidoDelCliente(std::string _apellidoDelCliente) {
  apellidoDelCliente = _apellidoDelCliente;
}
void Cliente::setAnioDeIngresoDelCliente(int _anioDeIngresoDelCliente) {
  anioDeIngresoDelCliente = _anioDeIngresoDelCliente;
}
void Cliente::setEstadoDelCliente(bool _estadoDelCliente) {
  estadoDelCliente = _estadoDelCliente;
}
void Cliente::setDineroEnCuenta(float _dineroEnCuenta) { dineroEnCuenta = _dineroEnCuenta; }


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
}

void Cliente::operator++() {
  std::string respuestaACategoria;
  std::cout << "Alta de nuevo cliente:\n\n";
  std::cout << "Ingrese nombre: ";
  std::cin >> nombreDelCliente;
  std::cout << "Ingrese apellido: ";
  std::cin >> apellidoDelCliente;
  std::cout << "Ingrese el anio de ingreso: ";
  std::cin >> anioDeIngresoDelCliente;
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
  if (respuestaACategoria == "plata") {
    clientePlata = true;
    clienteOro = false;
    clienteBlack = false;
  } else if (respuestaACategoria == "oro") {
    clientePlata = false;
    clienteOro = true;
    clienteBlack = false;
  } else {
    clientePlata = false;
    clienteOro = false;
    clienteBlack = true;
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
  std::cout << "Lista de clientes: \n\n";
  std::cout << " - [Nro. " << numeroDeCliente << "] " << nombreDelCliente << " "
            << apellidoDelCliente << ", "
            << "estado: ";
  if (estadoDelCliente) {
    std::cout << "activo.\n";
    std::cout << "- Dinero en cuenta: $" << dineroEnCuenta << '\n';
  } else {
    std::cout << "inactivo.\n";
  }
}

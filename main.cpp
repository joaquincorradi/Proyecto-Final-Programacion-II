#include "src/cliente/cliente.h"
#include <iostream>

void mostrarMenu(char &seleccionDelMenu);
void primeraOpcion(Cliente cliente);

int main() {
  Cliente obj("nombre", "apellido");
  obj++;
  obj--;
  obj.imprimirInformacionDelCliente();
}

void mostrarMenu(char &seleccionDelMenu) {
  std::cout
      << "\n==============================================================\n";
  std::cout
      << "  ____  _ _ __     __          _ _     ____              _     \n"
         " | __ )(_) |\\ \\   / /_ _ _   _| | |_  | __ )  __ _ _ __ | | __ \n"
         " |  _ \\| | __\\ \\ / / _` | | | | | __| |  _ \\ / _` | '_ \\| |/ / "
         "\n"
         " | |_) | | |_ \\ V / (_| | |_| | | |_  | |_) | (_| | | | |   <  \n"
         " |____/|_|\\__| \\_/ \\__,_|\\__,_|_|\\__| |____/ \\__,_|_| "
         "|_|_|\\_\\ \n\n";
  std::cout << "'Protegiendo sus activos digitales.'\n\n";
  std::cout
      << "==============================================================\n\n";
  std::cout << "Bienvenido. Para continuar seleccione una opcion:\n\n";
  std::cout << "[1] Alta de cliente.\n";
  std::cout << "[2] Baja de cliente.\n";
  std::cout << "[3] Generar extraccion.\n";
  std::cout << "[4] Generar deposito.\n";
  std::cout << "[5] Consultar cliente.\n";
  std::cout << "[6] Listar todos los clientes.\n";
  std::cout << "[7] Listar transacciones por clientes.\n";
  std::cout << "[8] Filtrar transacciones y depositos por periodo.\n";
  std::cout << "[9] Salir.\n\n";
  std::cout
      << "--------------------------------------------------------------\n";
  std::cout << "Ingrese su eleccion: ";
  std::cin >> seleccionDelMenu;
}

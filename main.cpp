#include "src/cliente/cliente.h"
#include <iostream>

void mostrarMenu(char *pSeleccionDelMenuPrincipal);
void opcion1(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion2(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion5(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion6(Cliente *objCliente[20], int *pContadorCantidadCliente);

int main() {
  Cliente *objCliente[20];
  for (int i = 0; i < 20; ++i) {
    objCliente[i] = new Cliente("sin", "datos", false, i + 1);
  }

  // Variables y punteros necesarios para las funciones:
  int contadorCantidadCliente = -1;
  int *pContadorCantidadCliente = &contadorCantidadCliente;

  char seleccionDelMenuPrincipal;
  char *pSeleccionDelMenuPrincipal;

  opcion1(objCliente, pContadorCantidadCliente);
  opcion1(objCliente, pContadorCantidadCliente);
  opcion1(objCliente, pContadorCantidadCliente);
  opcion6(objCliente, pContadorCantidadCliente);
  opcion2(objCliente, pContadorCantidadCliente);
  opcion6(objCliente, pContadorCantidadCliente);

  for (int i = 0; i < 20; ++i) {
    delete objCliente[i];
    objCliente[i] = nullptr;
  }
}

void mostrarMenu(char *pSeleccionDelMenuPrincipal) {
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
  std::cout << "'Protegiendo sus activos digitales.~'\n\n";
  std::cout
      << "==============================================================\n\n";
  std::cout << "Bienvenido. Para continuar seleccione una opcion:\n\n";
  std::cout << "[1] Alta de cliente.\n";
  std::cout << "[2] Baja de cliente.\n";
  std::cout << "[3] Generar extraccion.\n";
  std::cout << "[4] Generar deposito.\n";
  std::cout << "[5] Consultar cliente por numero de cliente.\n";
  std::cout << "[6] Listar todos los clientes.\n";
  std::cout << "[7] Listar transacciones por clientes.\n";
  std::cout << "[8] Filtrar transacciones y depositos por periodo.\n";
  std::cout << "[9] Salir.\n\n";
  std::cout
      << "--------------------------------------------------------------\n";
  std::cout << "Ingrese su eleccion: ";
  std::cin >> *pSeleccionDelMenuPrincipal;
}

void opcion1(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  ++*pContadorCantidadCliente;
  objCliente[*pContadorCantidadCliente]->setNumeroDeCliente(
      *pContadorCantidadCliente);
  ++*objCliente[*pContadorCantidadCliente];
}

void opcion2(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  int eleccionDelUsuario = 0;
  int *pEleccionDelUsuario = &eleccionDelUsuario;
  bool existeElUsuario = true;
  bool *pExisteElUsuario = &existeElUsuario;

  std::cout << "Ingrese numero del usuario que desea dar de baja: ";
  std::cin >> *pEleccionDelUsuario;
  for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
    if (*pEleccionDelUsuario == objCliente[i]->getNumeroDeCliente() &&
        objCliente[i]->getEstadoDelCliente()) {
      --*objCliente[i];
      *pExisteElUsuario = true;
    }
  }
  if (!*pExisteElUsuario) {
    std::cout << "El cliente ingresado no existe o no se encuentra activo. \n";
  }
}

void opcion5(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  int numeroDeClienteElegido = 0;
  std::cout << "Consulta de cliente por numero de cliente.\n\n";
  std::cout << "Ingrese un numero de cliente para consultar: ";
  std::cin >> numeroDeClienteElegido;
  std::cout << '\n';
  if (numeroDeClienteElegido > *pContadorCantidadCliente) {
    std::cout << "\nNo hay cliente con el numero " << numeroDeClienteElegido
              << " de cliente.\n";
  } else {
    for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
      if (numeroDeClienteElegido == objCliente[i]->getNumeroDeCliente()) {
        objCliente[i]->imprimirInformacionDelCliente();
      }
    }
  }
}

void opcion6(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
    objCliente[i]->listarTodosLosClientes();
  }
}

/*
  To do list:
  - Crear funcion 9 (filtrar transacciones).
  - Realizar chequeos de fechas.
  - Chequear que palabra ingresa el usuario como categoria.
  - Se puede extaer plata del futuro en el pasado.
  - Crear tarjeta de credito.
*/

#include "src/archivo/archivo.h"
#include "src/cliente/cliente.h"

#include <cstdlib>
#include <iostream>

void mostrarMenu(int *pSeleccionDelMenuPrincipal);
void obtenerFechaDeHoy(int *diaActual, int *mesActual, int *anioActual);
void opcion1(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion2(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion3(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion4(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *pContadorNroTransaccion);
void opcion5(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *pContadorNroTransaccion);
void opcion6(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion7(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion8(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion9(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *mesActual, int *anioActual);
void incializarMenu();

int main() { incializarMenu(); }

void mostrarMenu(int *pSeleccionDelMenuPrincipal) {
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
  std::cout << "[3] Reactivar cliente.\n";
  std::cout << "[4] Generar extraccion.\n";
  std::cout << "[5] Generar deposito.\n";
  std::cout << "[6] Consultar cliente por numero de cliente.\n";
  std::cout << "[7] Listar todos los clientes.\n";
  std::cout << "[8] Listar transacciones por numero de clientes.\n";
  std::cout << "[9] Filtrar transacciones y depositos por periodo.\n";
  std::cout << "[10] Salir.\n\n";
  std::cout
      << "--------------------------------------------------------------\n";
  std::cout << "Ingrese su eleccion: ";
  std::cin >> *pSeleccionDelMenuPrincipal;
}

void obtenerFechaDeHoy(int *diaActual, int *mesActual, int *anioActual) {
  std::cout << "Bienvenido al software del banco BitVault. Antes de continuar "
               "ingrese la fecha de hoy.\n";

  std::cout << "Ingrese el dia de hoy (numero): ";
  std::cin >> *diaActual;
  while (*diaActual <= 0 || *diaActual > 31) {
    std::cout << "\nIngrese un dia valido.\n";
    std::cout << "Ingrese el dia de hoy (numero): ";
    std::cin >> *diaActual;
  }

  std::cout << "Ingrese el mes actual (numero): ";
  std::cin >> *mesActual;
  while (*mesActual <= 0 || *mesActual > 12) {
    std::cout << "\nIngrese un mes valido.\n";
    std::cout << "Ingrese el mes actual (numero): ";
    std::cin >> *mesActual;
  }

  std::cout << "Ingrese el anio actual (numero): ";
  std::cin >> *anioActual;
  while (*anioActual < 1900 || *anioActual > 2023) {
    std::cout
        << "\nIngrese una fecha valida. Nuestros datos van del 1900 al 2023.\n";
    std::cout << "Ingrese el anio actual (numero): ";
    std::cin >> *anioActual;
  }
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

void opcion3(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  int eleccionDelUsuario = 0;
  int *pEleccionDelUsuario = &eleccionDelUsuario;

  bool existeElUsuario = false;
  bool *pExisteElUsuario = &existeElUsuario;

  std::cout << "Ingrese numero del usuario que desea reactivar: ";
  std::cin >> *pEleccionDelUsuario;

  for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
    // A continuacion busca coincidencia con el cliente que ingreso el usuario
    if (*pEleccionDelUsuario == objCliente[i]->getNumeroDeCliente()) {
      objCliente[i]->reactivarCliente();
      *pExisteElUsuario = true;
    }
  }
  if (!*pExisteElUsuario) {
    std::cout << "El cliente ingresado no existe.\n";
  }
}

void opcion4(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *pContadorNroTransaccion) {
  int numeroDeClienteElegido = 0;
  int *pNumeroDeClienteElegido = &numeroDeClienteElegido;

  bool chequeoDeExistencia = false;
  bool *pChequeoDeExistencia = &chequeoDeExistencia;

  std::cout << "Extraccion de dinero.\n\n";
  std::cout << "Ingrese el numero de cliente para realizar una extraccion: ";
  std::cin >> *pNumeroDeClienteElegido;

  // Chequeo previo para ver si el usuario existe
  for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
    if (*pNumeroDeClienteElegido == objCliente[i]->getNumeroDeCliente() &&
        objCliente[i]->getEstadoDelCliente()) {
      *pChequeoDeExistencia = true;
    }
  }
  if (*pChequeoDeExistencia) {
    for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
      /*- Se compara cada lugar del array buscando una coincidencia con el
      numero que ingreso el usuario.
      - Se chequea si el cliente existe y si esta activo.*/
      if (*pNumeroDeClienteElegido == objCliente[i]->getNumeroDeCliente() &&
          objCliente[i]->getEstadoDelCliente()) {
        // Se hace lo siguiente para poder usar '++'
        /*tempCantidadDeTransacciones es el contador interno de la clase
        para aumentar la posicion del objeto transaccion que esta adentro
        de ella*/
        int tempCantidadDeTrasancciones =
            objCliente[i]->getCantidadDeTransacciones();
        int *pTempCantidadDeTrasacciones = &tempCantidadDeTrasancciones;

        ++*pTempCantidadDeTrasacciones;
        ++*pContadorNroTransaccion;

        float dineroEnCuentaTemp = objCliente[i]->getDineroEnCuenta();
        float *pDineroEnCuentaTemp = &dineroEnCuentaTemp;

        objCliente[i]
            ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
            .realizarExtraccion(pDineroEnCuentaTemp);
        objCliente[i]
            ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
            .setNumeroDeTransaccion(*pContadorNroTransaccion);
        objCliente[i]->setCantidadDeTransacciones(*pTempCantidadDeTrasacciones);
        objCliente[i]->setDineroEnCuenta(*pDineroEnCuentaTemp);
      }
    }
  } else {
    std::cout << "El usuario nro. " << *pNumeroDeClienteElegido
              << " no existe o esta inactivo.\n";
  }
}

void opcion5(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *pContadorNroTransaccion) {
  int numeroDeClienteElegido = 0;
  int *pNumeroDeClienteElegido = &numeroDeClienteElegido;

  bool chequeoDeExistencia = false;
  bool *pChequeoDeExistencia = &chequeoDeExistencia;

  std::cout << "Deposito  de dinero.\n\n";
  std::cout << "Ingrese el numero de cliente para realizar una deposito: ";
  std::cin >> *pNumeroDeClienteElegido;

  // Chequeo previo para ver si el usuario existe
  for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
    if (*pNumeroDeClienteElegido == objCliente[i]->getNumeroDeCliente() &&
        objCliente[i]->getEstadoDelCliente()) {
      *pChequeoDeExistencia = true;
    }
  }
  if (*pChequeoDeExistencia) {
    for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
      /*- Se compara cada lugar del array buscando una coincidencia con el
      numero que ingreso el usuario.
      - Se chequea si el cliente existe y si esta activo.*/
      if (*pNumeroDeClienteElegido == objCliente[i]->getNumeroDeCliente() &&
          objCliente[i]->getEstadoDelCliente()) {
        // Se hace lo siguiente para poder usar '++'
        int tempCantidadDeTrasancciones =
            objCliente[i]->getCantidadDeTransacciones();
        int *pTempCantidadDeTrasacciones = &tempCantidadDeTrasancciones;

        ++*pTempCantidadDeTrasacciones;
        ++*pContadorNroTransaccion;

        float dineroEnCuentaTemp = objCliente[i]->getDineroEnCuenta();
        float *pDineroEnCuentaTemp = &dineroEnCuentaTemp;

        objCliente[i]
            ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
            .realizarDeposito(pDineroEnCuentaTemp);
        objCliente[i]
            ->objTransaccionCliente[*pTempCantidadDeTrasacciones]
            .setNumeroDeTransaccion(*pContadorNroTransaccion);
        objCliente[i]->setCantidadDeTransacciones(*pTempCantidadDeTrasacciones);
        objCliente[i]->setDineroEnCuenta(*pDineroEnCuentaTemp);
      }
    }
  } else {
    std::cout << "El usuario nro. " << *pNumeroDeClienteElegido
              << " no existe o esta inactivo.\n";
  }
}

void opcion6(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  int numeroDeClienteElegido = 0; // hacer de esta variable un puntero
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

void opcion7(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
    objCliente[i]->listarTodosLosClientes();
  }
}

void opcion8(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  int numeroDeClienteElegido = 0;
  int *pNumeroDeClienteElegido = &numeroDeClienteElegido;

  bool chequeoDeExistencia = false;
  bool *pChequeoDeExistencia = &chequeoDeExistencia;

  std::cout << "Consulta de transacciones por numero de cliente.\n\n";
  std::cout << "Ingrese un numero de cliente para consultar: ";
  std::cin >> *pNumeroDeClienteElegido;

  for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
    if (*pNumeroDeClienteElegido == objCliente[i]->getNumeroDeCliente()) {
      *pChequeoDeExistencia = true;
    }
  }
  if (*pChequeoDeExistencia) {
    for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
      if (*pNumeroDeClienteElegido == objCliente[i]->getNumeroDeCliente()) {
        std::cout << "Mostrando transacciones para el cliente nro. "
                  << objCliente[i]->getNumeroDeCliente() << ", "
                  << objCliente[i]->getNombreDelCliente() << " "
                  << objCliente[i]->getApellidoDelCliente() << ":\n";
        objCliente[i]->listarTransaccionesDelCliente();
      }
    }
  } else {
    std::cout << "El usuario nro. " << *pNumeroDeClienteElegido
              << " no existe.\n";
  }
}

void opcion9(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *mesActual, int *anioActual) {
  int numeroDeClienteElegido = 0;
  int *pNumeroDeClienteElegido = &numeroDeClienteElegido;

  bool chequeoDeExistencia = false;
  bool *pChequeoDeExistencia = &chequeoDeExistencia;

  int eleccionDelUsuarioSubmenu = 0;
  int *pEleccionDelUsuarioSubmenu = &eleccionDelUsuarioSubmenu;

  std::cout << "Filtrar transacciones y depositos por periodo.\n";
  std::cout << "Para continuar seleccione una opcion:\n\n";
  std::cout << "[1] Mostrar transacciones en los ultimos 6 meses.\n";
  std::cout << "[2] Filtrar transacciones por anio\n";
  std::cout << "[3] Mostrar todas las transacciones.\n\n";
  std::cout << "Ingrese su eleccion: ";
  std::cin >> *pEleccionDelUsuarioSubmenu;

  switch (*pEleccionDelUsuarioSubmenu) {
  case 1:
    for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
      objCliente[i]->listarTransaccionesDelClienteSeisMeses(mesActual, anioActual);
    }
    break;

    case 3:
      for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
        objCliente[i]->listarTransaccionesDelCliente();
      }

  default:
    std::cout << "La opcion seleccionada no es valida.\n";
    break;
  }
}

void incializarMenu() {
  Cliente *objCliente[20];
  for (int i = 0; i < 20; ++i) {
    objCliente[i] = new Cliente("sin", "datos", false, i + 1, 0.0, -1);
  }

  Archivo *objArchivo;
  objArchivo = new Archivo("db/clientes.txt", "db/transacciones.txt");

  // Variables para el menu
  char seleccionDelUsuarioFinal = 's';
  char *pSeleccionDelUsuarioFinal = &seleccionDelUsuarioFinal;

  bool quiereSalir = false;
  bool *pQuiereSalir = &quiereSalir;

  // Variables y punteros necesarios para las funciones:
  int contadorCantidadCliente = -1;
  int *pContadorCantidadCliente = &contadorCantidadCliente;

  int contadorNroTransaccion = -1;
  int *pContadorNroTransaccion = &contadorNroTransaccion;

  int seleccionDelMenuPrincipal;
  int *pSeleccionDelMenuPrincipal = &seleccionDelMenuPrincipal;

  int diaActual = 1, mesActual = 1, anioActual = 1900;
  int *pDiaActual = &diaActual, *pMesActual = &mesActual,
      *pAnioActual = &anioActual;

  objArchivo->iniciarNuevoArchivo();
  objArchivo->cargarDesdeArchivo(pContadorCantidadCliente, objCliente,
                                 pContadorNroTransaccion);

  obtenerFechaDeHoy(pDiaActual, pMesActual, pAnioActual);
  std::cout << std::flush;
  system("cls||clear");

  while (*pSeleccionDelUsuarioFinal == 's' ||
         *pSeleccionDelUsuarioFinal == 'S') {
    mostrarMenu(pSeleccionDelMenuPrincipal);
    std::cout << std::flush;
    system("cls||clear"); // para limpiar la terminal cada vez que ejecutamos
                          // una opcion
    switch (*pSeleccionDelMenuPrincipal) {
    case 1:
      opcion1(objCliente, pContadorCantidadCliente);
      objArchivo->actualizarArchivoClientes(objCliente, pContadorCantidadCliente);
      break;

    case 2:
      opcion2(objCliente, pContadorCantidadCliente);
      break;

    case 3:
      opcion3(objCliente, pContadorCantidadCliente);

      break;

    case 4:
      opcion4(objCliente, pContadorCantidadCliente, pContadorNroTransaccion);
      break;

    case 5:
      opcion5(objCliente, pContadorCantidadCliente, pContadorNroTransaccion);
      break;

    case 6:
      opcion6(objCliente, pContadorCantidadCliente);

      break;

    case 7:
      opcion7(objCliente, pContadorCantidadCliente);
      break;

    case 8:
      opcion8(objCliente, pContadorCantidadCliente);
      break;

    case 9:
      opcion9(objCliente, pContadorCantidadCliente, pMesActual, pAnioActual);
      break;

    case 10:
      *pQuiereSalir = true;
      break;

    default:
      std::cout << "La opcion seleccionada no es valida.\n";
      break;
    }

    /*Como el usuario no eligio la opcion de salir entonces se ejecuto
     algunas de las opciones del menu, por lo tanto despues de que se
     termino esa ejecucion se le pregunta si quiere salir.*/
    if (!*pQuiereSalir) {
      std::cout << "¿Desea volver al menu principal? [S/n]: ";
     
      std::cin >> *pSeleccionDelUsuarioFinal;

      if (*pSeleccionDelUsuarioFinal == 's' ||
          *pSeleccionDelUsuarioFinal == 'S') {
        system("cls||clear");
      }
    } else {
      *pSeleccionDelUsuarioFinal = 'n';
    }
  }

  for (int i = 0; i < 20; ++i) {
    delete objCliente[i];
    objCliente[i] = nullptr;
  }
  delete objArchivo;
}

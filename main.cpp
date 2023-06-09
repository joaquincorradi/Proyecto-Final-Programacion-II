/*
  To do list:
  - Opcion 1 de opcion9() no funciona.
  - Transaccion extra al cargar de transacciones.txt
*/

#include "src/archivo/archivo.h"
#include "src/cliente/cliente.h"

#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept> // libreria para que funcione el catch

void mostrarMenu(int *pSeleccionDelMenuPrincipal, int *diaActual,
                 int *mesActual, int *anioActual);
void obtenerFechaDeHoy(int *diaActual, int *mesActual, int *anioActual);
void opcion1(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion2(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion3(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion4(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *pContadorNroTransaccion, Archivo *objArchivo);
void opcion5(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *pContadorNroTransaccion, Archivo *objArchivo);
void opcion6(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion7(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion8(Cliente *objCliente[20], int *pContadorCantidadCliente);
void opcion9(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *mesActual, int *anioActual);
void incializarMenu();

int main() { incializarMenu(); }

void mostrarMenu(int *pSeleccionDelMenuPrincipal, int *diaActual,
                 int *mesActual, int *anioActual) {
  bool NaN = false; // este bool es para los try y catch

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
  std::cout << "Bienvenido. Hoy es " << *diaActual << " / " << *mesActual
            << " / " << *anioActual << ".\n";
  std::cout << "Para continuar seleccione una opcion:\n\n";
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

  do {
    try {
      std::cout << "Ingrese su eleccion: ";
      std::cin >> *pSeleccionDelMenuPrincipal;

      if (std::cin.fail()) {
        throw 1;
      } else {
        NaN = false;
      }
    } catch (int e) {
      NaN = true;
      std::cout << "Por favor, ingrese un numero.\n";
      std::cin.clear(); // limpia el error
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n'); // limpia los caracteres guardados
    }
  } while (NaN);
}

void obtenerFechaDeHoy(int *diaActual, int *mesActual, int *anioActual) {
  bool NaN = false;

  std::cout << "Bienvenido al software del banco BitVault. Antes de continuar "
               "ingrese la fecha de hoy.\n";
  do {
    try {
      std::cout << "Ingrese el dia de hoy (numero): ";
      std::cin >> *diaActual;

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

  while (*diaActual <= 0 || *diaActual > 31) {
    std::cout << "\nIngrese un dia valido.\n";
    std::cout << "Ingrese el dia de hoy (numero): ";
    std::cin >> *diaActual;
  }

  do {
    try {
      std::cout << "Ingrese el mes actual (numero): ";
      std::cin >> *mesActual;
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

  while (*mesActual <= 0 || *mesActual > 12) {
    std::cout << "\nIngrese un mes valido.\n";
    std::cout << "Ingrese el mes actual (numero): ";
    std::cin >> *mesActual;
  }

  do {
    try {
      std::cout << "Ingrese el anio actual (numero): ";
      std::cin >> *anioActual;
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
  bool NaN = false;

  do {
    try {
      std::cout << "Ingrese numero del usuario que desea dar de baja: ";
      std::cin >> *pEleccionDelUsuario;
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

  for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
    if (*pEleccionDelUsuario == objCliente[i]->getNumeroDeCliente() &&
        objCliente[i]->getEstadoDelCliente()) {
      --*objCliente[i];
      *pExisteElUsuario = true;
    }
  }
  if (!*pExisteElUsuario) {
    std::cout << "El cliente ingresado no existe o no se encuentra activo. \n";
  } else if (*pContadorCantidadCliente == -1) {
    std::cout
        << "\nAntes de realizar esta accion tiene que crear un cliente. \n";
  }
}

void opcion3(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  int eleccionDelUsuario = 0;
  int *pEleccionDelUsuario = &eleccionDelUsuario;

  bool existeElUsuario = false;
  bool *pExisteElUsuario = &existeElUsuario;

  bool NaN = false;

  do {
    try {
      std::cout << "Ingrese numero del usuario que desea reactivar: ";
      std::cin >> *pEleccionDelUsuario;
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
             int *pContadorNroTransaccion, Archivo *objArchivo) {
  int numeroDeClienteElegido = 0;
  int *pNumeroDeClienteElegido = &numeroDeClienteElegido;

  bool chequeoDeExistencia = false;
  bool *pChequeoDeExistencia = &chequeoDeExistencia;

  bool NaN = false;

  std::cout << "Extraccion de dinero.\n\n";

  do {
    try {
      std::cout
          << "Ingrese el numero de cliente para realizar una extraccion: ";
      std::cin >> *pNumeroDeClienteElegido;
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

        objArchivo->actualizarArchivoTransacciones(
            objCliente, pNumeroDeClienteElegido, pTempCantidadDeTrasacciones,
            pContadorNroTransaccion);
      }
    }
  } else {
    std::cout << "El usuario nro. " << *pNumeroDeClienteElegido
              << " no existe o esta inactivo.\n";
  }
}

void opcion5(Cliente *objCliente[20], int *pContadorCantidadCliente,
             int *pContadorNroTransaccion, Archivo *objArchivo) {
  int numeroDeClienteElegido = 0;
  int *pNumeroDeClienteElegido = &numeroDeClienteElegido;

  bool chequeoDeExistencia = false;
  bool *pChequeoDeExistencia = &chequeoDeExistencia;

  bool NaN = false;

  std::cout << "Deposito  de dinero.\n\n";

  do {
    try {
      std::cout << "Ingrese el numero de cliente para realizar una deposito: ";
      std::cin >> *pNumeroDeClienteElegido;
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

        objArchivo->actualizarArchivoTransacciones(
            objCliente, pNumeroDeClienteElegido, pTempCantidadDeTrasacciones,
            pContadorNroTransaccion);
      }
    }
  } else {
    std::cout << "El usuario nro. " << *pNumeroDeClienteElegido
              << " no existe o esta inactivo.\n";
  }
}

void opcion6(Cliente *objCliente[20], int *pContadorCantidadCliente) {
  int numeroDeClienteElegido = 0; // hacer de esta variable un puntero
  bool NaN = false;

  std::cout << "Consulta de cliente por numero de cliente.\n\n";

  do {
    try {
      std::cout << "Ingrese un numero de cliente para consultar: ";
      std::cin >> numeroDeClienteElegido;

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

  bool NaN = false;

  std::cout << "Consulta de transacciones por numero de cliente.\n\n";

  do {
    try {
      std::cout << "Ingrese un numero de cliente para consultar: ";
      std::cin >> *pNumeroDeClienteElegido;

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

  int anioSeleccionado;
  int *pAnioSeleccionado = &anioSeleccionado;

  bool NaN2 = false;
  bool NaN = 0;

  std::cout << "Filtrar transacciones y depositos por periodo.\n";
  std::cout << "Para continuar seleccione una opcion:\n\n";
  std::cout << "[1] Mostrar transacciones en los ultimos 6 meses.\n";
  std::cout << "[2] Filtrar transacciones por anio\n";
  std::cout << "[3] Mostrar todas las transacciones.\n\n";

  do {
    try {
      std::cout << "Ingrese su eleccion: ";
      std::cin >> *pEleccionDelUsuarioSubmenu;

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

  switch (*pEleccionDelUsuarioSubmenu) {
  case 1:
    for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
      objCliente[i]->listarTransaccionesDelClienteSeisMeses(mesActual,
                                                            anioActual);
    }
    break;

  case 2:
    do {
      try {
        std::cout << "Ingrese un anio para consultar: ";
        std::cin >> *pAnioSeleccionado;

        if (std::cin.fail()) {
          throw 1;
        } else {
          NaN2 = false;
        }
      } catch (int e) {
        NaN2 = true;
        std::cout << "Por favor, ingrese un numero.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    } while (NaN2);

    for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
      objCliente[i]->listarTransaccionesDelClientePorAnio(pAnioSeleccionado);
    }
    break;

  case 3:
    for (int i = 0; i <= *pContadorCantidadCliente; ++i) {
      objCliente[i]->listarTransaccionesDelCliente();
    }
    break;

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
  objArchivo->cargarDesdeArchivoClientes(pContadorCantidadCliente, objCliente);
  objArchivo->cargarDesdeArchivoTransacciones(objCliente,
                                              pContadorNroTransaccion);

  obtenerFechaDeHoy(pDiaActual, pMesActual, pAnioActual);
  std::cout << std::flush;
  system("cls||clear");

  while (*pSeleccionDelUsuarioFinal == 's' ||
         *pSeleccionDelUsuarioFinal == 'S') {
    mostrarMenu(pSeleccionDelMenuPrincipal, pDiaActual, pMesActual,
                pAnioActual);
    std::cout << std::flush;
    system("cls||clear"); // para limpiar la terminal cada vez que ejecutamos
                          // una opcion
    switch (*pSeleccionDelMenuPrincipal) {
    case 1:
      opcion1(objCliente, pContadorCantidadCliente);
      objArchivo->actualizarArchivoClientes(objCliente,
                                            pContadorCantidadCliente);
      break;

    case 2:
      opcion2(objCliente, pContadorCantidadCliente);
      objArchivo->actulizarALaBaja(objCliente, pContadorCantidadCliente);
      break;

    case 3:
      opcion3(objCliente, pContadorCantidadCliente);
      objArchivo->actulizarALaBaja(objCliente, pContadorCantidadCliente);
      break;

    case 4:
      opcion4(objCliente, pContadorCantidadCliente, pContadorNroTransaccion,
              objArchivo);
      objArchivo->actulizarALaBaja(objCliente, pContadorCantidadCliente);
      break;

    case 5:
      opcion5(objCliente, pContadorCantidadCliente, pContadorNroTransaccion,
              objArchivo);
      objArchivo->actulizarALaBaja(objCliente, pContadorCantidadCliente);
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

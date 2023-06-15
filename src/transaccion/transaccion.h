#ifndef PROYECTOFINAL_SRC_EXTRACCION_EXTRACCION_H_
#define PROYECTOFINAL_SRC_EXTRACCION_EXTRACCION_H_

class Transaccion {
private:
  // atributos
  int numeroDeTransaccion;
  float montoDeTransaccion;
  bool extraccion;
  bool deposito;
  int diaDeTransaccion;
  int mesDeTransaccion;
  int anioDeTransaccion;

public:
  // metodos son funciones
  Transaccion();
  Transaccion(int);
  int getNumeroDeTransaccion();
  float getMontoDeTransaccion();
  bool getExtraccion();
  bool getDeposito();
  int getDiaDetransaccion();
  int getMesDeTransaccion();
  int getAnioDeTransaccion();

  void setNumeroDeTransaccion(int);
  void setMontoDeTransaccion(float);
  void setExtraccion(bool);
  void setDeposito(bool);
  void setDiaDeTransaccion(int);
  void setMesDeTransaccion(int);
  void setAnioDeTransaccion(int);

  void realizarExtraccion(float *);
  void realizarDeposito(float *);

  void listarSeisMeses(int *, int *);
  void ListarPorAnio(int *pAnioSeleccionado);
  void listarTransaccion();
};

#endif

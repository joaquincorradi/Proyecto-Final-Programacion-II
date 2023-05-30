#ifndef PROYECTOFINAL_SRC_EXTRACCION_EXTRACCION_H_
#define PROYECTOFINAL_SRC_EXTRACCION_EXTRACCION_H_

class Transaccion{
  private:
  int numeroDeTransaccion;
  float montoDeTransaccion;
  bool extraccion;
  bool deposito;
  int diaDeTransaccion;
  int mesDeTransaccion;
  int anioDeTransaccion;

  public:
  Transaccion(float, bool, bool);
  int getnumeroDeTransaccion();
  float getmontoDeTransaccion();
  bool getextraccion();
  bool getdeposito();
  int getdiaDetransaccion();
  int getmesDeTransaccion();
  int getanioDeTransaccion();

  void setnumeroDeTransaccion();
  void setmontoDeTransaccion();
  void setextraccion();
  void setdeposito();
  void setdiaDeTransaccion();
  void setmesDeTransaccion();
  void setanioDeTransaccion();

};





#endif
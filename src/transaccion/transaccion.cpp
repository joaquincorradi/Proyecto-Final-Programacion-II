 
#include"./transaccion.h"

Transaccion::Transaccion(float _monto, bool _extraccion, bool _deposito) : montoDeTransaccion(_monto), extraccion(_extraccion), deposito(_deposito) {}

int Transaccion::getnumeroDeTransaccion(){return numeroDeTransaccion;}
float Transaccion::getmontoDeTransaccion(){return montoDeTransaccion;}
bool Transaccion::getextraccion(){return extraccion;}
bool Transaccion::getdeposito(){return deposito;}
int Transaccion::getdiaDetransaccion(){return diaDeTransaccion;}
int Transaccion::getmesDeTransaccion(){return mesDeTransaccion;}
int Transaccion::getanioDeTransaccion(){return anioDeTransaccion;}


void Transaccion::setnumeroDeTransaccion(int _numeroDeTransaccion){
  numeroDeTransaccion = _numeroDeTransaccion;
};

void Transaccion::setmontoDeTransaccion(float _montoDeTransaccion){
  montoDeTransaccion = _montoDeTransaccion;
};

void Transaccion::setextraccion(bool _extraccion){
  extraccion = _extraccion;
};

void Transaccion::setdeposito(bool _deposito){
  deposito = _deposito;
};

void Transaccion::setdiaDeTransaccion(int _diaDeTransaccion){
  diaDeTransaccion = _diaDeTransaccion;
};

void Transaccion::setmesDeTransaccion(int _mesDeTransaccion){
  mesDeTransaccion = _mesDeTransaccion;
};

void Transaccion::setanioDeTransaccion(int _anioDeTransaccion){
  anioDeTransaccion = _anioDeTransaccion;
};

/*
   Librería para acceder por I2C (400KHz) a los registros del módulo Qi P9242-R de IDT Inc.
   Creado por Jose Luis Tajada, Junio 2017
   joseluistajada@gmail.com
 */


#ifndef Qi9242_h
#define Qi9242_h

#include "Wire.h"
#include "Arduino.h"

#define ADDR_STATE 0X6E0 // definición de la dirección de los registros internos del P4292-R
#define ADDR_STATUS 0X6E1
#define ADDR_COIL_CURRENT 0X6E2
#define ADDR_COIL_VOLTAGE 0X6E4
#define ADDR_SENSING_VOLTAGE  0X6E8
#define ADDR_FREQUENCY 0X6EA
#define ADDR_OPERATING_DUTY 0X6EC
#define ADDR_BRIDGE_STATUS 0X6EE


class Qi9242
{
public:
Qi9242(int addres);
int state();
int status();
int coil_current();
int coil_voltage();
float sensing_voltage();
int frequency();
int operating_duty();
int bridge_status();

private:
int _Qi_addres;
int _register_addr;
int _register_long;
int _n;
int _m;
unsigned int _p;
float _r;
};

#endif

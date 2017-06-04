/*
   Librería para acceder por I2C (400KHz) a los registros del módulo Qi P9242-R de IDT Inc.
   Creado por Jose Luis Tajada, Junio 2017
   joseluistajada@gmail.com
 */



#include "Qi9242.h"


Qi9242::Qi9242(int addres) // define la dirección i2C del puerto del P9242-R
{
        _Qi_addres=addres;
}


int Qi9242::state()// pregunta por el estado del Qi
{
        Wire.beginTransmission(_Qi_addres); // selecciona la dirección del dispositivo Qi9242----------------------------------
        //delay(100);
        Wire.write( highByte( ADDR_STATE));
        Wire.write(  lowByte( ADDR_STATE));
        //delay(100);
        Wire.endTransmission();
        //delay(100);
        Wire.requestFrom(_Qi_addres, 1); // longitud en bits de la respuesta
        _n =Wire.read();
        return _n;
}


int Qi9242::status()// pregunta por el estatus operativo del Qi
{
        Wire.beginTransmission(_Qi_addres); // selecciona la dirección del dispositivo Qi9242----------------------------------
        //delay(100);
        Wire.write( highByte( ADDR_STATUS));
        Wire.write(  lowByte( ADDR_STATUS));
        //delay(100);
        Wire.endTransmission();
        //delay(100);
        Wire.requestFrom(_Qi_addres, 1); // longitud en bits de la respuesta
        _n =Wire.read();
        return _n;
}


int Qi9242::coil_current()// pregunta por la corriente aplicada a la coil del Qi
{
        Wire.beginTransmission(_Qi_addres); // selecciona la dirección del dispositivo Qi9242----------------------------------
        //delay(100);
        Wire.write( highByte( ADDR_COIL_CURRENT));
        Wire.write(  lowByte( ADDR_COIL_CURRENT));
        //delay(100);
        Wire.endTransmission();
        //delay(100);
        Wire.requestFrom(_Qi_addres, 2); // longitud en bits de la respuesta
        _n =Wire.read();
        _m =Wire.read();
        _p =(_m<<8) | _n;
        //Serial.println(String(_n)+" "+String(_m)+" "+String(_p));
        return _p;
}


int Qi9242::coil_voltage()// pregunta por el valor del voltaje aplicado a la coil del Qi
{
        Wire.beginTransmission(_Qi_addres); // selecciona la dirección del dispositivo Qi9242----------------------------------
        //delay(100);
        Wire.write( highByte( ADDR_COIL_VOLTAGE));
        Wire.write(  lowByte( ADDR_COIL_VOLTAGE));
        //delay(100);
        Wire.endTransmission();
        //delay(100);
        Wire.requestFrom(_Qi_addres, 2); // longitud en bits de la respuesta
        _n =Wire.read();
        _m =Wire.read();
        _p =(_m<<8) | _n;
        //Serial.println(String(_n)+" "+String(_m)+" "+String(_p));
        return _p;
}


float Qi9242::sensing_voltage()// pregunta por el valor del voltaje del termistor
{
        Wire.beginTransmission(_Qi_addres); // selecciona la dirección del dispositivo Qi9242----------------------------------
        //delay(100);
        Wire.write( highByte( ADDR_SENSING_VOLTAGE));
        Wire.write(  lowByte( ADDR_SENSING_VOLTAGE));
        //delay(100);
        Wire.endTransmission();
        //delay(100);
        Wire.requestFrom(_Qi_addres, 2); // longitud en bits de la respuesta
        _n =Wire.read();
        _m =Wire.read();
        _r =( ((_m<<8) | _n)*2.4 )/4095;
        //Serial.println(String(_n)+" "+String(_m)+" "+String(_p));
        return _r;
}


int Qi9242::frequency()// pregunta por el valor de la frecuencia de trabajo del circuito resonante
{
        Wire.beginTransmission(_Qi_addres); // selecciona la dirección del dispositivo Qi9242----------------------------------
        //delay(100);
        Wire.write( highByte( ADDR_FREQUENCY));
        Wire.write(  lowByte( ADDR_FREQUENCY));
        //delay(100);
        Wire.endTransmission();
        //delay(100);
        Wire.requestFrom(_Qi_addres, 2); // longitud en bits de la respuesta
        _n =Wire.read();
        _m =Wire.read();
        _p =((_m<<8) | _n);
        _p=60000/_p;
        //Serial.println(String(_n)+" "+String(_m)+" "+String(_p)+" "+String(_r));
        return _p;
}


int Qi9242::operating_duty()// pregunta por el valor del ciclo activo del circuito resonante
{
        Wire.beginTransmission(_Qi_addres); // selecciona la dirección del dispositivo Qi9242----------------------------------
        //delay(100);
        Wire.write( highByte( ADDR_OPERATING_DUTY));
        Wire.write(  lowByte( ADDR_OPERATING_DUTY));
        //delay(100);
        Wire.endTransmission();
        //delay(100);
        Wire.requestFrom(_Qi_addres, 2); // longitud en bits de la respuesta
        _n =Wire.read();
        _m =Wire.read();
        _p =((_m<<8) | _n);
        _p=(_p*50)/255;
        //Serial.println(String(_n)+" "+String(_m)+" "+String(_p)+" "+String(_r));
        return _p;
}


int Qi9242::bridge_status()// pregunta por el tipo de configuración del Puente de los MosFet
{
        Wire.beginTransmission(_Qi_addres); // selecciona la dirección del dispositivo Qi9242----------------------------------
        //delay(100);
        Wire.write( highByte( ADDR_BRIDGE_STATUS));
        Wire.write(  lowByte( ADDR_BRIDGE_STATUS));
        //delay(100);
        Wire.endTransmission();
        //delay(100);
        Wire.requestFrom(_Qi_addres, 1); // longitud en bits de la respuesta
        _n =Wire.read();
        return _n;
}

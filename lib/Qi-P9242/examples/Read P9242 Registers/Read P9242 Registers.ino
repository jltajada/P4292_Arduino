/*
   Librería para acceder por I2C (400KHz) a los registros del módulo Qi P9242-R de IDT Inc.
   Creado por Jose Luis Tajada, Junio 2017
   joseluistajada@gmail.com
 */


#include <Wire.h>
#include <Qi9242.h>


Qi9242 Qi9242(0x61);

void setup() {//___________________________________________________________ setup ___________________________________________
        Wire.begin ();
        Wire.setClock(400000);

        Serial.begin(115200);
        delay(1000);
        Serial.println("___________ Read I2C register from P4292-R Qi Charger_____________");

}


void loop() {//___________________________________________________________ L O O P ___________________________________________

        //Qi9242.state();
        delay(1000);
        Serial.println("Run Time:"+String(millis())+"ms");

        Serial.println("Estate:"+String(Qi9242.state()));
        Serial.println("Estatus:"+String(Qi9242.status()));
        Serial.println("Coil Current:"+String(Qi9242.coil_current())+"mA");
        Serial.println("Coil Voltage:"+String(Qi9242.coil_voltage())+"mV");
        Serial.println("Term Voltage:"+String(Qi9242.sensing_voltage())+"V");
        Serial.println("Frequency:"+String(Qi9242.frequency())+"KHz");
        Serial.println("opeation Duty:"+String(Qi9242.operating_duty())+"%");
        Serial.println("Bridge Status:"+String(Qi9242.bridge_status()));

        Serial.println("________________");

}

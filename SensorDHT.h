#pragma once

#include <Arduino.h>
#include <DHT.h>

// ======================================================================
//  CLASE: SensorDHT (DHT11)
// ======================================================================

class SensorDHT {
public:
  SensorDHT(uint8_t pin, uint8_t tipo) : _dht(pin, tipo) {}

  void iniciar() {
    _dht.begin();
  }

  // Lee humedad y temperatura.
  // Devuelve false si alguna de las lecturas falló (NaN).
  bool leer(float& temperatura, float& humedad) {
    humedad     = _dht.readHumidity();
    temperatura = _dht.readTemperature();

    return !(isnan(humedad) || isnan(temperatura));
  }

private:
  DHT _dht;
};

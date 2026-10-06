#pragma once

#include <Arduino.h>
#include <Wire.h>

#include "Config.h"
#include "SensorDHT.h"
#include "Pantalla.h"

// ======================================================================
//  CLASE: AplicacionAmbiente (une sensor y pantalla)
// ======================================================================

class AplicacionAmbiente {
public:
  AplicacionAmbiente()
    : _sensor(Config::DHT_PIN, Config::DHT_TIPO),
      _pantalla(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, &Wire, Config::OLED_RESET) {}

  void iniciar() {
    Serial.begin(Config::SERIAL_BAUDIOS);

    // Iniciar DHT11
    _sensor.iniciar();

    // Iniciar pantalla OLED
    if (!_pantalla.iniciar(Config::OLED_ADDRESS)) {
      Serial.println("No se encontró la pantalla OLED");
      while (true);
    }

    _pantalla.mostrarInicio();

    delay(Config::TIEMPO_INICIO_MS);
  }

  void actualizar() {
    float temperatura;
    float humedad;

    // Leer humedad y temperatura, comprobar si hubo error
    if (!_sensor.leer(temperatura, humedad)) {
      Serial.println("Error leyendo DHT11");

      _pantalla.mostrarError();

      delay(Config::INTERVALO_LECTURA_MS);
      return;
    }

    mostrarEnSerial(temperatura, humedad);
    _pantalla.mostrarLecturas(temperatura, humedad);

    // Actualizar cada 2 segundos
    delay(Config::INTERVALO_LECTURA_MS);
  }

private:
  SensorDHT _sensor;
  Pantalla  _pantalla;

  void mostrarEnSerial(float temperatura, float humedad) {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" C");

    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");
  }
};

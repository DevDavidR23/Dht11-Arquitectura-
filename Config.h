#pragma once

#include <Arduino.h>
#include <DHT.h>

// ======================================================================
//  CONFIGURACIÓN
// ======================================================================

namespace Config {

  // --------------------
  // DHT11
  // --------------------
  constexpr uint8_t DHT_PIN  = 4;
  constexpr uint8_t DHT_TIPO = DHT11;

  // --------------------
  // Pantalla OLED
  // --------------------
  constexpr uint8_t SCREEN_WIDTH  = 128;
  constexpr uint8_t SCREEN_HEIGHT = 64;
  constexpr int8_t  OLED_RESET    = -1;
  constexpr uint8_t OLED_ADDRESS  = 0x3C;

  // --------------------
  // Serial y tiempos
  // --------------------
  constexpr unsigned long SERIAL_BAUDIOS      = 115200;
  constexpr unsigned long TIEMPO_INICIO_MS    = 2000;
  constexpr unsigned long INTERVALO_LECTURA_MS = 2000;
}

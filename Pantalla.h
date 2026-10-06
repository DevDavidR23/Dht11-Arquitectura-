#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ======================================================================
//  CLASE: Pantalla (OLED SSD1306)
// ======================================================================

class Pantalla {
public:
  Pantalla(uint8_t ancho, uint8_t alto, TwoWire* wire, int8_t reset)
    : _display(ancho, alto, wire, reset) {}

  bool iniciar(uint8_t direccion) {
    if (!_display.begin(SSD1306_SWITCHCAPVCC, direccion)) {
      return false;
    }

    _display.clearDisplay();
    _display.setTextColor(SSD1306_WHITE);
    return true;
  }

  void mostrarInicio() {
    _display.clearDisplay();

    _display.setTextSize(2);
    _display.setCursor(10, 10);
    _display.println("DHT11");

    _display.setTextSize(1);
    _display.setCursor(10, 40);
    _display.println("Iniciando...");

    _display.display();
  }

  void mostrarError() {
    _display.clearDisplay();

    _display.setTextSize(1);
    _display.setCursor(10, 25);
    _display.println("Error DHT11");

    _display.display();
  }

  void mostrarLecturas(float temperatura, float humedad) {
    _display.clearDisplay();

    // Título
    _display.setTextSize(1);
    _display.setCursor(0, 0);
    _display.println("SENSOR AMBIENTE");

    _display.drawLine(0, 12, 128, 12, SSD1306_WHITE);

    // Temperatura
    _display.setTextSize(2);

    _display.setCursor(0, 20);
    _display.print("Temp:");

    _display.setCursor(65, 20);
    _display.print(temperatura, 1);
    _display.print("C");

    // Humedad
    _display.setCursor(0, 45);
    _display.print("Hum:");

    _display.setCursor(65, 45);
    _display.print(humedad, 1);
    _display.print("%");

    _display.display();
  }

private:
  Adafruit_SSD1306 _display;
};

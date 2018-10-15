#include <Wire.h>
#include <SSD1306.h>
#include <SSD1306_WIRE.h>

SSD1306_WIRE tft(0x3c, 255); // Not sure where the RES pin is on the ESP32. Set it to 255 to ignore it

void setup() {
    Wire.begin(5, 4); // This is needed for the ESP32
    tft.initializeDevice();
    tft.setBacklight(255);
    tft.setDisplayOffset(0, 0);
    tft.fillScreen(Color::Black);
    tft.drawRectangle(0, 0, 127, 63, Color::White);
}

void loop() {
    tft.setCursor(10, 10);
    tft.print(millis());
}

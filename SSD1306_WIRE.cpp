#include <SSD1306_WIRE.h>

void SSD1306_WIRE::initializeDevice() {
    if (_res != 255) {
        pinMode(_res, OUTPUT);
        digitalWrite(_res, HIGH);
        delay(10);
        digitalWrite(_res, LOW);
        delay(10);
        digitalWrite(_res, HIGH);
    }
    initDevice();
}

void SSD1306_WIRE::command(uint8_t c) {
    Wire.beginTransmission(_addr);
    Wire.write(0x00);
    Wire.write(c);
    Wire.endTransmission();
}

void SSD1306_WIRE::command(uint8_t c, uint8_t p) {
    Wire.beginTransmission(_addr);
    Wire.write(0x00);
    Wire.write(c);
    Wire.write(p);
    Wire.endTransmission();
}

void SSD1306_WIRE::command(uint8_t c, uint8_t p1, uint8_t p2) {
    Wire.beginTransmission(_addr);
    Wire.write(0x00);
    Wire.write(c);
    Wire.write(p2);
    Wire.write(p1);
    Wire.endTransmission();
}

void SSD1306_WIRE::data(uint8_t d) {
    Wire.beginTransmission(_addr);
    Wire.write(0x40);
    Wire.write(d);
    Wire.endTransmission();
}

void SSD1306_WIRE::data(uint8_t *d, uint32_t l) {

    uint32_t toSend = l;
    while (toSend > 0) {
        uint32_t thisSend = l > 16 ? 16 : l;
        Wire.beginTransmission(_addr);
        Wire.write(0x40);
        for (uint32_t i = 0; i < thisSend; i++) {
            Wire.write(d[l]);
        }
        Wire.endTransmission();
        toSend -= thisSend;
    }
}

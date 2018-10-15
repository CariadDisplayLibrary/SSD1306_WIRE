#ifndef _SSD1306_WIRE_H
#define _SSD1306_WIRE_H

#include <SSD1306.h>

#include <Wire.h>

class SSD1306_WIRE : public SSD1306 {
    private:
        uint8_t _addr;
        uint8_t _res;

    public:
        SSD1306_WIRE(uint8_t addr, uint8_t res = 255) :
            SSD1306(128, 64), _addr(addr), _res(res) {}

        void command(uint8_t c);
        void command(uint8_t c, uint8_t p);
        void command(uint8_t c, uint8_t p1, uint8_t p2);
        void data(uint8_t d);
        void data(uint8_t *d, uint32_t l);

        void initializeDevice();

};
#endif

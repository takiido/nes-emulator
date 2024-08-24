//
// Created by takiido on 8/23/2024.
//

#ifndef BUS_H
#define BUS_H
#include <array>
#include <cstdint>
#include "cpu.h"


class Bus {
public:
    Bus();
    ~Bus();

    CPU cpu;

    std::array<uint8_t, 64 * 1024> memory{};

    void write(uint16_t address, uint8_t data);
    uint8_t read(uint16_t address, bool readOnly = false);
};



#endif //BUS_H

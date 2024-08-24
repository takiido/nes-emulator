//
// Created by takiido on 8/23/2024.
//

#include "cpu.h"

CPU::CPU() = default;
CPU::~CPU() = default;


uint8_t CPU::read(uint16_t addr) {
    return bus->read(addr, false);
}

void CPU::write(uint16_t addr, uint8_t data) {
    bus->write(addr, data);
}

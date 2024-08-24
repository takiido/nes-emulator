//
// Created by takiido on 8/23/2024.
//

#include "Bus.h"

Bus::Bus() {
    for (auto &i : memory) i = 0x00;

    cpu.ConnectBus(this);
}

Bus::~Bus() = default;


void Bus::write(uint16_t address, uint8_t data) {
    if (0x0000 <= address && address <= 0xFFFF) {
        memory[address] = data;
    }
}

uint8_t Bus::read(uint16_t address, bool readOnly) {
    if (0x0000 <= address && address <= 0xFFFF) {
        return memory[address];
    }

    return 0x00;
}

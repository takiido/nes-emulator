//
// Created by takiido on 8/23/2024.
//

#ifndef CPU_H
#define CPU_H
#include "Bus.h"


class CPU {
public:
    CPU();
    ~CPU();

    void ConnectBus(Bus *n) { bus = n; }

private:
    Bus *bus = nullptr;
    uint8_t read(uint16_t addr);
    void write(uint16_t addr, uint8_t data);
};



#endif //CPU_H

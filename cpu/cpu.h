//
// Created by takiido on 8/23/2024.
//

#ifndef CPU_H
#define CPU_H
#include <string>
#include <vector>

#include "Bus.h"


class CPU {
public:
    CPU();
    ~CPU();

    void ConnectBus(Bus *n) { bus = n; }

    enum FLAGS {
        C = (1 << 0),       // Carry
        Z = (1 << 1),       // Zero
        I = (1 << 2),       // Disable interrupts
        D = (1 << 3),       // Decimal
        B = (1 << 4),       // Break
        U = (1 << 5),       // Unused
        V = (1 << 6),       // Overflow
        N = (1 << 7),       // Negative
    };

    uint8_t A = 0x00;       // Accumulator Register
    uint8_t X = 0x00;       // X Register
    uint8_t Y = 0x00;       // Y Register
    uint8_t SP = 0x00;      // Stack Pointer
    uint16_t PC = 0x0000;   // Program Counter
    uint8_t status = 0x00;  // Status Register

    // Addressing Modes
    uint8_t IMP();
    uint8_t IMM();
    uint8_t ZPO();
    uint8_t ZPX();
    uint8_t ZPY();
    uint8_t REL();
    uint8_t ABS();
    uint8_t ABX();
    uint8_t ABY();
    uint8_t IND();
    uint8_t IZX();
    uint8_t IZY();

    // Opcodes
    uint8_t ADC();
    uint8_t AND();
    uint8_t ASL();
    uint8_t BCC();
    uint8_t BCS();
    uint8_t BEQ();
    uint8_t BIT();
    uint8_t BMI();
    uint8_t BNE();
    uint8_t BPL();
    uint8_t BRK();
    uint8_t BVC();
    uint8_t BVS();
    uint8_t CLC();
    uint8_t CLD();
    uint8_t CLI();
    uint8_t CLV();
    uint8_t CMP();
    uint8_t CPX();
    uint8_t CPY();
    uint8_t DEC();
    uint8_t DEX();
    uint8_t DEY();
    uint8_t EOR();
    uint8_t INC();
    uint8_t INX();
    uint8_t INY();
    uint8_t JMP();
    uint8_t JSR();
    uint8_t LDA();
    uint8_t LDX();
    uint8_t LDY();
    uint8_t LSR();
    uint8_t NOP();
    uint8_t ORA();
    uint8_t PHA();
    uint8_t PHP();
    uint8_t PLA();
    uint8_t PLP();
    uint8_t ROL();
    uint8_t ROR();
    uint8_t RTI();
    uint8_t RTS();
    uint8_t SBC();
    uint8_t SEC();
    uint8_t SED();
    uint8_t SEI();
    uint8_t STA();
    uint8_t STX();
    uint8_t STY();
    uint8_t TAX();
    uint8_t TAY();
    uint8_t TSX();
    uint8_t TXA();
    uint8_t TXS();
    uint8_t TYA();

    uint8_t XXX();

    void clock();
    void reset();
    void interrupt();
    void nonminterrupt();

    uint8_t fetch();
    uint8_t fetched = 0x00;

    uint16_t addr_abs = 0x0000;
    uint16_t addr_rel = 0x00;
    uint8_t opcode = 0x00;
    uint8_t cycles = 0;

private:
    Bus *bus = nullptr;
    uint8_t read(uint16_t addr);
    void write(uint16_t addr, uint8_t data);
    void GetFlags(uint16_t addr);
    void SetFlags(uint16_t addr, uint16_t data);

    struct INSTRUCTION {
        std::string name;
        uint8_t(CPU::*operate)(void) = nullptr;
        uint8_t(CPU::*addrmode)(void) = nullptr;
        uint8_t cycles = 0;
    };

    std::vector<INSTRUCTION> instructions;
};



#endif //CPU_H

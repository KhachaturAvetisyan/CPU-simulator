#pragma once

#include <iostream>
#include "Opcodes.h"

class ALU
{
private:
    void add_operation(uint8_t A, uint8_t B);
    void subtract_operation(uint8_t A, uint8_t B);
    void or_operation(uint8_t A, uint8_t B);
    void not_operation(uint8_t A);
    void and_operation(uint8_t A, uint8_t B);
    void lshift_operation(uint8_t A);
    void rshift_operation(uint8_t A);

public:
    uint8_t result = 0;

    ALU() = default;
    ~ALU() = default;

    void operation(opcodes opcode, uint8_t A, uint8_t B);
    void operation(opcodes opcode, uint8_t A);
};



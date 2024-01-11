#pragma once

#include <iostream>
#include <string>
#include <array>

#include "Opcodes.h"

#define RAM_SIZE                64U
#define STACK_SIZE              32U

class RAM
{
private:
    std::array<uint8_t, RAM_SIZE> memory{};

    std::array<uint8_t, RAM_SIZE>::iterator instruction_ptr;
    std::array<uint8_t, RAM_SIZE>::iterator instructions_end_ptr;
    std::array<uint8_t, RAM_SIZE>::iterator stack_ptr;
    std::array<uint8_t, RAM_SIZE>::iterator rsp;

public:
    RAM();
    ~RAM() = default;

    void write_instructions(const std::string& file_name);
    uint8_t read_instruction();

    void stack_operation(opcodes opcode, uint8_t& value, uint8_t* ptr);
};

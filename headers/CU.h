#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "ALU.h"
#include "RAM.h"
#include "Opcodes.h"

enum error_codes
{
    NO_ERROR,
    INVALID_OPCODE,
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    INVALID_INPUT,
    INVALID_INPUT_SIZE
};

// Define the static dictionary
const std::unordered_map<std::string, opcodes> opcodeDictionary =
{
    {"ADD", ADD},
    {"SUB", SUB},
    {"OR", OR},
    {"AND", AND},
    {"NOT", NOT},
    {"LSHIFT", LSHIFT},
    {"RSHIFT", RSHIFT},
    {"PUSH", PUSH},
    {"POP", POP}
};

class CU
{
private:
    ALU alu{};
    RAM ram{};

    bool waiting_opcode_flag = true;

public:
    CU() = default;
    ~CU() = default;

    bool output_flag = false;
    error_codes error_flag = NO_ERROR;
    uint8_t result = 0;

    void input_operation(const std::string &operation);
};
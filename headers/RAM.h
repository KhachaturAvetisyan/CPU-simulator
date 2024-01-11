#pragma once

#include <string>
#include <array>

#define RAM_SIZE                64U

class RAM
{
private:
    std::array<uint8_t, RAM_SIZE> memory{};

    std::array<uint8_t, RAM_SIZE>::iterator stack_ptr;

public:
    RAM();
    ~RAM() = default;

    uint8_t error_flag = 0;

    void push(uint8_t value);
    uint8_t pop();
};

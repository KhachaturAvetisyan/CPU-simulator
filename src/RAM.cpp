#include "RAM.h"

RAM::RAM()
{
    stack_ptr = memory.begin();
}

void RAM::push(const uint8_t value)
{
    if (stack_ptr == memory.end())
    {
        error_flag = 1;
        return;
    }

    *stack_ptr = value;
    ++stack_ptr;

    error_flag = 0;
}

uint8_t RAM::pop()
{
    if (stack_ptr == memory.begin())
    {
        error_flag = 1;
        return 0;
    }

    error_flag = 0;

    return *(--stack_ptr);
}
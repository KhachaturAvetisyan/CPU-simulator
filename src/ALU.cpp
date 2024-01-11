#include "../headers/ALU.h"


void ALU::add_operation(uint8_t A, uint8_t B)
{
    result = A + B;
}

void ALU::subtract_operation(uint8_t A, uint8_t B)
{
    result = A - B;
}

void ALU::or_operation(uint8_t A, uint8_t B)
{
    result = A | B;
}

void ALU::not_operation(uint8_t A)
{
    result = ~A;
}

void ALU::and_operation(uint8_t A, uint8_t B)
{
    result = A & B;
}

void ALU::lshift_operation(uint8_t A)
{
    result = A << 1;
}

void ALU::rshift_operation(uint8_t A)
{
    result = A >> 1;
}

void ALU::operation(opcodes opcode, uint8_t A, uint8_t B)
{
    switch (opcode)
    {
        case ADD:
            add_operation(A, B);
            break;
        case SUBTRACT:
            subtract_operation(A, B);
            break;
        case OR:
            or_operation(A, B);
            break;
        case AND:
            and_operation(A, B);
            break;
        default:
            break;
    }
}

void ALU::operation(opcodes opcode, uint8_t A)
{
    switch (opcode)
    {
        case LSHIFT:
            lshift_operation(A);
            break;
        case RSHIFT:
            rshift_operation(A);
            break;
        case NOT:
            not_operation(A);
            break;
        default:
            break;
    }
}


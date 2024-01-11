#include <iostream>
#include "../headers/ALU.h"

int main()
{
//    std::cout << opcodes::WRITE << std::endl;

    // ALU operation testing
    ALU alu{};
    uint8_t A;
    uint8_t B;

    // ADD two nums
    A = 10;
    B = 8;
    alu.operation(ADD, A, B);
    std::cout << "ADD " << (int)A << " " << (int)B << " = "  << (int)alu.result << std::endl;

    // SUBTRACT two nums
    A = 10;
    B = 8;
    alu.operation(SUBTRACT, A, B);
    std::cout << "SUBTRACT " << (int)A << " " << (int)B << " = " << (int)alu.result << std::endl;

    // OR two nums
    A = 10;
    B = 8;
    alu.operation(OR, A, B);
    std::cout << "OR " << (int)A << " " << (int)B << " = " << (int)alu.result << std::endl;

    // AND two nums
    A = 10;
    B = 8;
    alu.operation(AND, A, B);
    std::cout << "AND " << (int)A << " " << (int)B << " = " << (int)alu.result << std::endl;

    // NOT two nums
    A = 10;
    alu.operation(NOT, A);
    std::cout << "NOT " << (int)A << " = " << (int)alu.result << std::endl;

    // LSHIFT two nums
    A = 10;
    alu.operation(LSHIFT, A);
    std::cout << "LSHIFT " << (int)A << " = " << (int)alu.result << std::endl;

    // RSHIFT two nums
    A = 10;
    alu.operation(RSHIFT, A);
    std::cout << "RSHIFT " << (int)A << " = " << (int)alu.result << std::endl;

    return 0;
}

#include <iostream>
#include "CU.h"

const std::unordered_map<error_codes, std::string> errorDictionary =
{
    {NO_ERROR, "NO_ERROR"},
    {INVALID_OPCODE, "INVALID_OPCODE"},
    {STACK_OVERFLOW, "STACK_OVERFLOW"},
    {STACK_UNDERFLOW, "STACK_UNDERFLOW"},
    {INVALID_INPUT, "INVALID_INPUT"},
    {INVALID_INPUT_SIZE, "INVALID_INPUT_SIZE"}
};

int main(int argc, char* argv[])
{
    CU cu;
    std::string input;

    for (;;)
    {
        std::getline(std::cin, input);

        if (input == "exit")
        {
            break;
        }

        cu.input_operation(input);

        if (cu.error_flag != NO_ERROR)
        {
            std::cout << "Error: " << errorDictionary.at(cu.error_flag) << std::endl;
            continue;
        }

        if (cu.output_flag)
        {
            std::cout << static_cast<int>(cu.result) << std::endl;
        }
    }

    return 0;
}

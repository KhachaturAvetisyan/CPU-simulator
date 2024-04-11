#include <iostream>
#include <fstream>
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
    // init file read flag
    bool file_read_flag = false;

    // check if there are any arguments
    if (argc == 1)
    {
        std::cout << "Please write opcodes in terminal." << std::endl;
    }
    else if (argc == 2)
    {
        std::cout << "All opcodes will be read from the file: " << argv[1] << std::endl;
        file_read_flag = true;
    }
    else
    {
        std::cout << "Invalid number of arguments." << std::endl;
        return 1;
    }

    // check flag
    if (file_read_flag)
    {
        // read file
        std::ifstream file(argv[1]);

        if (!file.is_open())
        {
            std::cout << "Error: Could not open file." << std::endl;
            return 1;
        }

        std::string line;
        CU cu;

        while (std::getline(file, line))
        {
            // print opcode
            std::cout << line << std::endl;

            cu.input_operation(line);

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

        file.close();
        return 0;
    }

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

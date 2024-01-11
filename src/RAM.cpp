#include "../headers/RAM.h"

RAM::RAM()
{
    instruction_ptr = memory.begin();
    stack_ptr = memory.end();
    rsp = memory.begin() + STACK_SIZE;
}


void RAM::write_instructions(const std::string& file_name)
{

}

uint8_t RAM::read_instruction()
{
    if (instruction_ptr == instructions_end_ptr)
    {
        instruction_ptr = memory.begin();
        instructions_end_ptr = memory.begin();

        return 0;
    }
    else
    {

    }

    // return  ? *(instruction_ptr++) : 0;
}



void RAM::stack_operation(opcodes opcode, uint8_t &value, uint8_t *ptr)
{
    switch (opcode)
    {
        case READ:
            break;
        case WRITE:
            break;
        default:
            break;
    }
}




#include "CU.h"

void CU::input_operation(const std::string& operation)
{
    output_flag = false;

    if (waiting_opcode_flag)
    {
        const auto opcode = opcodeDictionary.find(operation);

        // check if opcode is valid
        if (opcode == opcodeDictionary.end())
        {
            error_flag = INVALID_OPCODE;
            return;
        }

        // check if opcode is PUSH or POP
        if (opcode->second == PUSH)
        {
            waiting_opcode_flag = false;
            error_flag = NO_ERROR;
            return;
        }
        if (opcode->second == POP)
        {
            result = ram.pop();

            // check if pop was successful
            if (ram.error_flag)
            {
                error_flag = STACK_UNDERFLOW;
                return;
            }

            output_flag = true;
            return;
        }
        if (opcode->second >= ADD && opcode->second <= AND)
        {
            const uint8_t val2 = ram.pop();

            // check if pop was successful
            if (ram.error_flag)
            {
                error_flag = STACK_UNDERFLOW;
                return;
            }

            const uint8_t val1 = ram.pop();

            // check if pop was successful
            if (ram.error_flag)
            {
                error_flag = STACK_UNDERFLOW;
                return;
            }

            alu.operation(opcode->second, val1, val2);

            // push alu result to stack
            ram.push(alu.result);

            // check if push was successful
            if (ram.error_flag)
            {
                error_flag = STACK_OVERFLOW;
                return;
            }
        }
        if (opcode->second >= NOT && opcode->second <= RSHIFT)
        {
            const uint8_t val = ram.pop();

            // check if pop was successful
            if (ram.error_flag)
            {
                error_flag = STACK_UNDERFLOW;
                return;
            }

            alu.operation(opcode->second, val);

            // push alu result to stack
            ram.push(alu.result);

            // check if push was successful
            if (ram.error_flag)
            {
                error_flag = STACK_OVERFLOW;
                return;
            }
        }
    }
    else
    {
        waiting_opcode_flag = true;

        // check if operation is a number
        try
        {
            const uint8_t value = std::stoi(operation);

            ram.push(value);

            // check if push was successful
            if (ram.error_flag)
            {
                error_flag = STACK_OVERFLOW;
                return;
            }
        }
        catch (const std::invalid_argument&)
        {
            error_flag = INVALID_INPUT;
            return;
        }
        catch (const std::out_of_range&)
        {
            error_flag = INVALID_INPUT_SIZE;
            return;
        }
    }

    error_flag = NO_ERROR;
}

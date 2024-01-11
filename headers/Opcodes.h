#pragma once

enum opcodes
{
    // ALU
    ADD         =       0b10000001,
    SUBTRACT    =       0b10000010,
    OR          =       0b10000011,
    AND         =       0b10000100,
    NOT         =       0b10000101,
    LSHIFT      =       0b10000110,
    RSHIFT      =       0b10000111,

    // RAM
    PUSH        =       0b10001000,
    POP         =       0b10001001,

    CALL        =       0b10001010
};
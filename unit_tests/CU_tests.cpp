#include <gtest/gtest.h>

#include "CU.h"

// Fixture class for common setup and teardown
class CU_Tests : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Initialize any common setup for tests
    }

    void TearDown() override
    {
        // Clean up any resources after tests
    }
};

TEST_F(CU_Tests, opcodeDictionaryTests)
{
    ASSERT_EQ(opcodeDictionary.at("ADD"), ADD);
    ASSERT_EQ(opcodeDictionary.at("SUB"), SUB);
    ASSERT_EQ(opcodeDictionary.at("OR"), OR);
    ASSERT_EQ(opcodeDictionary.at("AND"), AND);
    ASSERT_EQ(opcodeDictionary.at("NOT"), NOT);
    ASSERT_EQ(opcodeDictionary.at("LSHIFT"), LSHIFT);
    ASSERT_EQ(opcodeDictionary.at("RSHIFT"), RSHIFT);
    ASSERT_EQ(opcodeDictionary.at("PUSH"), PUSH);
    ASSERT_EQ(opcodeDictionary.at("POP"), POP);
    ASSERT_EQ(opcodeDictionary.find("fhjksdjlhf"), opcodeDictionary.end());
}

TEST_F(CU_Tests, TestInvalidInput)
{
    CU cu;

    cu.input_operation("fdsfds");
    ASSERT_EQ(cu.error_flag, INVALID_OPCODE);
}

TEST_F(CU_Tests, TestPush)
{
    CU cu;

    // test valid push
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    // test invalid input
    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, INVALID_OPCODE);

    // test invalid input number
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("dhjakhf");
    ASSERT_EQ(cu.error_flag, INVALID_INPUT);

    // test invalid input size
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("122222222222222222222222222");
    ASSERT_EQ(cu.error_flag, INVALID_INPUT_SIZE);
}

TEST_F(CU_Tests, TestPop)
{
    CU cu;

    // test valid pop
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("55");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    ASSERT_EQ(cu.result, 55);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    ASSERT_EQ(cu.result, 12);

    // test invalid input
    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}

TEST_F(CU_Tests, TestAdd)
{
    CU cu;

    // test valid add
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("23");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("ADD");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    ASSERT_EQ(cu.result, 35);

    // test invalid input
    cu.input_operation("ADD");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);

    // push only one value
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("ADD");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}

TEST_F(CU_Tests, TestSub)
{
    CU cu;

    // test valid sub
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("23");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("SUB");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    ASSERT_EQ(cu.result, 11);

    // test invalid input
    cu.input_operation("SUB");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);

    // push only one value
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("SUB");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}

TEST_F(CU_Tests, TestOr)
{
    CU cu;

    // test valid or
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("23");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("OR");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    ASSERT_EQ(cu.result, 31);

    // test invalid input
    cu.input_operation("OR");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);

    // push only one value
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("OR");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}

TEST_F(CU_Tests, TestAnd)
{
    CU cu;

    // test valid and
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("23");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("AND");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    ASSERT_EQ(cu.result, 23 & 12);

    // test invalid input
    cu.input_operation("AND");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);

    // push only one value
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("AND");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}

TEST_F(CU_Tests, TestNot)
{
    CU cu;

    // test valid not
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("23");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("NOT");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    ASSERT_EQ(cu.result, 232);

    // test invalid input
    cu.input_operation("NOT");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}

TEST_F(CU_Tests, TestLshift)
{
    CU cu;

    // test valid lshift
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("2");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("LSHIFT");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    ASSERT_EQ(cu.result, 2 << 1);

    // test invalid input
    cu.input_operation("LSHIFT");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}

TEST_F(CU_Tests, TestRshift)
{
    CU cu;

    // test valid rshift
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("2");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("RSHIFT");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    ASSERT_EQ(cu.result, 2 >> 1);

    // test invalid input
    cu.input_operation("RSHIFT");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}

TEST_F(CU_Tests, TestStackOverflow)
{
    CU cu;

    // test stack overflow
    for (int i = 0; i < RAM_SIZE; ++i)
    {
        cu.input_operation("PUSH");
        ASSERT_EQ(cu.error_flag, NO_ERROR);

        cu.input_operation("12");
        ASSERT_EQ(cu.error_flag, NO_ERROR);
    }

    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, STACK_OVERFLOW);
}

TEST_F(CU_Tests, TestStackUnderflow)
{
    CU cu;

    // test valid pop
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    // test stack underflow
    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}

TEST_F(CU_Tests, TestStackUnderflow2)
{
    CU cu;

    // test valid pop
    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("12");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("PUSH");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("23");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("ADD");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, NO_ERROR);

    // test stack underflow
    cu.input_operation("POP");
    ASSERT_EQ(cu.error_flag, STACK_UNDERFLOW);
}
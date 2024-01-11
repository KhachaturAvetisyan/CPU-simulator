#include <gtest/gtest.h>

#include "ALU.h"

// Fixture class for common setup and teardown
class ALU_Tests : public ::testing::Test
{
protected:
    std::unique_ptr<ALU> alu;

    void SetUp() override
    {
        // Initialize any common setup for tests
        alu = std::make_unique<ALU>();
    }

    void TearDown() override
    {
        // Clean up any resources after tests
    }
};

TEST_F(ALU_Tests, ADD)
{
    // ADD two nums
    uint8_t A = 10;
    uint8_t B = 8;
    alu->operation(ADD, A, B);
    ASSERT_EQ(A + B, alu->result);
}

TEST_F(ALU_Tests, SUBTRACT)
{
    // SUBTRACT two nums
    uint8_t A = 10;
    uint8_t B = 8;
    alu->operation(SUB, A, B);
    ASSERT_EQ(A - B, alu->result);
}

TEST_F(ALU_Tests, OR)
{
    // OR two nums
    uint8_t A = 10;
    uint8_t B = 8;
    alu->operation(OR, A, B);
    ASSERT_EQ(A | B, alu->result);
}

TEST_F(ALU_Tests, AND)
{
    // AND two nums
    uint8_t A = 10;
    uint8_t B = 8;
    alu->operation(AND, A, B);
    ASSERT_EQ(A & B, alu->result);
}

TEST_F(ALU_Tests, NOT)
{
    // NOT two nums
    uint8_t A = 10;
    alu->operation(NOT, A);
    ASSERT_EQ(static_cast<uint8_t>(~A), alu->result);
}

TEST_F(ALU_Tests, LSHIFT)
{
    // LSHIFT two nums
    uint8_t A = 10;
    alu->operation(LSHIFT, A);
    ASSERT_EQ(A << 1, alu->result);
}

TEST_F(ALU_Tests, RSHIFT)
{
    // RSHIFT two nums
    uint8_t A = 10;
    alu->operation(RSHIFT, A);
    ASSERT_EQ(A >> 1, alu->result);
}

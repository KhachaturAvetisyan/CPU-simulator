#include <gtest/gtest.h>

#include "RAM.h"

// Fixture class for common setup and teardown
class RAM_Tests : public ::testing::Test
{
protected:
    std::unique_ptr<RAM> ram;

    void SetUp() override
    {
        // Initialize any common setup for tests
        ram = std::make_unique<RAM>();
    }

    void TearDown() override
    {
        // Clean up any resources after tests
    }
};

TEST_F(RAM_Tests, PushAndPop)
{
    // Push values to the RAM
    ram->push(42);
    ASSERT_EQ(ram->error_flag, 0);

    ram->push(23);
    ASSERT_EQ(ram->error_flag, 0);

    ram->push(3);
    ASSERT_EQ(ram->error_flag, 0);

    ram->push(123);
    ASSERT_EQ(ram->error_flag, 0);

    ram->push(67);
    ASSERT_EQ(ram->error_flag, 0);

    // Pop values from the RAM and check if they match
    uint8_t value = ram->pop();
    ASSERT_EQ(ram->error_flag, 0);
    ASSERT_EQ(value, 67);

    value = ram->pop();
    ASSERT_EQ(ram->error_flag, 0);
    ASSERT_EQ(value, 123);

    value = ram->pop();
    ASSERT_EQ(ram->error_flag, 0);
    ASSERT_EQ(value, 3);

    value = ram->pop();
    ASSERT_EQ(ram->error_flag, 0);
    ASSERT_EQ(value, 23);

    value = ram->pop();
    ASSERT_EQ(ram->error_flag, 0);
    ASSERT_EQ(value, 42);

    value = ram->pop();
    ASSERT_EQ(ram->error_flag, 1);
}

TEST_F(RAM_Tests, OverflowError)
{
    // Push values until the RAM is full
    for (int i = 0; i < RAM_SIZE; ++i)
    {
        ram->push(i);
    }

    // Try to push one more value, should set the error flag
    ram->push(42);

    // Check if the error flag is set
    ASSERT_EQ(ram->error_flag, 1);
}

TEST_F(RAM_Tests, UnderflowError)
{
    // Try to pop a value from the RAM, should set the error flag
    ram->pop();

    // Check if the error flag is set
    ASSERT_EQ(ram->error_flag, 1);
}
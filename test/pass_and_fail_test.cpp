#include "gtest/gtest.h"

#include "median.hxx"


TEST(add, adds_two_numbers_and_passes)
{
    ASSERT_EQ(add(10, 13), 23);
}

TEST(add, adds_two_numbers_fails)
{
    ASSERT_EQ(add(10, 13), 123);
}

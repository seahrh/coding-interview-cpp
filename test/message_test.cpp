#include "gtest/gtest.h"

#include "cses/message.hpp"

TEST(HelloWorldTest, TestCase1)
{
  EXPECT_EQ(get_message(),"Hello World!");
}

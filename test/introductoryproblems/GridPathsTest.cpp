#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cses/introductoryproblems/package.hpp"

TEST(GridPaths, Example1)
{
    EXPECT_EQ(grid_paths("??????R??????U??????????????????????????LD????D?"), 201);
}

TEST(GridPaths, Test12)
{
    EXPECT_EQ(grid_paths("???????????????????????????????????????????????L"), 42771);
}
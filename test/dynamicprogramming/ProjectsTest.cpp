#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/dynamicprogramming/package.hpp"

TEST(Projects, Test1)
{
    int n = 10;
    vector<tuple<ll, ll, ll>> ar = {
        make_tuple(14, 14, 98),
        make_tuple(76, 76, 58),
        make_tuple(94, 94, 57),
        make_tuple(92, 92, 45),
        make_tuple(82, 82, 14),
        make_tuple(86, 86, 41),
        make_tuple(87, 87, 72),
        make_tuple(14, 14, 26),
        make_tuple(27, 27, 85),
        make_tuple(48, 48, 52)};
    EXPECT_EQ(projects(n, ar), 522);
}
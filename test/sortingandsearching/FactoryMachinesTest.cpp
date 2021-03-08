#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cses/sortingandsearching/FactoryMachines.hpp"

TEST(FactoryMachines, Test11)
{
    ll n = 25, t = 1000000000;
    vector<ll> ks = {1000000000, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(solve(n, t, ks), 41666667);
}
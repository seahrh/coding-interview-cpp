#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cses/sortingandsearching/package.hpp"
using ::testing::ElementsAre;
using ::testing::IsEmpty;

TEST(SlidingMedian, ExampleTest01)
{
    ll n = 8, k = 3;
    vector<ll> xs = {2, 4, 3, 5, 8, 1, 2, 1};
    EXPECT_THAT(sliding_median(n, k, xs), ElementsAre(3, 4, 5, 5, 2, 1));
}

TEST(SlidingMedian, Test25)
{
    ll n = 10, k = 10;
    vector<ll> xs = {8, 3, 2, 3, 5, 7, 6, 3, 2, 7};
    EXPECT_THAT(sliding_median(n, k, xs), ElementsAre(3));
}

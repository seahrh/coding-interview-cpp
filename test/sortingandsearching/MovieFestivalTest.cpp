#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cses/sortingandsearching/package.hpp"
using ::testing::ElementsAre;
using ::testing::IsEmpty;

TEST(MovieFestival, OneMovie)
{
  vector<tuple<int, int>> movies = {make_tuple(1, 2)};
  EXPECT_EQ(movie_festival(1, movies), 1);
}

TEST(MovieFestival, TwoMovies)
{
  vector<tuple<int, int>> movies = {make_tuple(1, 2), make_tuple(2, 3)};
  EXPECT_EQ(movie_festival(2, movies), 2);
  movies = {make_tuple(1, 2), make_tuple(1, 3)};
  EXPECT_EQ(movie_festival(2, movies), 1);
}

TEST(MovieFestival, Example)
{
  vector<tuple<int, int>> movies = {make_tuple(3, 5), make_tuple(4, 9), make_tuple(5, 8)};
  EXPECT_EQ(movie_festival(3, movies), 2);
}

TEST(MovieFestival, Test1)
{
  vector<tuple<int, int>> movies = {make_tuple(6, 7),
                                    make_tuple(4, 5),
                                    make_tuple(8, 9),
                                    make_tuple(2, 3),
                                    make_tuple(10, 11),
                                    make_tuple(1, 2),
                                    make_tuple(9, 10),
                                    make_tuple(3, 4),
                                    make_tuple(5, 6),
                                    make_tuple(7, 8)};
  EXPECT_EQ(movie_festival(10, movies), 10);
}

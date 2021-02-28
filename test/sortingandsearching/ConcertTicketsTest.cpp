#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cses/sortingandsearching/ConcertTickets.hpp"
using ::testing::ElementsAre;
using ::testing::IsEmpty;

TEST(ConcertTickets, EmptyInputs)
{
  vector<lli> tickets;
  vector<lli> customers;
  EXPECT_THAT(solve(tickets, customers), IsEmpty());
  tickets.clear();
  customers = {1};
  EXPECT_THAT(solve(tickets, customers), ElementsAre(-1));
  tickets = {1};
  customers.clear();
  EXPECT_THAT(solve(tickets, customers), IsEmpty());
}

TEST(ConcertTickets, SingleTicket)
{
  vector<lli> tickets = {10};
  vector<lli> customers = {10};
  EXPECT_THAT(solve(tickets, customers), ElementsAre(10));
  tickets = {10};
  customers = {1, 10};
  EXPECT_THAT(solve(tickets, customers), ElementsAre(-1, 10));
}

TEST(ConcertTickets, TestCase1)
{
  vector<lli> tickets = {5, 3, 7, 8, 5};
  vector<lli> customers = {4, 8, 3};
  EXPECT_THAT(solve(tickets, customers), ElementsAre(3, 8, -1));
}
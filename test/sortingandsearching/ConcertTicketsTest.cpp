#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cses/sortingandsearching/ConcertTickets.hpp"
using ::testing::ElementsAre;
using ::testing::IsEmpty;

TEST(ConcertTickets, SingleTicket)
{
  vector<lli> tickets = {10};
  vector<lli> customers = {10};
  ASSERT_THAT(solve(tickets, customers), ElementsAre(10));
  tickets = {10};
  customers = {1, 10};
  ASSERT_THAT(solve(tickets, customers), ElementsAre(-1, 10));
}

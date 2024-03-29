#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/sortingandsearching/package.hpp"
using ::testing::ElementsAre;
using ::testing::IsEmpty;

TEST(ConcertTickets, EmptyInputs)
{
  vector<ll> tickets;
  vector<ll> customers;
  EXPECT_THAT(concert_tickets(tickets, customers), IsEmpty());
  tickets.clear();
  customers = {1};
  EXPECT_THAT(concert_tickets(tickets, customers), ElementsAre(-1));
  tickets = {1};
  customers.clear();
  EXPECT_THAT(concert_tickets(tickets, customers), IsEmpty());
}

TEST(ConcertTickets, SingleTicket)
{
  vector<ll> tickets = {10};
  vector<ll> customers = {10};
  EXPECT_THAT(concert_tickets(tickets, customers), ElementsAre(10));
  tickets = {10};
  customers = {1, 10};
  EXPECT_THAT(concert_tickets(tickets, customers), ElementsAre(-1, 10));
}

TEST(ConcertTickets, TestCase1)
{
  vector<ll> tickets = {5, 3, 7, 8, 5};
  vector<ll> customers = {4, 8, 3};
  EXPECT_THAT(concert_tickets(tickets, customers), ElementsAre(3, 8, -1));
}
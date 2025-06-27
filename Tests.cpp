// leonandsani@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Iterators.hpp"
#include "MyContainer.hpp"
#include "doctest.h"

using namespace mycontainers;

TEST_CASE("Add/remove elements") {
  MyContainer<int> c;
  c.add(10);
  c.add(5);
  c.add(10);
  CHECK(c.size() == 3);

  c.remove(10); // removes both 10s
  CHECK(c.size() == 1);
  CHECK_THROWS(c.remove(42)); // not in container
}

TEST_CASE("AscendingOrder") {
  MyContainer<int> c;
  c.add(3);
  c.add(1);
  c.add(5);

  iterators::AscendingOrder<int> it(c);
  std::vector<int> result;
  for (int x : it)
    result.push_back(x);

  CHECK(result == std::vector<int>{1, 3, 5});
}

TEST_CASE("DescendingOrder") {
  MyContainer<int> c;
  c.add(3);
  c.add(1);
  c.add(5);

  iterators::DescendingOrder<int> it(c);
  std::vector<int> result;
  for (int x : it)
    result.push_back(x);

  CHECK(result == std::vector<int>{5, 3, 1});
}

TEST_CASE("Order (insertion order)") {
  MyContainer<int> c;
  c.add(8);
  c.add(4);
  c.add(6);

  iterators::Order<int> it(c);
  std::vector<int> result;
  for (int x : it)
    result.push_back(x);

  CHECK(result == std::vector<int>{8, 4, 6});
}

TEST_CASE("ReverseOrder") {
  MyContainer<int> c;
  c.add(8);
  c.add(4);
  c.add(6);

  iterators::ReverseOrder<int> it(c);
  std::vector<int> result;
  for (int x : it)
    result.push_back(x);

  CHECK(result == std::vector<int>{6, 4, 8});
}

TEST_CASE("SideCrossOrder") {
  MyContainer<int> c;
  c.add(5);
  c.add(1);
  c.add(9);
  c.add(3);
  c.add(7);

  iterators::SideCrossOrder<int> it(c);
  std::vector<int> result;
  for (int x : it)
    result.push_back(x);

  // sorted = [1,3,5,7,9] → cross = 1,9,3,7,5
  CHECK(result == std::vector<int>{1, 9, 3, 7, 5});
}

TEST_CASE("MiddleOutOrder (odd)") {
  MyContainer<int> c;
  c.add(100);
  c.add(200);
  c.add(300);
  c.add(400);
  c.add(500);

  iterators::MiddleOutOrder<int> it(c);
  std::vector<int> result;
  for (int x : it)
    result.push_back(x);

  // indices: 2 → 1 → 3 → 0 → 4
  CHECK(result == std::vector<int>{300, 200, 400, 100, 500});
}

TEST_CASE("MiddleOutOrder (even)") {
  MyContainer<int> c;
  c.add(10);
  c.add(20);
  c.add(30);
  c.add(40); // size = 4 → mid = 2

  iterators::MiddleOutOrder<int> it(c);
  std::vector<int> result;
  for (int x : it)
    result.push_back(x);

  // indices: 2 → 1 → 3 → 0
  CHECK(result == std::vector<int>{30, 20, 40, 10});
}

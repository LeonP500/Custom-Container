// leonandsani@gmail.com

#include "Iterators.hpp"
#include "MyContainer.hpp"
#include <iostream>

using namespace mycontainers;

void printHeader(const std::string &title) {
  std::cout << "\n=== " << title << " ===\n";
}

int main() {
  MyContainer<int> c;

  c.add(7);
  c.add(15);
  c.add(6);
  c.add(1);
  c.add(2);

  std::cout << "Original container(int): " << c << std::endl;

  printHeader("AscendingOrder");
  for (int x : iterators::AscendingOrder<int>(c))
    std::cout << x << " "; // 1 2 6 7 15

  printHeader("DescendingOrder");
  for (int x : iterators::DescendingOrder<int>(c))
    std::cout << x << " "; // 15 7 6 2 1

  printHeader("Order (insertion)");
  for (int x : iterators::Order<int>(c))
    std::cout << x << " "; // 7 15 6 1 2

  printHeader("ReverseOrder");
  for (int x : iterators::ReverseOrder<int>(c))
    std::cout << x << " "; // 2 1 6 15 7

  printHeader("SideCrossOrder");
  for (int x : iterators::SideCrossOrder<int>(c))
    std::cout << x << " "; // 1 15 2 7 6

  printHeader("MiddleOutOrder");
  for (int x : iterators::MiddleOutOrder<int>(c))
    std::cout << x << " "; // 6 15 1 7 2

  std::cout << std::endl << std::endl << std::endl;

  MyContainer<std::string> s;

  s.add("hello");
  s.add("leon");
  s.add("amit");
  s.add("computers");
  s.add("grand theft auto");

  std::cout << "Original container(string): " << s << std::endl;

  printHeader("AscendingOrder");
  for (std::string x : iterators::AscendingOrder<std::string>(s))
    std::cout << x << " ";

  printHeader("DescendingOrder");
  for (std::string x : iterators::DescendingOrder<std::string>(s))
    std::cout << x << " ";

  printHeader("Order (insertion)");
  for (std::string x : iterators::Order<std::string>(s))
    std::cout << x << " ";

  printHeader("ReverseOrder");
  for (std::string x : iterators::ReverseOrder<std::string>(s))
    std::cout << x << " ";

  printHeader("SideCrossOrder");
  for (std::string x : iterators::SideCrossOrder<std::string>(s))
    std::cout << x << " ";

  printHeader("MiddleOutOrder");
  for (std::string x : iterators::MiddleOutOrder<std::string>(s))
    std::cout << x << " ";

  std::cout << std::endl;

  return 0;
}

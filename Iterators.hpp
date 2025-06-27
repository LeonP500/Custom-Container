// leonandsani@gmail.com

#pragma once
#include "MyContainer.hpp"
#include <algorithm>
#include <iterator>
#include <numeric> // עבור std::iota
#include <vector>

namespace mycontainers {
namespace iterators {

// מחלקה כללית לאיטרטורים אשר מקבלת מערך של אינדקסים המציין את סדר הסריקה.
template <typename T> class GenericIterator {
private:
  const MyContainer<T> &container;
  const std::vector<size_t> &indices;
  size_t pos;

public:
  GenericIterator(const MyContainer<T> &cont, const std::vector<size_t> &idx,
                  size_t position)
      : container(cont), indices(idx), pos(position) {}

  const T &operator*() const { return container.getData()[indices[pos]]; }

  GenericIterator &operator++() {
    ++pos;
    return *this;
  }

  bool operator!=(const GenericIterator &other) const {
    return pos != other.pos;
  }
};

///////////////////// AscendingOrder ///////////////////////
template <typename T = int> class AscendingOrder {
private:
  const MyContainer<T> &container;
  std::vector<size_t> sorted_indices;

public:
  AscendingOrder(const MyContainer<T> &cont) : container(cont) {
    const auto &data = container.getData();
    sorted_indices.resize(data.size());
    std::iota(sorted_indices.begin(), sorted_indices.end(), 0);
    std::sort(sorted_indices.begin(), sorted_indices.end(),
              [&](size_t a, size_t b) { return data[a] < data[b]; });
  }

  auto begin() const {
    return GenericIterator<T>(container, sorted_indices, 0);
  }
  auto end() const {
    return GenericIterator<T>(container, sorted_indices, sorted_indices.size());
  }
};

///////////////////// DescendingOrder ///////////////////////
template <typename T = int> class DescendingOrder {
private:
  const MyContainer<T> &container;
  std::vector<size_t> sorted_indices;

public:
  DescendingOrder(const MyContainer<T> &cont) : container(cont) {
    const auto &data = container.getData();
    sorted_indices.resize(data.size());
    std::iota(sorted_indices.begin(), sorted_indices.end(), 0);
    std::sort(sorted_indices.begin(), sorted_indices.end(),
              [&](size_t a, size_t b) { return data[a] > data[b]; });
  }

  auto begin() const {
    return GenericIterator<T>(container, sorted_indices, 0);
  }
  auto end() const {
    return GenericIterator<T>(container, sorted_indices, sorted_indices.size());
  }
};

///////////////////// Order (סדר הוספה) ///////////////////////
template <typename T = int> class Order {
private:
  const MyContainer<T> &container;
  std::vector<size_t> order_indices;

public:
  Order(const MyContainer<T> &cont) : container(cont) {
    const auto &data = container.getData();
    order_indices.resize(data.size());
    std::iota(order_indices.begin(), order_indices.end(), 0);
  }

  auto begin() const { return GenericIterator<T>(container, order_indices, 0); }
  auto end() const {
    return GenericIterator<T>(container, order_indices, order_indices.size());
  }
};

///////////////////// ReverseOrder (הפוך סדר הוספה) ///////////////////////
template <typename T = int> class ReverseOrder {
private:
  const MyContainer<T> &container;
  std::vector<size_t> rev_indices;

public:
  ReverseOrder(const MyContainer<T> &cont) : container(cont) {
    const auto &data = container.getData();
    size_t n = data.size();
    rev_indices.resize(n);
    for (size_t i = 0; i < n; ++i) {
      rev_indices[i] = n - 1 - i;
    }
  }

  auto begin() const { return GenericIterator<T>(container, rev_indices, 0); }
  auto end() const {
    return GenericIterator<T>(container, rev_indices, rev_indices.size());
  }
};

///////////////////// SideCrossOrder ///////////////////////
template <typename T = int> class SideCrossOrder {
private:
  const MyContainer<T> &container;
  std::vector<size_t> side_cross_indices;

public:
  SideCrossOrder(const MyContainer<T> &cont) : container(cont) {
    const auto &data = container.getData();
    std::vector<size_t> sorted_indices(data.size());
    std::iota(sorted_indices.begin(), sorted_indices.end(), 0);
    std::sort(sorted_indices.begin(), sorted_indices.end(),
              [&](size_t a, size_t b) { return data[a] < data[b]; });
    // בניית סדר סריקה: ראשון הקטן ביותר, אחריו הגדול ביותר, אחר כך השני הקטן,
    // השני הגדול, ...
    size_t i = 0, j = sorted_indices.size() - 1;
    while (i <= j) {
      if (i == j) {
        side_cross_indices.push_back(sorted_indices[i]);
      } else {
        side_cross_indices.push_back(sorted_indices[i]);
        side_cross_indices.push_back(sorted_indices[j]);
      }
      i++;
      if (j > 0)
        j--;
    }
  }

  auto begin() const {
    return GenericIterator<T>(container, side_cross_indices, 0);
  }
  auto end() const {
    return GenericIterator<T>(container, side_cross_indices,
                              side_cross_indices.size());
  }
};

///////////////////// MiddleOutOrder ///////////////////////
template <typename T = int> class MiddleOutOrder {
private:
  const MyContainer<T> &container;
  std::vector<size_t> middle_out_indices;

public:
  MiddleOutOrder(const MyContainer<T> &cont) : container(cont) {
    const auto &data = container.getData();
    size_t n = data.size();
    if (n == 0)
      return;
    // בחירה במרכז: במקרה של מספר זוגי – בחרנו באינדקס n/2 (חלוקה שלמה כלפי מטה)
    size_t mid = n / 2;
    middle_out_indices.push_back(mid);
    int left = static_cast<int>(mid) - 1;
    int right = static_cast<int>(mid) + 1;
    while (left >= 0 || right < static_cast<int>(n)) {
      if (left >= 0) {
        middle_out_indices.push_back(left);
        left--;
      }
      if (right < static_cast<int>(n)) {
        middle_out_indices.push_back(right);
        right++;
      }
    }
  }

  auto begin() const {
    return GenericIterator<T>(container, middle_out_indices, 0);
  }
  auto end() const {
    return GenericIterator<T>(container, middle_out_indices,
                              middle_out_indices.size());
  }
};

} // namespace iterators
} // namespace mycontainers

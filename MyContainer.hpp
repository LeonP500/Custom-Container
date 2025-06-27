// leonandsani@gmail.com

#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace mycontainers {

template <typename T = int> class MyContainer {
private:
  std::vector<T> data;

public:
  // הוספת איבר
  void add(const T &value) { data.push_back(value); }

  // הסרת כל ההופעות של איבר (אם לא קיים – זריקת חריגה)
  void remove(const T &value) {
    auto original_size = data.size();
    data.erase(std::remove(data.begin(), data.end(), value), data.end());

    if (data.size() == original_size) {
      throw std::invalid_argument("Item not found in container.");
    }
  }

  // כמות האיברים בקונטיינר
  std::size_t size() const { return data.size(); }

  // גישה ישירה (לשימוש פנימי או איטרטורים)
  const std::vector<T> &getData() const { return data; }

  // הדפסה
  friend std::ostream &operator<<(std::ostream &os,
                                  const MyContainer<T> &container) {
    os << "[";
    for (std::size_t i = 0; i < container.data.size(); ++i) {
      os << container.data[i];
      if (i != container.data.size() - 1)
        os << ", ";
    }
    os << "]";
    return os;
  }
};

} // namespace mycontainers

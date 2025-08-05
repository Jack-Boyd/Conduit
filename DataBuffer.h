#pragma once

#include <vector>
#include <stdexcept>

template <typename T>
class DataBuffer {
public:
  DataBuffer(size_t size) {
    data.resize(size);
  };

  size_t getSize() const {
    return data.size();
  };

  T getSample(size_t index) const  {
    if (index >= data.size()) {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  };

  void setSample(size_t index, T value) {
    if (index >= data.size()) {
      throw std::out_of_range("Index out of range");
    }
    data[index] = value;
  };
private:
  std::vector<T> data;
};
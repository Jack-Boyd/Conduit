#include "DataBuffer.h"
#include <stdexcept>

DataBuffer::DataBuffer(size_t size) {
  data.resize(size);
}

size_t DataBuffer::getSize() const {
  return data.size();
}

float DataBuffer::getSample(size_t index) const {
  if (index < 0 || static_cast<size_t>(index) >= data.size()) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

void DataBuffer::setSample(size_t index, float value) {
  if (index < 0 || static_cast<size_t>(index) >= data.size()) {
    throw std::out_of_range("Index out of range");
  }
  data[index] = value;
}
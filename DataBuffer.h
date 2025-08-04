#pragma once

#include <vector>

class DataBuffer {
private:
  std::vector<float> data;
public:
  DataBuffer(size_t size);

  size_t getSize() const;
  float getSample(size_t index) const;
  void setSample(size_t index, float value);
};
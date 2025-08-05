#pragma once
#include "IProcessor.h"
#include "DataBuffer.h"

template <typename T>
class InvertProcessor : public IProcessor<T> {
public:
  InvertProcessor() = default;
  
  void process(DataBuffer<T> &buffer) override {
    for (size_t i = 0; i < buffer.getSize(); ++i) {
      buffer.setSample(i, buffer.getSample(i) * static_cast<T>(-1));
    }
  };
};
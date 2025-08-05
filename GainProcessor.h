#pragma once
#include "IProcessor.h"
#include "DataBuffer.h"

template <typename T>
class GainProcessor : public IProcessor<T> {
public:
  GainProcessor(T gainFactor) : gain(gainFactor) {}

  void process(DataBuffer<T>& buffer) override {
    for (size_t i = 0; i < buffer.getSize(); ++i) {
      const T currentSample = buffer.getSample(i);
      buffer.setSample(i, currentSample * gain);
    }
  }
private:
  T gain;
};
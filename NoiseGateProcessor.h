#pragma once
#include "IProcessor.h"
#include "DataBuffer.h"
#include <cmath>

template <typename T>
class NoiseGateProcessor : public IProcessor<T> {
public:
  NoiseGateProcessor(T thresholdValue) : threshold(thresholdValue) {}

  void process(DataBuffer<T>& buffer) override {
    for (size_t i = 0; i < buffer.getSize(); ++i) {
      const T currentSample = buffer.getSample(i);
      if (std::abs(currentSample) < threshold) {
        buffer.setSample(i, static_cast<T>(0));
      }
    }
  };
private:
  T threshold;
};
#pragma once
#include "IProcessor.h"

class NoiseGateProcessor : public IProcessor {
public:
  NoiseGateProcessor(float thresholdValue);
  void process(DataBuffer& buffer) override;
private:
  float threshold;
};
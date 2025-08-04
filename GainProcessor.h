#pragma once
#include "IProcessor.h"

class GainProcessor : public IProcessor {
public:
  GainProcessor(float gainFactor);
  void process(DataBuffer& buffer) override;
private:
  float gain;
};
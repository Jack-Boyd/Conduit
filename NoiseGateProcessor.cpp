#include "NoiseGateProcessor.h"
#include "DataBuffer.h"

NoiseGateProcessor::NoiseGateProcessor(float thresholdValue) : threshold(thresholdValue) {}

void NoiseGateProcessor::process(DataBuffer& buffer) {
  for (int i = 0; i < buffer.getSize(); ++i) {
    const float currentSample = buffer.getSample(i);
    if (currentSample < threshold) {
      buffer.setSample(i, 0.f);
    }
  }
}
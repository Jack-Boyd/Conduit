#include "GainProcessor.h"
#include "DataBuffer.h"

GainProcessor::GainProcessor(float gainFactor) : gain(gainFactor) {}

void GainProcessor::process(DataBuffer& buffer) {
  for (int i = 0; i < buffer.getSize(); ++i) {
    const float currentSample = buffer.getSample(i);
    buffer.setSample(i, currentSample * gain);
  }
}
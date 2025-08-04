#include "InvertProcessor.h"
#include "DataBuffer.h"

void InvertProcessor::process(DataBuffer& buffer) {
  for (int i = 0; i < buffer.getSize(); ++i) {
    buffer.setSample(i, buffer.getSample(i) * -1.f);
  }
}
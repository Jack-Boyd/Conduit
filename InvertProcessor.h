#pragma once
#include "IProcessor.h"

class InvertProcessor : public IProcessor {
public: 
  void process(DataBuffer& buffer) override;
};
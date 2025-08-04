#include <iostream>
#include <vector> 
#include <memory>

#include "DataBuffer.h"
#include "IProcessor.h"
#include "GainProcessor.h"
#include "InvertProcessor.h"
#include "NoiseGateProcessor.h"

void printBuffer(const DataBuffer& buffer) {
  for (size_t i = 0 ; i < buffer.getSize(); ++i) {
    std::cout << buffer.getSample(i) << " ";
  }
  std::cout << std::endl;
}
int main () {
  DataBuffer buffer(100);

  for (size_t i = 0; i < buffer.getSize(); ++i) {
    buffer.setSample(i, static_cast<float>(i) / 10.f);
  }

  std::cout << "--- Original Buffer ---" << std::endl;
  printBuffer(buffer);
  std::cout << "\n";

  std::vector<std::unique_ptr<IProcessor>> processorChain;

  processorChain.push_back(std::make_unique<GainProcessor>(5.f));
  processorChain.push_back(std::make_unique<NoiseGateProcessor>(10.f));
  processorChain.push_back(std::make_unique<InvertProcessor>());

  for (const auto& processor : processorChain) {
    processor->process(buffer);
    printBuffer(buffer);
    std::cout << "----------------------------\n";
  }

  std::cout << "--- New Buffer ---" << std::endl;
  printBuffer(buffer);
  std::cout << "\n";
  
  return 0;
}
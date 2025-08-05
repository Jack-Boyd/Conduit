#include <iostream>
#include <vector> 
#include <memory>
#include <thread>
#include <chrono>
#include <cmath>
#include <atomic>
#include <functional>

#include "DataBuffer.h"
#include "IProcessor.h"
#include "GainProcessor.h"
#include "InvertProcessor.h"
#include "NoiseGateProcessor.h"

void processing_thread_function(
  std::vector<std::unique_ptr<IProcessor<float>>> processorChain,
  std::atomic<bool>& stopFlag
) {
  std::cout << "[Processing Thread] Thread started." << std::endl;

  const size_t bufferSize = 256;
  float phase = 0.0f;
  float frequency = 440.f / 44100.f;

  while(!stopFlag.load()) {
    DataBuffer<float> buffer(bufferSize);
    for (size_t i = 0; i < buffer.getSize(); ++i) {
      buffer.setSample(i, std::sin(phase));
      phase += 2.f * M_PI * frequency;
      if (phase > 2.f * M_PI) {
        phase -= 2.f * M_PI;
      }
    }

    for (const auto& processor : processorChain) {
      processor->process(buffer);
    }

    std::cout << "." << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

  }
  std::cout << "[Processing Thread] Thread stopping" << std::endl;
}

int main () {
  std::cout << "[Main Thread] Application starting." << std::endl;

  std::vector<std::unique_ptr<IProcessor<float>>> processorChain;
  processorChain.push_back(std::make_unique<GainProcessor<float>>(5.f));
  processorChain.push_back(std::make_unique<NoiseGateProcessor<float>>(0.1f));
  processorChain.push_back(std::make_unique<InvertProcessor<float>>());

  std::atomic<bool> stopProcessingFlag(false);

  std::cout << "[Main Thread] Lauching processing thread..." << std::endl;
  std::thread processingThread(processing_thread_function, std::move(processorChain), std::ref(stopProcessingFlag));

  std::cout << "[Main Thread] Processing thread launched. Running for 3 seconds..." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  
  std::cout << "\n[Main Thread] Requesting processing thread to stop." << std::endl;
  stopProcessingFlag.store(true);
  
  std::cout << "[Main Thread] Waiting for processing thread to join..." << std::endl;
  processingThread.join();

  std::cout << "[Main Thread] Application finished." << std::endl;

  return 0;
}
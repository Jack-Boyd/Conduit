#pragma once

class DataBuffer;
class IProcessor {
public: 
  virtual ~IProcessor() = default;
  virtual void process(DataBuffer& buffer) = 0;
};
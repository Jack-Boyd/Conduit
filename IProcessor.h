#pragma once

template <typename T>
class DataBuffer;

template <typename T>
class IProcessor {
public: 
  virtual ~IProcessor() = default;
  virtual void process(DataBuffer<T>& buffer) = 0;
};
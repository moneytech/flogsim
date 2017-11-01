#pragma once

#include <memory>
#include <vector>
#include <iostream>

#include "model.hpp"

class Task;

enum class Fault
{
  OK,
  SKIP,
  FAILURE
};

class FaultInjector
{
protected:
  virtual void print(std::ostream &os) const = 0;

public:
  FaultInjector()
  {}

  virtual Fault failure(std::shared_ptr<Task> task) = 0;

  // Factory method, which creates fault injector based on
  // configuration.
  static std::unique_ptr<FaultInjector> create();

  friend std::ostream &operator<<(std::ostream &os, const FaultInjector &fi)
  {
    fi.print(os);
    return os;
  }
};

class NoFaults : public FaultInjector
{
  virtual void print(std::ostream &os) const override final
  {}

public:
  using FaultInjector::FaultInjector;

  Fault failure(std::shared_ptr<Task>) override final
  {
    return Fault::OK;
  }
};

class UniformFaults : public FaultInjector
{
  int P; // Number of nodes
  int F; // Number of offline failures
  std::vector<int> failed_nodes;

  virtual void print(std::ostream &os) const override final;
public:

  UniformFaults();

  Fault failure(std::shared_ptr<Task>) override final;
};

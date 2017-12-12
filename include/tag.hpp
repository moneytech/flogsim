#pragma once

#include "integer.hpp"

enum class Tag
{
  INTERNAL   = 1,
  TREE       = 2,
  GOSSIP     = 3,
  RING_LEFT  = 10,
  RING_RIGHT = 11,
  EXCLUSIVE  = 50,
};

std::ostream& operator<<(std::ostream &os, const Tag& t);

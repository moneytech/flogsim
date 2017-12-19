#pragma once

#include "tree.hpp"

class OptimalTree : public Tree
{
  std::vector<std::vector<int>> send_to;
  void post_sends(const int sender, TaskQueue &tq) const;
public:
  OptimalTree(ReachedNodes &reached_nodes);

  virtual Result dispatch(const InitTask &t, TaskQueue &tq, int node_id) override;
  virtual Result dispatch(const RecvEndTask& t, TaskQueue &tq, int node_id) override;
};

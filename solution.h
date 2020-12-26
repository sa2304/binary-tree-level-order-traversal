#ifndef SOLUTION_H
#define SOLUTION_H

#include <set>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root) {
      nodes_queue_.push({root, 0});
      nodes_visited_.insert(root);
      int current_level = -1;
      while (!nodes_queue_.empty()) {
        auto [node, node_level] = nodes_queue_.front();
        nodes_queue_.pop();
        if (current_level != node_level) {
          result.push_back({});
          current_level = node_level;
        }
        result.back().push_back(node->val);
        for (auto child : {node->left, node->right}) {
          if (child && !nodes_visited_.count(child)) {
            nodes_queue_.push({child, node_level + 1});
            nodes_visited_.insert(child);
          }
        }
      }
    }

    return result;
  }

private:
  queue<pair<TreeNode*,int>> nodes_queue_;
  set<TreeNode*> nodes_visited_;
};

#endif // SOLUTION_H

#include <vector>
#include <iostream>

#include "common/tree_node.h"

int max_depth(TreeNode* root) {
  if (root == nullptr) return 0;
  int left = max_depth(root->left());
  int right = max_depth(root->right());
  return (left > right ? left : right) + 1;
}

int main() {
  init_tree();
  root->print();

  std::cout << "-------------" << std::endl;

  std::cout << max_depth(root.get()) << std::endl;
}
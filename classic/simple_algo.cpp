#include <vector>
#include <iostream>
#include <algorithm>

#include "common/tree_node.h"

int maxDepth(TreeNode* root) {
  if (root == nullptr) return 0;
  int left = maxDepth(root->left());
  int right = maxDepth(root->right());
  return (left > right ? left : right) + 1;
}

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left() == nullptr && root->right() == nullptr)
        return 1;
    int left = 1e5;
    if (root->left() != nullptr)
        left = minDepth(root->left());
    int right = 1e5;
    if (root->right() != nullptr)
        right = minDepth(root->right());
    return (left < right ? left : right) + 1;
}

int minDepth2(TreeNode* root) {
    if (root == nullptr) return 0;
    else if (root->left() == nullptr) return minDepth(root->right()) + 1;
    else if (root->right() == nullptr) return minDepth(root->left()) + 1;
    else return std::min(minDepth(root->left()), minDepth(root->right())) + 1;
}

int main() {
  init_tree();
  root->print();

  std::cout << "-------------" << std::endl;

  std::cout << maxDepth(root.get()) << std::endl;
  std::cout << minDepth(root.get()) << std::endl;
  std::cout << minDepth2(root.get()) << std::endl;
}
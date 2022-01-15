#include <iostream>
#include <vector>

#include "common/tree_node.h"


void preorder_traversal(TreeNode* node, std::vector<int>& result) {
  if (node == nullptr)
    return;
  result.push_back(node->value());
  preorder_traversal(node->left(), result);
  preorder_traversal(node->right(), result);
}

void inorder_traversal(TreeNode* node, std::vector<int>& result) {
  if (node == nullptr)
    return;
  inorder_traversal(node->left(), result);
  result.push_back(node->value());
  inorder_traversal(node->right(), result);
}

void postorder_traversal(TreeNode* node, std::vector<int>& result) {
  if (node == nullptr)
    return;
  postorder_traversal(node->left(), result);
  postorder_traversal(node->right(), result);
  result.push_back(node->value());
}

void print_vector(const std::vector<int>& vec) {
  for (const auto& v : vec) {
    std::cout << v << ", ";
  }
  std::cout << std::endl;
}


int main() {
  init_tree();
  root->print();

  std::cout << "-------------" << std::endl;

  std::vector<int> result;
  preorder_traversal(root.get(), result);
  print_vector(result);

  result.clear();
  inorder_traversal(root.get(), result);
  print_vector(result);

  result.clear();
  postorder_traversal(root.get(), result);
  print_vector(result);

  return 0;
}
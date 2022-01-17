#include <iostream>
#include <vector>
#include <stack>

#include "common/tree_node.h"

// 使用递归进行前序、中序、后序遍历

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

// 迭代法

std::vector<int> preorder_traversal(TreeNode* root) {
  std::stack<TreeNode*> st;
  std::vector<int> result;
  if (root == nullptr) return result;

  st.push(root);
  while (!st.empty()) {
    auto* node = st.top();
    result.push_back(node->value());
    st.pop();
    if (node->right() != nullptr) st.push(node->right());
    if (node->left() != nullptr) st.push(node->left());
  }
  return result;
}

std::vector<int> inorder_traversal(TreeNode* root) {
  std::stack<TreeNode*> st;
  std::vector<int> result;
  if (root == nullptr) return result;

  st.push(root);
  
  while (!st.empty()) {
    auto* node = st.top();
    if (node->left() != nullptr) {
      st.push(node->left());
    }
    else {
      result.push_back(node->value());
      st.pop();
      if (st.empty())
        return result;
      node = st.top();
      result.push_back(node->value());
      st.pop();
      if (node->right() != nullptr) st.push(node->right());
    }
  }
  return result;
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

  std::cout << "-------------" << std::endl;

  result = preorder_traversal(root.get());
  print_vector(result);

  result = inorder_traversal(root.get());
  print_vector(result);

  return 0;
}
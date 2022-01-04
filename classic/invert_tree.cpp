#include <vector>
#include <iostream>

#include "common/tree_node.h"

// 将整棵树的节点翻转
TreeNode* invertTree(TreeNode* root) {
  // base case
  if (root == nullptr) {
    return nullptr;
  }

  /**** 前序遍历位置 ****/
  // root 节点需要交换它的左右子节点
  TreeNode* tmp = root->left();
  root->set_left(root->right());
  root->set_right(tmp);
  // std::swap(root->left(), root->right())；

  // 让左右子节点继续翻转它们的子节点
  invertTree(root->left());
  invertTree(root->right());

  return root;
}

int main() {
  init_tree();
  root->print();

  std::cout << "-------------" << std::endl;

  auto* invert_root = invertTree(root.get());
  invert_root->print();

  return 0;
}
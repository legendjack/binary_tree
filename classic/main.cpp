#include <iostream>
#include <vector>

#include "common/tree_node.h"

// 将整棵树的节点翻转
TreeNode *invertTree(TreeNode *root) {
  // base case
  if (root == nullptr) {
    return nullptr;
  }

  /**** 前序遍历位置 ****/
  // root 节点需要交换它的左右子节点
  TreeNode *tmp = root->left();
  root->set_left(root->right());
  root->set_right(tmp);
  // std::swap(root->left(), root->right())；

  // 让左右子节点继续翻转它们的子节点
  invertTree(root->left());
  invertTree(root->right());

  return root;
}

// 输入两个节点，将他们连接起来
void connectTwoNodes(TreeNode *n1, TreeNode *n2) {
  if (n1 == nullptr || n2 == nullptr)
    return;
  /**** 前序遍历位置 ****/
  // 将传入的两个节点连接
  n1->set_next(n2);
  // 连接相同父节点的两个子节点
  connectTwoNodes(n1->left(), n1->right());
  connectTwoNodes(n2->left(), n2->right());
  // 连接跨越父节点的两个子节点
  connectTwoNodes(n1->right(), n2->left());
}

// 主函数
TreeNode *connect(TreeNode *root) {
  if (root == nullptr)
    return nullptr;

  connectTwoNodes(root->left(), root->right());
}

void flatten(TreeNode *root) {}

int main() {
  init_tree();
  root->print();

  std::cout << "-------------" << std::endl;

  //   auto* invert_tree = invertTree(root.get());
  //   invert_tree->print();

  connect(root.get());
  node4->print_next();
  node2->print_next();
  node1->print_next();

  // flatten(root);
  // root.print_next();

  return 0;
}
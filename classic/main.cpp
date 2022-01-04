#include <iostream>
#include <vector>

#include "common/tree_node.h"

void print_next(TreeNode *root) {
  if (root == nullptr) {
    std::cout << std::endl;
    return;
  }

  std::cout << root->value() << " ";
  print_next(root->next());
}

void print_right(TreeNode *node) {
  if (node == nullptr) {
    std::cout << std::endl;
    return;
  }

  std::cout << node->value() << " ";

  print_right(node->right());
};

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
void connect(TreeNode *root) {
  if (root == nullptr)
    return;

  connectTwoNodes(root->left(), root->right());
}

void flatten(TreeNode *root) {
  if (root == nullptr)
    return;

  // 先flatten左右子树
  flatten(root->left());
  flatten(root->right());

  // 到这里认为左右子树已经flatten
  // 然后把左子树当做右子树, 之前的右子树接到现在的右子树的最后
  auto *left = root->left();
  auto *right = root->right();

  root->set_left(nullptr);
  root->set_right(left);

  TreeNode *tmp = root;
  while (tmp->right() != nullptr) {
    tmp = tmp->right();
  }
  tmp->set_right(right);
}

int main() {
  init_tree();
  root->print();

  std::cout << "-------------" << std::endl;

  // auto* invert_tree = invertTree(root.get());
  // invert_tree->print();

  // connect(root.get());
  // print_next(node4.get());
  // print_next(node2.get());
  // print_next(node1.get());

  flatten(root.get());
  print_right(root.get());

  return 0;
}
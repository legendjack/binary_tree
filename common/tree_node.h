#pragma once

#include <memory>
#include <vector>

class TreeNode {
public:
  TreeNode(int v);
  ~TreeNode();
  int value() { return value_; }
  TreeNode *left() { return left_; }
  TreeNode *right() { return right_; }
  TreeNode *next() { return next_; }
  void set_left(TreeNode *left) { left_ = left; }
  void set_right(TreeNode *right) { right_ = right; }
  void set_next(TreeNode *next) { next_ = next; }
  void print();
  void print_next();

private:
  TreeNode *left_ = nullptr;
  TreeNode *right_ = nullptr;
  TreeNode *next_ = nullptr;

  int value_ = 0;
};

static auto node1 = std::make_shared<TreeNode>(1);
static auto node2 = std::make_shared<TreeNode>(2);
static auto node3 = std::make_shared<TreeNode>(3);
static auto node4 = std::make_shared<TreeNode>(4);
static auto node6 = std::make_shared<TreeNode>(6);
static auto node7 = std::make_shared<TreeNode>(7);
static auto node9 = std::make_shared<TreeNode>(9);

static std::shared_ptr<TreeNode> root = node4;

static void init_tree() {
  node4->set_left(node2.get());
  node4->set_right(node7.get());
  node2->set_left(node1.get());
  node2->set_right(node3.get());
  node7->set_left(node6.get());
  node7->set_right(node9.get());
}

/*
    4
   / \
  2   7
 / \ / \
1  3 6  9

*/
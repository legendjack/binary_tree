#include "tree_node.h"

#include <iostream>

TreeNode::TreeNode(int v) : value_(v) {}

TreeNode::~TreeNode() {}

void TreeNode::print() {
  if (this == nullptr) {
    return;
  }

  std::cout << "  " << value_ << std::endl;
  std::cout << " / \\" << std::endl;

  if (left_ != nullptr) {
    std::cout << left_->value();
  } else {
    std::cout << " ";
  }
  std::cout << "   ";

  if (right_ != nullptr) {
    std::cout << right_->value() << "\n";
  }
  std::cout << std::endl;

  left_->print();
  right_->print();
}

void TreeNode::print_next() {
  if (this == nullptr) {
    std::cout << std::endl;
    return;
  }

  std::cout << value_ << " ";
  next_->print_next();
}
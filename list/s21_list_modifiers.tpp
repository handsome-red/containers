#pragma once

#include "s21_list.h"

namespace s21 {

template <typename T>
void s21::list<T>::clear() {
  while (head_) {
    Node* next_node = head_->next;
    delete head_;
    head_ = next_node;
  }
  head_ = nullptr;
  tail_ = nullptr;
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::insert(iterator pos,
                                                     const_reference value) {
  return iterator();
}

template <typename T>
void s21::list<T>::push_front(const_reference value) {
  Node* new_node = new Node(value, nullptr, nullptr);

  if (this->head_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->next = head_;
    head_->prev = new_node;
    head_ = new_node;
  }
  ++size_;
}

template <typename T>
void s21::list<T>::push_back(const_reference value) {
  Node* new_node = new Node{value, nullptr, nullptr};

  if (this->tail_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    tail_->next = new_node;  // (10) -(next)-> (20)
    new_node->prev = tail_;  // (10) <-(prev)- (20)
    tail_ = new_node;        //
  }

  ++size_;
}

template <typename T>
void s21::list<T>::reverse() {
  Node* current = head_;

  while (current != nullptr) {
    std::swap(current->next, current->prev);
    current = current->next;
  }

  std::swap(this->head_, this->tail_);
}

}  // namespace s21
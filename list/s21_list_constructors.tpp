#pragma once

#include "s21_list.h"

namespace s21 {

/**
 * default constructor
 */
template <typename T>
s21::list<T>::list() : head_(nullptr), tail_(nullptr), size_(0) {}
// s21::list<T>::list() : size_(0) {
//   fake_node = new Node(T(), nullptr, nullptr);
//   fake_node->next = fake_node;
//   fake_node->prev = fake_node;
// }

/**
 * parameterized constructor
 */
template <typename T>
s21::list<T>::list(size_type n) : head_(nullptr), tail_(nullptr), size_(0) {
  while (n--) {
    push_back(T());
  }
}

/**
 * initializer list constructor
 */
template <typename T>
s21::list<T>::list(std::initializer_list<value_type> const& items)
    : head_(nullptr), tail_(nullptr), size_(0) {
  for (const auto& i : items) {
    push_back(i);
  }
}

/**
 * copy constructor
 */
template <typename T>
s21::list<T>::list(const list& l) : head_(nullptr), tail_(nullptr), size_(0) {
  for (const auto& i : l) {
    push_back(i);
  }
}

/**
 * move constructor
 */
template <typename T>
s21::list<T>::list(list&& l) : head_(l.head_), tail_(l.tail_), size_(l.size_) {
  l.head_ = nullptr;
  l.tail_ = nullptr;
  l.size_ = 0;
}

/**
 * destructor
 */
template <typename T>
s21::list<T>::~list() {
  s21::list<T>::clear();
}

/**
 * assignment operator overload for moving object
 */
template <typename T>
s21::list<T>& s21::list<T>::operator=(list&& l) {
  while (head_) {
    Node* next_node = head_->next;
    delete head_;
    head_ = next_node;
  }

  this->head_ = l.head_;
  this->tail_ = l.tail_;
  this->size_ = l.size_;
  l.head_ = nullptr;
  l.tail_ = nullptr;
  l.size_ = 0;

  return *this;
}

}  // namespace s21
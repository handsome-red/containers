#pragma once

#include "s21_list.h"

namespace s21 {

template <typename T>
void s21::list<T>::clear() {
  while (!empty()) {
    pop_front();
  }
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::insert(iterator pos,
                                                     const_reference value) {
  Node* new_node = new Node(value, pos.ptr_, pos.ptr_->next);

  pos.ptr_->prev->next = new_node;
  pos.ptr_->prev = new_node;

  ++size_;

  return iterator(new_node);
}

template <typename T>
void s21::list<T>::erase(iterator pos) {
  if (empty() || pos.ptr_ == fake_node_) return;

  Node* to_delete = pos.ptr_;

  pos.ptr_->prev->next = pos.ptr_->next;
  pos.ptr_->next->prev = pos.ptr_->prev;

  delete to_delete;

  --size_;
}

template <typename T>
void s21::list<T>::push_back(const_reference value) {
  insert(end(), value);
}

template <typename T>
void s21::list<T>::pop_back() {
  if (!empty()) {
    erase(--end());
  }
}

template <typename T>
void s21::list<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename T>
void s21::list<T>::pop_front() {
  if (!empty()) {
    erase(begin());
  }
}
template <typename T>
void s21::list<T>::swap(list& other) noexcept {
  std::swap(fake_node_, other.fake_node_);
  std::swap(size_, other.size_);
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
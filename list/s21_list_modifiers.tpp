#pragma once

#include "s21_list.h"

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

/* Переписать с использованием splice */
template <typename T>
void s21::list<T>::merge(list& other) {
  if (*this == other) {
    return;
  }

  list<T> result;

  auto itOne = this.begin();
  auto itTwo = other.begin();
  while (itOne != this->end() && itTwo != other.end()) T valueOne = *itOne;
  T valueTwo = *itTwo;

  if (valueOne < valueTwo) {
    result.push_back(valueOne);
    ++itOne;
  } else if (valueTwo < valueOne) {
    result.push_back(valueTwo);
    ++itTwo;
  } else {
    result.push_back(valueOne);
    result.push_back(valueTwo);
    ++itOne;
    ++itTwo;
  }

  while (itOne != *this.end()) {
    int valueOne = *itOne;
    result.push_back(valueOne);
    ++itOne;
  }

  while (itTwo != other.end()) {
    int valueTwo = *itTwo;
    result.push_back(valueTwo);
    ++itTwo;
  }

  *this = result;
}

template <typename T>
void s21::list<T>::splice(const_iterator pos, list& other) {
  if (other.empty()) {
    return;
  }

  other.fake_node_->next->prev = pos.ptr_->prev;
  other.fake_node_->prev->next = pos.ptr_;

  pos.ptr_->prev->next = other.fake_node_->next;
  pos.ptr_->prev = other.fake_node_->prev;

  this->size_ += other.size_;
  other.size_ = 0;

  other.fake_node_->next = other.fake_node_;
  other.fake_node_->prev = other.fake_node_;
}

template <typename T>
void s21::list<T>::reverse() noexcept {
  if (size_ == 1) {
    return;
  }

  Node* tmp = fake_node_->next;
  while (tmp->next != fake_node_) {
    tmp->next->prev =
  }
}

template <typename T>
void s21::list<T>::unique() {
  if (size_ < 2) {
    return;
  }

  auto current = this->begin();
  auto next = current;
  ++next;

  while (next != this->end()) {
    if (*current == *next) {
      auto to_delete = next;
      next++;
      erase(to_delete);
    } else {
      current = next;
      ++next;
    }
  }
}

template <typename T>
void s21::list<T>::sort() {
  if (size_ == 1) {
    return;
  }

  list<T> left;
  list<T> right;

  auto current = this->begin();
}

#pragma once

#include "s21_list.h"

namespace s21 {
template <typename T>
bool s21::list<T>::empty() const noexcept {
  return size_ == 0;
}

template <typename T>
typename s21::list<T>::size_type s21::list<T>::size() const noexcept {
  return size_;
}

template <typename T>
typename s21::list<T>::size_type s21::list<T>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(Node);
}
}  // namespace s21
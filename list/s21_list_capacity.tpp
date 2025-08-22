#pragma once

#include "s21_list.h"

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
  return std::allocator<Node>().max_size();
}
#pragma once

#include "s21_list.h"

namespace s21 {

/**
 * access the first element
 */
template <typename T>
typename s21::list<T>::const_reference s21::list<T>::front() const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  return this->head_->value_;
}

/**
 * access the last element
 */
template <typename T>
typename s21::list<T>::const_reference s21::list<T>::back() const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  return this->tail_->value_;
}
}  // namespace s21

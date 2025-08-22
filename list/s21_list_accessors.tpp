#pragma once

#include "s21_list.h"

template <typename T>
typename s21::list<T>::const_reference s21::list<T>::front() const {
  // if (empty()) {    throw std::out_of_range("List is empty");}
  return this->fake_node_->next->value_;
}

template <typename T>
typename s21::list<T>::reference s21::list<T>::front() {
  // if (empty()) {    throw std::out_of_range("List is empty");}
  return this->fake_node_->next->value_;
}

template <typename T>
typename s21::list<T>::const_reference s21::list<T>::back() const {
  // if (empty()) {    throw std::out_of_range("List is empty");}
  return this->fake_node_->prev->value_;
}

template <typename T>
typename s21::list<T>::reference s21::list<T>::back() {
  // if (empty()) {    throw std::out_of_range("List is empty");}
  return this->fake_node_->prev->value_;
}

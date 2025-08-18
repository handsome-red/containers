#pragma once

#include "s21_list.h"

namespace s21 {
/* ListIterator construct*/

template <typename T>
typename s21::list<T>::ListIterator& s21::list<T>::ListIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

template <typename T>
s21::list<T>::ListIterator::ListIterator() : ptr(nullptr) {}

template <typename T>
s21::list<T>::ListIterator::ListIterator(typename s21::list<T>::Node* current)
    : ptr(current) {}

template <typename T>
typename s21::list<T>::reference s21::list<T>::ListIterator::operator*() const {
  if (!ptr) throw std::out_of_range("Dereferencing end iterator");
  return ptr->value_;
}

template <typename T>
typename s21::list<T>::ListIterator& s21::list<T>::ListIterator::operator--() {
  if (ptr) ptr = ptr->prev;
  ptr = ptr->prev;
  return *this;
}

template <typename T>
bool s21::list<T>::ListIterator::operator==(
    const ListIterator& other) const {  // add nullptr
  return this->ptr == other.ptr;
}

template <typename T>
bool s21::list<T>::ListIterator::operator!=(const ListIterator& other) const {
  return !(*this == other);
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::begin() {
  return iterator(head_);
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::end() {
  return iterator(nullptr);
}
}  // namespace s21
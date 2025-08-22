#pragma once

#include "s21_list.h"

namespace s21 {

template <typename T>
typename s21::list<T>::iterator s21::list<T>::begin() noexcept {
  return iterator(fake_node_->next);
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::end() noexcept {
  return iterator(fake_node_);
}

template <typename T>
typename s21::list<T>::const_iterator s21::list<T>::begin() const noexcept {
  return const_iterator(fake_node_->next);
}

template <typename T>
typename s21::list<T>::const_iterator s21::list<T>::end() const noexcept {
  return const_iterator(fake_node_);
}

template <typename T>
typename s21::list<T>::const_iterator s21::list<T>::cbegin() const noexcept {
  return const_iterator(fake_node_->next);
}

template <typename T>
typename s21::list<T>::const_iterator s21::list<T>::cend() const noexcept {
  return const_iterator(fake_node_);
}

/////////////////////

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

}  // namespace s21
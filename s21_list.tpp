#include "s21_containersplus.h"

// construct without parametrs
template <typename T>
s21::list<T>::list() : head_(nullptr), tail_(nullptr), size_type(0) {}

template <typename T>
s21::list<T>::list(size_type n) {
  for (size_t i = 0; i < n; i++) {
    ;
  }
}

template <typename T>
s21::list<T>::list(std::initializer_list<value_type> const& items) {
  ;
}

template <typename T>
s21::list<T>::list(const list& l) {
  ;
}

template <typename T>
s21::list<T>::list(list&& l) {
  ;
}

template <typename T>
s21::list<T>::~list() {
  ;
}

template <typename T>
s21::list<T>::operator=(list&& l) {
  ;
}

template <typename T>
void s21::list<T>::push_back(const_reference value) {
  Node<T>* new_node = new Node<T>{value, nullptr, nullptr};

  if (this->head_ == nullptr && this->tail_ nullptr) {
    /* code */
  }

  size_type++;
}
// template <typename T>
// iterator insert(iterator pos, const_reference value)

template <typename T>
s21::list<T>::iterator s21::list<T>::ListIterator::begin() {
  ;
}

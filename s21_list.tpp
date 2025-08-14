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

  if (this->tail_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    tail_->next = new_node;  // (10) -(next)-> (20)
    new_node->prev = tail_;  // (10) <-(prev)- (20)
    tail_ = new_node;        //
  }

  size_type++;
}
template <typename T>
s21::list<T>::iterator s21::list<T>::begin() {
  return iterator(head_);
}

template <typename T>
s21::list<T>::iterator s21::list<T>::end() {
  return iterator(tail_);
}

/* ListIterator construct*/
template <typename T>
s21::list<T>::ListIterator::ListIterator() : ptr(nullptr) {}

template <typename T>
s21::list<T>::ListIterator::ListIterator(Node<T>* current) : ptr(current) {}

template <typename T>
s21::list<T>::reference s21::list<T>::ListIterator::operator*() const {
  return ptr->value_;
}

template <typename T>
s21::list<T>::ListIterator& s21::list<T>::ListIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

template <typename T>
s21::list<T>::ListIterator& s21::list<T>::ListIterator::operator--() {
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
  return *this->ptr != other.ptr;
}
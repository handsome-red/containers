#pragma once

#include <cstddef>           // for size_t
#include <initializer_list>  // Нужно ли реализовывать???

namespace s21 {

template <typename T>
struct Node {
  T value_;
  Node<T>* prev;
  Node<T>* next;
};

template <typename T>
class list {
 private:
  Node<T>* head_;
  Node<T>* tail_;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;  // learn using

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  operator=(list && l);

  iterator begin();
  iterator end();

  void push_back(const_reference value);

  class ListIterator {
   public:
    Node<T>* ptr;

    ListIterator();
    ListIterator(Node<T>* current);  // change Node

    reference operator*() const;
    ListIterator& operator++();
    ListIterator& operator--();
    bool operator==(const ListIterator& other) const;
    bool operator!=(const ListIterator& other) const;
  };
};
}  // namespace s21

#include "s21_list.tpp"

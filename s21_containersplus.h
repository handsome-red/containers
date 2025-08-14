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

  void push_back(const_reference value);

  class ListIterator {
   public:
    reference itr;

    iterator begin();
    iterator end();
  };
};
}  // namespace s21

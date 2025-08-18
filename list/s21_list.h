#pragma once

#include <algorithm>         // Нужно ли реализовывать???
#include <cstddef>           // for size_t
#include <initializer_list>  // Нужно ли реализовывать???

namespace s21 {

template <typename T>
class list {
 private:
  using const_reference = const T&;
  using size_type = size_t;  // learn using

  struct Node {
    T value_;
    Node* prev;
    Node* next;

    Node(const T& val, Node* p, Node* n) : value_(val), prev(p), next(n) {};
  };

  Node* fake_node;

  Node* head_;
  Node* tail_;
  size_type size_;

 public:
  class ListIterator;
  class ListConstIterator;

  using value_type = T;
  using reference = T&;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();

  list& operator=(list&& l);

  const_reference front() const;
  const_reference back() const;

  iterator begin();
  iterator end();

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;  // i dont care

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();  //
  void unique();
  void sort();

  class ListIterator {
   public:
    Node* ptr;

    ListIterator();
    ListIterator(Node* current);  // change Node

    reference operator*() const;
    ListIterator& operator++();
    ListIterator& operator--();
    bool operator==(const ListIterator& other) const;
    bool operator!=(const ListIterator& other) const;
  };
};
}  // namespace s21

#include "./s21_list_accessors.tpp"
#include "./s21_list_capacity.tpp"
#include "./s21_list_constructors.tpp"
#include "./s21_list_iterators.tpp"
#include "./s21_list_modifiers.tpp"
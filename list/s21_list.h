#pragma once

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <limits>  // для max_size()

namespace s21 {

template <typename T>
class list {
 private:
  struct Node {
    T value_;
    Node* prev;
    Node* next;

    Node(const T& val, Node* p, Node* n) : value_(val), prev(p), next(n) {}
  };

  Node* fake_node_;
  size_t size_;

 public:
  class ListIterator;
  class ListConstIterator;

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

  // Конструкторы
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l) noexcept;
  ~list();

  // Операторы присваивания
  list& operator=(const list& l);
  list& operator=(list&& l) noexcept;

  // Доступ к элементам
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;

  // Итераторы
  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  // Емкость
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  // Модификаторы
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other) noexcept;
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse() noexcept;
  void unique();
  void sort();

  // Класс итератора
  class ListIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    Node* ptr_;

    ListIterator() : ptr_(nullptr) {}
    explicit ListIterator(Node* current) : ptr_(current) {}

    reference operator*() const { return ptr_->value_; }
    pointer operator->() const { return &ptr_->value_; }

    ListIterator& operator++();
    ListIterator operator++(int);
    ListIterator& operator--();
    ListIterator operator--(int);

    bool operator==(const ListIterator& other) const;
    bool operator!=(const ListIterator& other) const;
  };

  class ListConstIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    const Node* ptr_;

    ListConstIterator() : ptr_(nullptr) {}
    explicit ListConstIterator(const Node* current) : ptr_(current) {}
    ListConstIterator(const ListIterator& it) : ptr_(it.ptr_) {}  // конверсия

    reference operator*() const { return ptr_->value_; }
    pointer operator->() const { return &ptr_->value_; }

    ListConstIterator& operator++();
    ListConstIterator operator++(int);
    ListConstIterator& operator--();
    ListConstIterator operator--(int);

    bool operator==(const ListConstIterator& other) const;
    bool operator!=(const ListConstIterator& other) const;
  };
};
}  // namespace s21
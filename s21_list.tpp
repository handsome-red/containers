#include "s21_containersplus.h"

// construct without parametrs
template <typename T>
s21::list<T>::list() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
s21::list<T>::list(size_type n) : head_(nullptr), tail_(nullptr), size_(0) {
  while (n--) {
    push_back(T());
  }
}

template <typename T>
s21::list<T>::list(std::initializer_list<value_type> const& items)
    : head_(nullptr), tail_(nullptr), size_(0) {
  for (const auto& i : items) {
    push_back(i);
  }
}

template <typename T>
s21::list<T>::list(const list& l) : head_(nullptr), tail_(nullptr), size_(0) {
  for (const auto& i : l) {
    push_back(i);
  }
}

template <typename T>
s21::list<T>::list(list&& l) : head_(l.head_), tail_(l.tail_), size_(l.size_) {
  l.head_ = nullptr;
  l.tail_ = nullptr;
  l.size_ = 0;
}

template <typename T>
s21::list<T>::~list() {
  while (head_) {
    Node* next_node = head_->next;
    delete head_;
    head_ = next_node;
  }
}

template <typename T>
s21::list<T>& s21::list<T>::operator=(list&& l) {
  while (head_) {
    Node* next_node = head_->next;
    delete head_;
    head_ = next_node;
  }

  this->head_ = l.head_;
  this->tail_ = l.tail_;
  this->size_ = l.size_;
  l.head_ = nullptr;
  l.tail_ = nullptr;
  l.size_ = 0;

  return *this;
}

template <typename T>
s21::list<T>::const_reference s21::list<T>::front() {
  if (!head_->value_) {  // empty()
    throw std::out_of_range("List is empty");
  }

  return this->head_->value_;
}

template <typename T>
s21::list<T>::const_reference s21::list<T>::back() {
  if (!tail_->value_) {  // empty()
    throw std::out_of_range("List is empty");
  }

  return this->tail_->value_;
}

template <typename T>
bool s21::list<T>::empty() {
  // return true ? (this->tail_ == nullptr && this->head_ == nullptr) : false;
  return size_ == 0;
}

template <typename T>
typename s21::list<T>::size_type s21::list<T>::size() const noexcept {
  return size_;
}

template <typename T>
s21::list<T>::size_type s21::list<T>::max_size() {
  if (size_ == 0) {
    return 0;
  }

  auto max_value(T());

  for (const auto& i : this) {
    if (max_value < i) {
      max_value = i;
    }
  }

  return 0;
}

template <typename T>
void s21::list<T>::reverse() {
  for (const auto& elem : this) {
  }
}

// 1 2 3 4 5
// 5 4 3 2 1

template <typename T>
void s21::list<T>::push_front(const_reference value) {
  Node* new_node = new Node(value, nullptr, nullptr);

  if (this->head_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->next = head_;
    head_->prev = new_node;
    head_ = new_node;
  }
  ++size_;
}

template <typename T>
void s21::list<T>::push_back(const_reference value) {
  Node* new_node = new Node{value, nullptr, nullptr};

  if (this->tail_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    tail_->next = new_node;  // (10) -(next)-> (20)
    new_node->prev = tail_;  // (10) <-(prev)- (20)
    tail_ = new_node;        //
  }

  ++size_;
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::begin() {
  return iterator(head_);
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::end() {
  return iterator(nullptr);
}

/* ListIterator construct*/
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
typename s21::list<T>::ListIterator& s21::list<T>::ListIterator::operator++() {
  ptr = ptr->next;
  return *this;
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
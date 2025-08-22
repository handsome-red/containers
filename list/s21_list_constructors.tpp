#pragma once

#include "s21_list.h"

template <typename T>
s21::list<T>::list() : size_(0) {
  fake_node_ = new Node(T(), nullptr, nullptr);
  fake_node_->next = fake_node_;
  fake_node_->prev = fake_node_;
}

template <typename T>
s21::list<T>::list(size_type n) : list() {
  try {
    while (n--) {
      push_back(T());  // заменить на emplace_back
    }
  } catch (...) {
    clear();
    throw;
  }
}

template <typename T>
s21::list<T>::list(std::initializer_list<value_type> const& items) : list() {
  try {
    for (const auto& item : items) {
      push_back(item);
    }
  } catch (...) {
    clear();
    throw;
  }
}

template <typename T>
s21::list<T>::list(const list& l) : list() {
  if (this == &l) {
    return;
  }

  try {
    for (const auto& item : l) {
      push_back(item);
    }
  } catch (...) {
    clear();
    throw;
  }
}

template <typename T>
s21::list<T>::list(list&& l) noexcept : list() {
  std::swap(fake_node_, l.fake_node_);
  std::swap(size_, l.size_);
}

template <typename T>
s21::list<T>::~list() {
  if (fake_node_) {
    s21::list<T>::clear();
    delete fake_node_;
    fake_node_ = nullptr;
  }
}

template <typename T>
s21::list<T>& s21::list<T>::operator=(const list& l) {
  if (this != &l) {
    list temp(l);
    std::swap(temp);
  }
  return *this;
}

template <typename T>
s21::list<T>& s21::list<T>::operator=(list&& l) noexcept {
  if (this != &l) {
    list temp(std::move(l));
    std::swap(temp);
  }
  return *this;
}
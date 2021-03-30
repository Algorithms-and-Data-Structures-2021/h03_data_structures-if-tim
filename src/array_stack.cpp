#include "array_stack.hpp"

#include <algorithm>  // copy, fill
#include <cassert>    // assert
#include <stdexcept>  // logic_error, invalid_argument

namespace itis {

ArrayStack::ArrayStack(int capacity) {
  if (capacity <= 0) {
    throw std::invalid_argument("initial capacity must be greater than zero");
  }

  // TODO: напишите здесь свой код ...
  capacity_ = capacity;
  data_ = new Element[capacity_]{Element::UNDEFINED};
}

ArrayStack::~ArrayStack() {
  // TODO: напишите здесь свой код ...
  delete data_;
  size_ = 0;
  capacity_ = 0;
  data_ = nullptr;
}

void ArrayStack::Push(Element e) {
  // TODO: напишите здесь свой код ...
    if (size_ == capacity_) {
        resize(capacity_ + kCapacityGrowthCoefficient);
    }
    data_[size_] = e;
    size_++;
}

void ArrayStack::Pop() {
  if (size_ == 0) {
    throw std::logic_error("cannot pop out from empty stack");
  }

  // TODO: напишите здесь свой код ...
  data_[size_ - 1] = Element::UNDEFINED;
  size_--;
}

void ArrayStack::Clear() {
  // TODO: напишите здесь свой код ...

  for (int i = 0; i < size_; i++) {
      data_[i] = Element::UNDEFINED;
  }
  size_ = 0;
}

void ArrayStack::resize(int new_capacity) {
  assert(new_capacity > size_);

  // TODO: напишите здесь свой код ...
  Element* newData = new Element[new_capacity];
  std::copy(data_, data_ + capacity_, newData);
  delete data_;
  data_ = newData;
  capacity_ = new_capacity;
}

// === РЕАЛИЗОВАНО ===

std::optional<Element> ArrayStack::Peek() const {
  // возвращаем вершину стека или ничего (nullopt), если стек пустой
  return size_ == 0 ? std::nullopt : std::make_optional(data_[size_ - 1]);
}

bool ArrayStack::IsEmpty() const {
  return size_ == 0;
}

int ArrayStack::size() const {
  return size_;
}

int ArrayStack::capacity() const {
  return capacity_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const ArrayStack &stack) {
  os << "size: " << stack.size_ << '\n';
  if (stack.data_ != nullptr) {
    // выводим элементы сверху вниз
    for (int index = stack.size_ - 1; index >= 0; index--) {
      if (index == stack.size_ - 1) os << "[TOP] ";
      os << enum2str(stack.data_[index]) << '\n';
    }
  }
  return os;
}

}  // namespace itis
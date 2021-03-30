#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
  // TODO: напишите здесь свой код ...
  if (this ->IsEmpty()) {
      DoublyNode* newNode = new DoublyNode(e, nullptr, nullptr);
      front_ = newNode;
      back_ = newNode;
      size_++;
      return;
  }
  DoublyNode* newNode = new DoublyNode(e, back_, nullptr);
  back_ -> next = newNode;
  back_ = newNode;
  size_++;
}

void LinkedDequeue::EnqueueFront(Element e) {
  // TODO: напишите здесь свой код ...
  if (this -> IsEmpty()) {
      DoublyNode* newNode = new DoublyNode(e, nullptr, nullptr);
      front_ = newNode;
      back_ = newNode;
      size_++;
      return;
  }
  DoublyNode* newNode = new DoublyNode(e, nullptr, front_);
  front_ -> previous = newNode;
  front_ = newNode;
  size_++;
}

void LinkedDequeue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  // TODO: напишите здесь свой код ...
    if (size_ == 1) {
        back_ = nullptr;
    }
    DoublyNode* toDelete = front_;
    front_ = front_ -> next;
    delete toDelete;
    size_--;
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  // TODO: напишите здесь свой код ...
  DoublyNode* toDelete = back_;
  back_ = back_ -> previous;
  if (back_ == nullptr) {
      front_ = nullptr;
  } else {
      back_ -> next = nullptr;
  }
  delete toDelete;
  size_--;
}

void LinkedDequeue::Clear() {
  // TODO: напишите здесь свой код ...

    for (DoublyNode* curr_node = back_; curr_node != nullptr; /* Do nothing */) {
        DoublyNode* delete_node = curr_node;
        curr_node = curr_node -> next;
        delete delete_node;
    }

    front_ = nullptr;
    back_ = nullptr;
    size_ = 0;
}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis

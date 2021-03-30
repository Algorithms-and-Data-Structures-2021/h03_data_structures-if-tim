#include "linked_queue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedQueue::Enqueue(Element e) {
  // TODO: напишите здесь свой код ...
  if (this->IsEmpty()) {
      SinglyNode* newNode = new SinglyNode(e, nullptr);
      front_ = newNode;
      back_ = newNode;
      size_++;
      return;
  }
  SinglyNode* newNode = new SinglyNode(e, nullptr);
  back_ -> next = newNode;
  back_ = newNode;
  size_++;
}

void LinkedQueue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("could not dequeue from empty queue");
  }

  // TODO: напишите здесь свой код ...
  SinglyNode* toDelete = front_;
  front_ = front_ -> next;
  if (front_ == nullptr) {
      back_ = nullptr;
  }
  delete toDelete;
  size_--;
}

void LinkedQueue::Clear() {
  // TODO: напишите здесь свой код ...
  for (SinglyNode* currentNode = front_; currentNode != 0;) {
      SinglyNode* nodeToDelete = currentNode;
      currentNode = currentNode -> next;
      delete nodeToDelete;
  }
  front_ = nullptr;
  back_ = nullptr;
  size_ = 0;
}

// === РЕАЛИЗОВАНО ===

LinkedQueue::~LinkedQueue() {
  Clear();
}

std::optional<Element> LinkedQueue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedQueue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedQueue::IsEmpty() const {
  return size_ == 0;
}
int LinkedQueue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedQueue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
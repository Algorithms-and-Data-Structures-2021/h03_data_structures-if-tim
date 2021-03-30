#include "linked_stack.hpp"

#include <stdexcept>  // logic_error
#include <iostream>

namespace itis {

    void LinkedStack::Push(Element e) {
        // TODO: напишите здесь свой код ...
        SinglyNode *previousNode = top_;
        top_ = new SinglyNode(e, nullptr);
        top_ -> next = previousNode;
        size_++;
    }

    void LinkedStack::Pop() {
        if (top_ == nullptr) {
            throw std::logic_error("cannot pop out from empty stack");
        }
        // TODO: напишите здесь свой код ...
        SinglyNode* toDelete = top_;
        top_ = top_ -> next;
        size_--;
        delete toDelete;
    }

    void LinkedStack::Clear() {
        // TODO: напишите здесь свой код ...
        SinglyNode* currentNode = top_;
        for (; currentNode != nullptr;) {
            SinglyNode* toDelete = currentNode;
            currentNode = currentNode -> next;
            delete toDelete;
        }
        size_ = 0;
        top_ = nullptr;
    }

// === РЕАЛИЗОВАНО ===

    LinkedStack::~LinkedStack() {
        Clear();
    }

    std::optional<Element> LinkedStack::Peek() const {
        return top_ == nullptr ? std::nullopt : std::make_optional(top_->data);
    }

    bool LinkedStack::IsEmpty() const {
        return size_ == 0;
    }

    int LinkedStack::size() const {
        return size_;
    }

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

    std::ostream &operator<<(std::ostream &os, const LinkedStack &stack) {
        os << "size: " << stack.size_ << '\n';
        for (auto current_node = stack.top_; current_node != nullptr; current_node = current_node->next) {
            if (current_node == stack.top_) os << "[TOP] ";
            os << enum2str(current_node->data) << '\n';
        }
        return os;
    }

}  // namespace itis
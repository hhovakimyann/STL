#include "include.hpp"


template <typename T, typename Container>
Stack<T, Container>::Stack() = default;

template <typename T, typename Container>
Stack<T, Container>::Stack(std::initializer_list<value_type> init) : container(init) {}

template <typename T, typename Container>
Stack<T, Container>::Stack(const Stack& other) : container(other) {}

template <typename T, typename Container>
Stack<T, Container>::Stack(Stack &&other) noexcept {
    container = std::move(other.container);
}
template <typename T, typename Container>
Stack<T, Container>::Stack(typename container_type::iterator first, typename container_type::iterator last) 
    : container(first, last) {}


template <typename T, typename Container>
Stack<T, Container>::~Stack() = default;

template <typename T, typename Container>
Stack<T, Container>& Stack<T, Container>::operator=(const Stack& other) {
    if (this != &other) {
        container = other.container;
    }
    return *this;
}


template <typename T, typename Container>
Stack<T, Container>& Stack<T, Container>::operator=(Stack&& other) noexcept {
    if (this != &other) {
        container = std::move(other.container);
    }
    return *this;
}

template <typename T, typename Container>
Stack<T, Container>& Stack<T, Container>::operator=(std::initializer_list<value_type> list) {
    container = list;
    return *this;
}

template <typename T, typename Container>
void Stack<T,Container>::push(const_reference value) {
    container.push_back(value);
}

template <typename T, typename Container>
void Stack<T,Container>::push(value_type&& value) {
    container.push_back(std::move(value));
}


template <typename T, typename Container>
void Stack<T, Container>::pop() {
    if(!container.empty()){
        container.pop_back();
    }
}


template<typename T, typename Container>
typename Stack<T, Container>::reference Stack<T,Container>::top() {
    return container.back();
}


template<typename T, typename Container>
typename Stack<T, Container>::const_reference Stack<T,Container>::top() const {
    return container.back();
}

template<typename T, typename Container>
bool Stack<T,Container>::empty() const {
    return container.empty();
}


template<typename T, typename Container>
typename Stack<T,Container>::size_type Stack<T,Container>::size() const {
    return container.size();
}

template<typename T, typename Container>
void Stack<T,Container>::swap(Stack<T,Container> & other) noexcept {
    container.swap(other.container);
}

template<typename T, typename Container>
template<class... Args >
void Stack<T,Container>::emplace( Args&&... args ) {
    container.emplace_back(std::forward<Args>(args)...);
}

template<typename T, typename Container>
bool Stack<T,Container>::operator==(const Stack<T,Container>& rhs) {
    return container == rhs.container;
}

template<typename T, typename Container>
bool Stack<T,Container>::operator!=(const Stack<T,Container>& rhs) {
    return container != rhs.container;
}


template<typename T, typename Container>
bool Stack<T,Container>::operator<(const Stack<T,Container>& rhs) {
    return container < rhs.container;
}

template<typename T, typename Container>
bool Stack<T,Container>::operator<=(const Stack<T,Container>& rhs) {
    return container <= rhs.container;
}


template<typename T, typename Container>
bool Stack<T,Container>::operator>=(const Stack<T,Container>& rhs) {
    return container >= rhs.container;
}

template<typename T, typename Container>
bool Stack<T,Container>::operator>(const Stack<T,Container>& rhs) {
    return container > rhs.container;
}



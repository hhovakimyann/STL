#include "include.hpp"

template <typename T, typename Container>
Queue<T, Container>::Queue() = default;

template <typename T, typename Container>
Queue<T, Container>::Queue(std::initializer_list<value_type> init) : container(init) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(const Queue& other) : container(other) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(Queue &&other) noexcept {
    container = std::move(other.container);
}

template <typename T, typename Container>
Queue<T, Container>::Queue(typename container_type::iterator first, typename container_type::iterator last) 
    : container(first, last) {}


template <typename T, typename Container>
Queue<T, Container>::~Queue() = default;

template <typename T, typename Container>
Queue<T, Container>& Queue<T, Container>::operator=(const Queue& other) {
    if (this != &other) {
        container = other.container;
    }
    return *this;
}


template <typename T, typename Container>
Queue<T, Container>& Queue<T, Container>::operator=(Queue&& other) noexcept {
    if (this != &other) {
        container = std::move(other.container);
    }
    return *this;
}

template <typename T, typename Container>
Queue<T, Container>& Queue<T, Container>::operator=(std::initializer_list<value_type> list) {
    container = list;
    return *this;
}

template <typename T, typename Container>
void Queue<T,Container>::push(const_reference value) {
    container.push_back(value);
}


template <typename T, typename Container>
void Queue<T,Container>::push(value_type&& value) {
    container.push_back(value);
}

template <typename T, typename Container>
void Queue<T, Container>::pop() {
    if(!container.empty()){
        container.pop_front();
    }
}

template <typename T, typename Container>
typename Queue<T,Container>::reference Queue<T,Container>::front() {
    return container.front();
}

template <typename T, typename Container>
typename Queue<T,Container>::const_reference Queue<T,Container>::front() const {
    return container.front();
}


template <typename T, typename Container>
typename Queue<T,Container>::const_reference Queue<T,Container>::back() const {
    return container.back();
}


template <typename T, typename Container>
typename Queue<T,Container>::reference Queue<T,Container>::back() {
    return container.back();
}


template<typename T, typename Container>
bool Queue<T,Container>::empty() const {
    return container.empty();
}


template<typename T, typename Container>
typename Queue<T,Container>::size_type Queue<T,Container>::size() const {
    return container.size();
}

template<typename T, typename Container>
void Queue<T,Container>::swap(Queue<T,Container> & other) noexcept {
    container.swap(other.container);
}

template<typename T, typename Container>
bool Queue<T,Container>::operator==(const Queue<T,Container>& rhs) {
    return container == rhs.container;
}

template<typename T, typename Container>
bool Queue<T,Container>::operator!=(const Queue<T,Container>& rhs) {
    return container != rhs.container;
}


template<typename T, typename Container>
bool Queue<T,Container>::operator<(const Queue<T,Container>& rhs) {
    return container < rhs.container;
}

template<typename T, typename Container>
bool Queue<T,Container>::operator<=(const Queue<T,Container>& rhs) {
    return container <= rhs.container;
}


template<typename T, typename Container>
bool Queue<T,Container>::operator>=(const Queue<T,Container>& rhs) {
    return container >= rhs.container;
}

template<typename T, typename Container>
bool Queue<T,Container>::operator>(const Queue<T,Container>& rhs) {
    return container > rhs.container;
}

template <typename T, typename Container>
template <class... Args>
void Queue<T, Container>::emplace(Args&&... args) {
    container.emplace_back(std::forward<Args>(args)...);
}
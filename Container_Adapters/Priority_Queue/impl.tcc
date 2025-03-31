#include "include.hpp"

template <typename T, typename Container, class Compare>
priority_queue<T, Container, Compare>::priority_queue() = default;

template <class T, class Container, class Compare>
priority_queue<T, Container, Compare>::priority_queue(const priority_queue &other)
{
    container = other.container;
}

template <class T, class Container, class Compare>
priority_queue<T, Container, Compare>::priority_queue(priority_queue &&other)
{
    container = std::move(other.container);
}

template <class T, class Container, class Compare>
priority_queue<T, Container, Compare> &priority_queue<T, Container, Compare>::operator=(const priority_queue &other)
{
    if (this != &other)
    {
        container.clear();
        container = other.container;
    }
    return *this;
}

template <class T, class Container, class Compare>
priority_queue<T, Container, Compare> &priority_queue<T, Container, Compare>::operator=(priority_queue &&other)
{
    if (this != &other)
    {
        container.clear();
        container = std::move(other.container);
    }
    return *this;
}
template <class T, class Container, class Compare>
priority_queue<T, Container, Compare>::~priority_queue() = default;

template <class T, class Container, class Compare>
void priority_queue<T, Container, Compare>::push(const value_type &value)
{
    container.push_back(value);
    heapify_up(container.size() - 1);
}

template <class T, class Container, class Compare>
void priority_queue<T, Container, Compare>::push(value_type &&value)
{
    container.push_back(std::move(value));
    heapify_up(container.size() - 1);
}
template <class T, class Container, class Compare>
void priority_queue<T, Container, Compare>::pop()
{
    if (container.empty())
        return;
    std::swap(container.front(), container.back());
    container.pop_back();
    heapify_down(0);
}
template <class T, class Container, class Compare>
typename priority_queue<T, Container, Compare>::const_reference priority_queue<T, Container, Compare>::top() const
{
    return container.front();
}

template <class T, class Container, class Compare>
typename priority_queue<T, Container, Compare>::size_type priority_queue<T, Container, Compare>::size() const
{
    return container.size();
}
template <class T, class Container, class Compare>
bool priority_queue<T, Container, Compare>::empty() const
{
    return container.empty();
}
template <class T, class Container, class Compare>
void priority_queue<T, Container, Compare>::swap(priority_queue &other) noexcept
{
    std::swap(other.container, container);
    std::swap(other.comparator, comparator);
}
template <class T, class Container, class Compare>
void priority_queue<T, Container, Compare>::heapify_down(size_t index)
{
    size_t i = index * 2 + 1;
    size_t j = index * 2 + 2;
    size_t largest = index;
    size_t size = container.size();
    if (i < size && comparator(container[i], container[largest]))
    {
        largest = i;
    }

    if (j < size && comparator(container[j], container[largest]))
    {
        largest = j;
    }

    if (largest != index)
    {
        std::swap(container[largest], container[index]);
        heapify_down(largest);
    }
}

template <class T, class Container, class Compare>
void priority_queue<T, Container, Compare>::heapify_up(size_t index)
{
    if (index == 0)
        return;
    size_t parent = (index - 1) / 2;

    if (comparator(container[index], container[parent]))
    {
        std::swap(container[index], container[parent]);
        heapify_up(parent);
    }
}

template<class T, class Container, class Compare>
typename Container::iterator priority_queue<T, Container, Compare>::begin() {
    return container.begin();
}

template<class T, class Container, class Compare>
typename Container::iterator priority_queue<T, Container, Compare>::end() {
    return container.end();
}

template<class T, class Container, class Compare>
typename Container::const_iterator priority_queue<T, Container, Compare>::begin() const {
    return container.begin();
}

template<class T, class Container, class Compare>
typename Container::const_iterator priority_queue<T, Container, Compare>::end() const {
    return container.end();
}

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
private:
    Container container;
public:
    using container_type = Container;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;

    Queue(); // ++
    Queue(const Queue& other); // ++
    Queue(Queue&& other) noexcept; // ++ 
    Queue(std::initializer_list<value_type> init); // ++
    Queue(typename container_type::iterator first, typename container_type::iterator last); // ++
    ~Queue(); // ++

    Queue& operator=(const Queue& other);
    Queue& operator=(Queue&& other) noexcept;
    Queue& operator=(std::initializer_list<value_type> list);

    void push(const_reference value); // ++
    void push(value_type&& value); // ++
    void pop(); // ++ 
    reference front(); // ++ 
    const_reference front() const; // ++ 
    reference back(); // ++ 
    const_reference back() const; // ++ 
    bool empty() const; // ++ 
    size_type size() const; // ++ 
    void swap(Queue& other) noexcept;
    template <class ... Args>
    void emplace( Args&&... args );

    bool operator==(const Queue<T, Container>& rhs); // ++
    bool operator!=(const Queue<T, Container>& rhs); // ++
    bool operator<(const Queue<T, Container>& rhs); // ++
    bool operator<=(const Queue<T, Container>& rhs); // ++
    bool operator>(const Queue<T, Container>& rhs); // ++
    bool operator>=(const Queue<T, Container>& rhs); // ++
};

#include "queue.tcc"

#endif // QUEUE_HPP
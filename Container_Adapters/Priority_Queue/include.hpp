#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <iostream>
#include <vector>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <algorithm>
#include <functional>
#include <cassert>

template<class T, class Container = std::vector<T>,  class Compare = std::less<typename Container::value_type>>
class priority_queue {
private:
    Container container;
    Compare comparator;
    void heapify_up(size_t index);
    void heapify_down(size_t index);

public:
    using container_type = Container;
    using value_compare = Compare;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;

    using iterator = typename Container::iterator;
    using const_iterator = typename Container::const_iterator;

public:
    priority_queue();
    priority_queue( const priority_queue& other );
    priority_queue( priority_queue&& other );
    priority_queue& operator=( const priority_queue& other );
    priority_queue& operator=( priority_queue&& other );
    ~priority_queue();
public:
    void push( const value_type& value );
    void push( value_type&& value );
    void pop();
    const_reference top() const;
    size_type size() const;
    bool empty() const;
    void swap(priority_queue& other ) noexcept;


    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

#include "impl.tcc"
#endif // PRIORITY_QUEUE
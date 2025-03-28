#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class Stack
{
private:
    Container container;

public:
    using container_type = Container;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;

    Stack(); // ++
    Stack(const Stack &other); // ++
    Stack(Stack &&other) noexcept; // ++
    Stack(std::initializer_list<value_type> init); // ++ 
    Stack(typename container_type::iterator first, typename container_type::iterator last); // ++
    ~Stack(); //++ 


    Stack &operator=(const Stack &other);                     //++
    Stack &operator=(Stack &&other) noexcept;                 //++
    Stack &operator=(std::initializer_list<value_type> list); //++

    void push(const_reference value); // ++
    void push(value_type&& value); // ++
    void pop(); // ++ 
    reference top();
    const_reference top() const;
    bool empty() const;
    size_type size() const;
    void swap(Stack &other) noexcept;
    
    template< class... Args >
    void emplace( Args&&... args );

    bool operator==(const Stack<T, Container> &rhs);
    bool operator!=(const Stack<T, Container> &rhs);
    bool operator<(const Stack<T, Container> &rhs);
    bool operator<=(const Stack<T, Container> &rhs);
    bool operator>(const Stack<T, Container> &rhs);
    bool operator>=(const Stack<T, Container> &rhs);
};

#include "stack.tcc"

#endif // STACK_HPP
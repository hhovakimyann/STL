#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>        
#include <initializer_list>
#include <stdexcept>      
#include <algorithm>    
#include <iostream>  
#include <limits>
#include <cassert>

template <typename T>
class List
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

private:
    struct Node
    {
        value_type data;
        Node* next;

        Node(const_reference obj) : data(obj), next(nullptr) {}
    };

    Node* m_head;
    size_type m_size;

public:
    class const_iterator {
    protected:
        Node* current;
    public:  
        const_iterator();
        const_iterator(Node* node);
        const_iterator& operator=(const const_iterator& other);

        reference operator*();
        pointer operator->() ;

        const_iterator& operator++();
        const_iterator operator++(int);
        bool operator==(const const_iterator& other) const;
        bool operator!=(const const_iterator& other) const;
    };

    class iterator : public const_iterator {
    public:  
        iterator();
        iterator(Node* node);
        iterator& operator=(const iterator& other);

        reference operator*();
        pointer operator->() ;

        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
    };

    // Constructors and Destructor
    List() : m_head(nullptr), m_size(0) {}
    List(const std::initializer_list<value_type>& init);
    List(const List& other);
    List(List&& other) noexcept;
    ~List();

    // Assignment Operators
    List& operator=(const List& other);
    List& operator=(List&& other) noexcept;

    // Element Access
    reference operator[](size_type index);
    const_reference operator[](size_type index) const;
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    // Capacity
    bool empty() const;
    size_type size() const;

    // Modifiers
    void push_front(const_reference value);
    void pop_front();
    void push_back(const_reference value);
    void pop_back();
    void erase(size_type pos);
    void insert(size_type position, const_reference value);
    void clear() noexcept;
    void assign(size_type count, const_reference value);
    void assign(const std::initializer_list<value_type>& ilist);
    void reverse();
    void swap(List& other) noexcept;
    void remove(const_reference value);
    void remove_if(bool (*predicate)(reference));

    // Lookup
    bool find(const_reference value) const;

    // Display
    void print() const;

    // Iterators
    const_iterator begin()  { return const_iterator(m_head); }
    const_iterator end() { return const_iterator(nullptr); }
    const_iterator cbegin() const  { return const_iterator(m_head); }
    const_iterator cend() const{ return const_iterator(nullptr); }
    
    iterator begin()  { return iterator(m_head); }
    iterator end() { return iterator(nullptr); }
    iterator begin()  const { return iterator(m_head); }
    iterator end() const { return iterator(nullptr); }
};

#include "list.tcc"

#endif // List_HPP
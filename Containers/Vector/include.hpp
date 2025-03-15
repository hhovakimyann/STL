#ifndef VECTOR_H
#define VECTOR_H

#include <iterator>
#include <cstddef>        
#include <initializer_list>
#include <stdexcept>      
#include <algorithm>    
#include <iostream>  
#include <limits>

namespace my_std {

template<typename T>

class Vector {
public:
    // Member Types
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using reference_refer = reference&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;


    // Iterators class forward declaration
    class iterator; // ++
    class const_iterator; // ++
    class reverse_iterator;
    class const_reverse_iterator;

    // Constructors and Destructor

    Vector(); // ++
    explicit Vector(size_type count); //++
    Vector(size_type count, const_reference value); //++
    Vector(std::initializer_list<value_type> init); //++
    Vector(const Vector& other); //++
    Vector(Vector&& other) noexcept; //++
    ~Vector(); //++

    // Assignment Operators
    Vector& operator=(const Vector& other); //++
    Vector& operator=(Vector&& other) noexcept; //++
    Vector& operator=(std::initializer_list<value_type> list); //++

    // Element Access
    reference at(size_type pos); //++
    const_reference at(size_type pos) const; //++

    reference operator[](size_type pos); //++
    const_reference operator[](size_type pos) const; //++

    reference front(); //++
    const_reference front() const; //++

    reference back(); //++
    const_reference back() const; //++

    pointer data() noexcept; // ++
    const_pointer data() const noexcept; //++

    // Iterators

    iterator begin() noexcept; //++
    const_iterator begin() const noexcept; //++
    const_iterator cbegin() const noexcept; // ++


    iterator end() noexcept; //++
    const_iterator end() const noexcept; //++
    const_iterator cend() const noexcept; //++

    reverse_iterator rbegin() noexcept; 
    const_reverse_iterator rbegin() const noexcept; 
    const_reverse_iterator crbegin() const noexcept; 

    reverse_iterator rend() noexcept; 
    const_reverse_iterator rend() const noexcept; 
    const_reverse_iterator crend() const noexcept; 

    // Capacity
    bool empty() const noexcept; // ++
    size_type size() const noexcept; // ++
    size_type capacity() const noexcept; // ++
    std::size_t max_size()  noexcept; // ++
    void reserve(size_type new_cap); // ++ 
    void shrink_to_fit(); // ++

    // Modifiers
    void clear() noexcept; //++
    void push_back(const_reference value); //++
    void push_back(reference_refer value); //++
    void pop_back(); //++
    void resize(size_type count); //++
    void resize(size_type count, const_reference value); //++
    void swap(Vector& other) noexcept; //++
    void insert(size_type pos, const_reference value); //++
    void insert(size_type pos, reference_refer value); //++
    void insert(size_type pos, size_type count,const_reference value); //++
    void insert(size_type pos, std::initializer_list<value_type> ilist); //++
    void erase(size_type pos); //++
    void erase(size_type first, size_type last); //++
    
    // Equality operators
    bool operator==(const Vector& other) const; // ++
    bool operator!=(const Vector& other) const;  // ++

    // Relational operators
    bool operator<(const Vector& other) const; // ++
    bool operator>(const Vector& other) const; // ++
    bool operator<=(const Vector& other) const; // ++
    bool operator>=(const Vector& other) const; // ++

    // Addition operator (vector concatenation)
    Vector operator+(const Vector& other) const; //++

    // Addition assignment operator
    Vector& operator+=(const Vector& other); //++

    // Operator cast to bool
    explicit operator bool() const noexcept; //++

    // Friend Functions

    friend void swap(Vector& lhs, Vector& rhs) noexcept {
        lhs.swap(rhs);
    } //++

private:
    // Private Member Variables

    pointer m_data;        // Pointer to the dynamic array
    size_type m_size;      // Number of elements
    size_type m_capacity;  // Allocated capacity

    // Private Member Functions

    void reallocate(size_type new_capacity); //++
    // void destroy_elements();
    // void copy_from(const Vector& other);
    // void move_from(Vector&& other) noexcept;
};



template <class T>
class Vector<T>::iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    iterator() : current(nullptr) {}
    iterator(pointer ptr) : current(ptr) {}

    const_reference operator*() const { return *current;}
    const_pointer operator->()  const{return current;}

    reference operator*()  { return *current;}
    pointer operator->()  {return current;}

    iterator& operator++() { current++; return *this;}
    iterator& operator--() { current--; return *this;}

    iterator operator++(int) { iterator tmp(*this); current++; return tmp; }
    iterator operator--(int) { iterator tmp(*this);current--; return tmp; }

    iterator& operator+=(difference_type offset) {current += offset; return *this;}
    iterator& operator-=(difference_type offset) {current -= offset; return *this;}

    iterator operator-(difference_type offset) {return iterator(current - offset);}
    iterator operator+(difference_type offset) {return iterator(current + offset);}

    reference operator[](difference_type offset) {return *(current + offset);}

    bool operator==(const iterator& other) const{return other.current == current;}
    bool operator!=(const iterator& other) const{return other.current != current;}
    bool operator>(const iterator& other)const { return current > other.current; }
    bool operator<(const iterator& other) const{return other.current < current;}
    bool operator<=(const iterator& other) const{return other.current <= current;}
    bool operator>=(const iterator& other) const {return other.current >= current;}

private:
    pointer current;
};

template <class T>
class Vector<T>::const_iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    const_iterator() : current(nullptr) {}
    const_iterator(pointer ptr) : current(ptr) {}

    const_reference operator*() const { return *current;}
    const_pointer operator->()  const{ return current;}

    // reference operator*()  { return *current};
    // pointer operator->()  {return current};

    const_iterator& operator++() { current++; return *this;}
    const_iterator& operator--() { current--; return *this;}

    const_iterator operator++(int) { const_iterator tmp(*this);current++; return tmp;}
    const_iterator operator--(int) { const_iterator tmp(*this);current--; return tmp;}

    const_iterator& operator+=(difference_type offset) {current += offset; return *this;}
    const_iterator& operator-=(difference_type offset) {current -= offset; return *this;}

    const_iterator operator-(difference_type offset) {return const_iterator(current - offset);}
    const_iterator operator+(difference_type offset) {return const_iterator(current + offset);}

    reference operator[](difference_type offset) {return *(current + offset);}

    bool operator==(const const_iterator& other) const {return other.current == current;}
    bool operator!=(const const_iterator& other) const {return other.current != current;}
    bool operator>(const const_iterator& other) const {return other.current > current;}
    bool operator<(const const_iterator& other) const {return other.current < current;}
    bool operator<=(const const_iterator& other) const {return other.current <= current;}
    bool operator>=(const const_iterator& other) const {return other.current >= current;}

private:
    pointer current;
};



template<typename T>
class Vector<T>::reverse_iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    reverse_iterator(pointer ptr = nullptr) : m_ptr(ptr) {}

    const_reference operator*() const { return *m_ptr; }
    reference operator*() { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    const_pointer operator->() const { return m_ptr; }

    reverse_iterator& operator++() { --m_ptr; return *this; }
    reverse_iterator operator++(int) { reverse_iterator temp = *this; --(*this); return temp; }

    reverse_iterator& operator--() { ++m_ptr; return *this; }
    reverse_iterator operator--(int) { reverse_iterator temp = *this; ++(*this); return temp; }

    reverse_iterator operator+(difference_type n) const { return reverse_iterator(m_ptr - n); }
    reverse_iterator operator-(difference_type n) const { return reverse_iterator(m_ptr + n); }

    difference_type operator-(const reverse_iterator& other) const { return other.m_ptr - m_ptr; }

    reverse_iterator& operator+=(difference_type n) { m_ptr -= n; return *this; }
    reverse_iterator& operator-=(difference_type n) { m_ptr += n; return *this; }

    reference operator[](difference_type n) const { return *(m_ptr - n); }

    bool operator==(const reverse_iterator& other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const reverse_iterator& other) const { return m_ptr != other.m_ptr; }
    bool operator<(const reverse_iterator& other) const { return m_ptr > other.m_ptr; }
    bool operator>(const reverse_iterator& other) const { return m_ptr < other.m_ptr; }
    bool operator<=(const reverse_iterator& other) const { return m_ptr >= other.m_ptr; }
    bool operator>=(const reverse_iterator& other) const { return m_ptr <= other.m_ptr; }

private:
    pointer m_ptr;
};

template<typename T>
class Vector<T>::const_reverse_iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    const_reverse_iterator(pointer ptr = nullptr) : m_ptr(ptr) {}

    const_reference operator*() const { return *m_ptr; }
    const_pointer operator->() const { return m_ptr; }

    const_reverse_iterator& operator++() { --m_ptr; return *this; }
    const_reverse_iterator operator++(int) { const_reverse_iterator temp = *this; --(*this); return temp; }

    const_reverse_iterator& operator--() { ++m_ptr; return *this; }
    const_reverse_iterator operator--(int) { const_reverse_iterator temp = *this; ++(*this); return temp; }

    const_reverse_iterator operator+(difference_type n) const { return const_reverse_iterator(m_ptr - n); }
    const_reverse_iterator operator-(difference_type n) const { return const_reverse_iterator(m_ptr + n); }

    difference_type operator-(const const_reverse_iterator& other) const { return other.m_ptr - m_ptr; }

    const_reverse_iterator& operator+=(difference_type n) { m_ptr -= n; return *this; }
    const_reverse_iterator& operator-=(difference_type n) { m_ptr += n; return *this; }

    reference operator[](difference_type n) const { return *(m_ptr - n); }

    bool operator==(const const_reverse_iterator& other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const const_reverse_iterator& other) const { return m_ptr != other.m_ptr; }
    bool operator<(const const_reverse_iterator& other) const { return m_ptr > other.m_ptr; }
    bool operator>(const const_reverse_iterator& other) const { return m_ptr < other.m_ptr; }
    bool operator<=(const const_reverse_iterator& other) const { return m_ptr >= other.m_ptr; }
    bool operator>=(const const_reverse_iterator& other) const { return m_ptr <= other.m_ptr; }

private:
    pointer m_ptr;
};

} // namespace my_std

#include "vector.tcc"

#endif // VECTOR_H
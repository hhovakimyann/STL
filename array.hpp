#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <iterator>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>

template <class T, std::size_t N>
class Array {
private:
    T elements[N];
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using iterator_category = std::random_access_iterator_tag;

    class iterator;
    class const_iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
   
    constexpr Array() : elements{} {}
    constexpr Array(std::initializer_list<T> list);
    constexpr Array(const Array& other);
    constexpr Array(Array&& other) noexcept;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    const_reference at(size_type pos) const;
    reference at(size_type pos); 

    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;
   
    reference front();
    const_reference front() const;

    reference back();
    const_reference back() const;

    pointer data() noexcept;
    const_pointer data() const noexcept;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;

    iterator end() noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;

    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator crbegin() const noexcept;

    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;

    constexpr bool empty() const noexcept;
    constexpr size_type size() const noexcept;
    constexpr size_type max_size() const noexcept;

    void fill(const T& value);
    void swap(Array& other) noexcept;

    bool operator==(const Array<T, N>& rhs) const;
    bool operator!=(const Array<T, N>& rhs) const;
    bool operator<(const Array<T, N>& rhs) const;
    bool operator>(const Array<T, N>& rhs) const;
    bool operator>=(const Array<T, N>& rhs) const;
    bool operator<=(const Array<T, N>& rhs) const;
};
#include <iterator>

template<class T, std::size_t N>
class Array<T, N>::iterator {
private:
    pointer current;
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using reference = T&;

    iterator() : current(nullptr) {}
    explicit iterator(pointer ptr) : current(ptr) {}

    reference operator*() const { return *current; }
    pointer operator->() const { return current; }

    iterator& operator++() { ++current; return *this; }
    iterator operator++(int) { iterator tmp = *this; ++current; return tmp; }
    iterator& operator--() { --current; return *this; }
    iterator operator--(int) { iterator tmp = *this; --current; return tmp; }

    iterator& operator+=(difference_type distance) { current += distance; return *this; }
    iterator& operator-=(difference_type distance) { current -= distance; return *this; }
    iterator operator+(difference_type distance) const { return iterator(current + distance); }
    iterator operator-(difference_type distance) const { return iterator(current - distance); }
    difference_type operator-(const iterator& other) const { return current - other.current; }

    reference operator[](difference_type distance) { return current[distance]; }

    bool operator==(const iterator& other) const { return current == other.current; }
    bool operator!=(const iterator& other) const { return current != other.current; }
    bool operator<(const iterator& other) const { return current < other.current; }
    bool operator>(const iterator& other) const { return current > other.current; }
    bool operator<=(const iterator& other) const { return current <= other.current; }
    bool operator>=(const iterator& other) const { return current >= other.current; }

    friend iterator operator+(difference_type distance, const iterator& it) {
        return iterator(it.current + distance);
    }
};

template<class T, std::size_t N>
class Array<T, N>::const_iterator {
private:
    const_pointer current;
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    const_iterator() : current(nullptr) {}
    explicit const_iterator(const_pointer ptr) : current(ptr) {}

    const_iterator(const iterator& it) : current(it.current) {}  // Allow conversion

    reference operator*() const { return *current; }
    pointer operator->() const { return current; }

    const_iterator& operator++() { ++current; return *this; }
    const_iterator operator++(int) { const_iterator tmp = *this; ++current; return tmp; }
    const_iterator& operator--() { --current; return *this; }
    const_iterator operator--(int) { const_iterator tmp = *this; --current; return tmp; }

    const_iterator& operator+=(difference_type distance) { current += distance; return *this; }
    const_iterator& operator-=(difference_type distance) { current -= distance; return *this; }
    const_iterator operator+(difference_type distance) const { return const_iterator(current + distance); }
    const_iterator operator-(difference_type distance) const { return const_iterator(current - distance); }
    difference_type operator-(const const_iterator& other) const { return current - other.current; }

    reference operator[](difference_type distance) const { return current[distance]; }

    bool operator==(const const_iterator& other) const { return current == other.current; }
    bool operator!=(const const_iterator& other) const { return current != other.current; }
    bool operator<(const const_iterator& other) const { return current < other.current; }
    bool operator>(const const_iterator& other) const { return current > other.current; }
    bool operator<=(const const_iterator& other) const { return current <= other.current; }
    bool operator>=(const const_iterator& other) const { return current >= other.current; }

    friend const_iterator operator+(difference_type distance, const const_iterator& it) {
        return const_iterator(it.current + distance);
    }
};

#include "array.tcc"

#endif // ARRAY_HPP
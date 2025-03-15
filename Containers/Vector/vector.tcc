#include "include.hpp"


namespace my_std {
template<typename T>
void Vector<T>::reallocate(size_type new_capacity) {
    pointer new_data = new value_type[new_capacity];    
    for(size_t i = 0; i < m_size; i++) {
        new_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;
}


/*--------------------------Constructors-------------------------------*/
template<typename T>
Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0) {} // defout constructor

template<typename T>
Vector<T>::Vector(size_type count) : m_data(new value_type[count]), m_size(count), m_capacity(count) {} // take memory for count

template<typename T>
Vector<T>::Vector(size_type count, const_reference value) : m_data(new value_type[count]), m_size(count), m_capacity(count) { // take memory for count and initialize with value
    for(size_t i = 0; i < m_size; i++) {
        m_data[i] = value;
    }
} 

template<typename T>
Vector<T>::Vector(std::initializer_list<value_type> init) : m_data(new value_type[init.size()]), m_size(init.size()), m_capacity(init.size()) { // take memory with list size and initialize it with list values
    size_type index = 0;
    for (auto ptr = init.begin(); ptr != init.end(); ++ptr) {
        m_data[index++] = *ptr;
    }
}

template<typename T>
Vector<T>::Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity) { // copy constructor deep copy
    m_data = new value_type[m_capacity];
    for(size_t i = 0 ; i < m_size; i++) {
        m_data[i] = other.m_data[i];
    }
} 

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept { // move constructor 
    m_data = other.m_data;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    other.m_data = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

template<typename T>
Vector<T>::~Vector() {  // destructor
    if(m_data) {
        delete [] m_data;
    }
} 

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) { // copy assignment
    if(this != &other) {
        delete [] m_data;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_data = new value_type[m_capacity];
        
        for (size_type i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept { // move assignment
    if (this != &other) {
        delete[] m_data;
        m_data = other.m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }
    return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(std::initializer_list<value_type> list) { // list assignment
    m_size = list.size();
    m_capacity = m_size;
    delete [] m_data;
    m_data = new value_type [m_capacity];
    size_type index = 0;
    for (auto i = list.begin(); i != list.end(); ++i) {
        m_data[index++] = *i;
    }
    return *this;
}


/*------------------------------Position get functions--------------------------------*/
template <typename T>
typename Vector<T>::reference Vector<T>::at(size_type pos) { // give element int that position if invalid position give exertion
    if(pos > m_size) {
        throw std::out_of_range("Invalid Position");
    }
    return m_data[pos];
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin() noexcept {
    return iterator(m_data);
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const noexcept {
    return const_iterator(m_data);
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const noexcept {
    return const_iterator(m_data);
}


template<typename T>
typename Vector<T>::iterator Vector<T>::end() noexcept {
    return iterator(m_data + m_size);
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::end() const noexcept {
    return const_iterator(m_data + m_size);
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const noexcept {
    return const_iterator(m_data + m_size);
}

template<typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin() noexcept {
    return reverse_iterator(end());
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::rbegin() const noexcept {
    return const_reverse_iterator(end());
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const noexcept {
    return const_reverse_iterator(end());
}

template<typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend() noexcept {
    return reverse_iterator(begin());
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::rend() const noexcept {
    return const_reverse_iterator(begin());
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const noexcept {
    return const_reverse_iterator(begin());
}
template <typename T>
typename Vector<T>::const_reference Vector<T>::at(size_type pos) const { // give element int that position if invalid position give exertion using for const objects
    if(pos > m_size) {
        throw std::out_of_range("Invalid Position");
    }
    return m_data[pos];
}
template <typename T>
typename Vector<T>::reference Vector<T>::operator[](size_type pos) { // give element in that position without checking position is valid
    return m_data[pos];
}
template <typename T>
typename Vector<T>::const_reference Vector<T>::operator[](size_type pos) const{ // give element in that position without checking postion in valid use for const objects
    return m_data[pos];
}
template <typename T>
typename Vector<T>::reference Vector<T>::front() { // give the first element
    return m_data[0];
}
template <typename T>
typename Vector<T>::const_reference Vector<T>::front() const { // give the first element for const objects
    return m_data[0];
}
template <typename T>
typename Vector<T>::reference Vector<T>::back() { // give the last element
    return m_data[m_size - 1];
}
template <typename T>
typename Vector<T>::const_reference Vector<T>::back() const { // give the last element for const objects
    return m_data[m_size - 1];
}
template <typename T>
typename Vector<T>::pointer Vector<T>::data() noexcept { // return the data pointer
    return m_data;
}
template <typename T>
typename Vector<T>::const_pointer Vector<T>::data() const noexcept { // return the data pointer for const
    return m_data;
}

/*--------------------------------------Capacity--------------------------------*/
template <typename T>
bool Vector<T>::empty() const noexcept { // check is empty Vector<T>
    return m_size == 0;
}
template <typename T>

typename Vector<T>::size_type Vector<T>::size() const noexcept { // give the Vector<T> size;
    return m_size;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::capacity() const noexcept { // give the Vector<T> capacity
    return m_capacity;
}

template <typename T>
void Vector<T>::reserve(size_type new_cap) {
    if (new_cap > m_capacity) {
        reallocate(new_cap);
    }
}   
template <typename T>
void Vector<T>::shrink_to_fit() {
    if (m_capacity > m_size) {
        reallocate(m_size);
    }
}
template <typename T>
std::size_t max_size() noexcept {
    return std::numeric_limits<std::size_t>::max() / sizeof(std::size_t);
}


/*------------------------------------------Modifiers----------------------------------*/
template <typename T>
void Vector<T>::clear() noexcept{
    for(size_t i = 0; i < m_size; i++) {
        m_data[i].~value_type();
    }
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
void Vector<T>::push_back(const_reference value){ // add element at end of Vector<T>
    if(m_size == m_capacity) {
        reallocate(m_capacity ? m_capacity * 2 : 1);
    }

    m_data[m_size++] = value; 
}
template <typename T>
void Vector<T>::push_back(reference_refer value) { //add temp element at end of vector
    if (m_size >= m_capacity) {
        reserve(m_capacity ? m_capacity * 2 : 1);
    }
    m_data[m_size++] = std::move(value);
}
template <typename T>
void Vector<T>::pop_back() { // remove element at the end
    if (m_size > 0) {
        --m_size;
    }else {
        throw std::out_of_range("No elements");
    }
}
template <typename T>
void Vector<T>::resize(size_type count,const_reference value) { // resize vector and add elements with value
    if (count > m_size) {
        pointer new_data = new value_type[count];
        for (size_t i = 0; i < m_size; i++) {
            new_data[i] = m_data[i];
        }
        for (size_t i = m_size; i < count; i++) {
            new_data[i] = value;
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = count;
        m_size = count;
    } else {
        m_size = count;
    }
}
template <typename T>
void Vector<T>::resize(size_type count) { // resize vector 
    if(count > m_size) {
        reallocate(count);
    }else {
        m_size = count;
    }
}
template <typename T>
void Vector<T>::swap(Vector& other) noexcept { // swap elements
    std::swap(m_data, other.m_data);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
}
template <typename T>
void Vector<T>::insert(size_type pos, const_reference value) {
    if (pos < 0 || pos > m_size) {
        throw std::out_of_range("Invalid Position");
    }
    if (m_size == m_capacity) {
        reallocate(m_capacity ? m_capacity * 2 : 1);
    }
    for (size_type i = m_size; i > pos; --i) {
        m_data[i] = m_data[i - 1];
    }
    m_data[pos] = value;
    ++m_size;
}
template <typename T>
void Vector<T>::insert(size_type pos, reference_refer value) {
    if (pos < 0|| pos > m_size) {
        throw std::out_of_range("Invalid Position");
    }
    if (m_size == m_capacity) {
        reallocate(m_capacity ? m_capacity * 2 : 1);
    }
    for (size_type i = m_size; i > pos; --i) {
        m_data[i] = m_data[i - 1];
    }
    m_data[pos] = std::move(value);
    ++m_size;
}

template <typename T>
void Vector<T>::insert(size_type pos, size_type count, const_reference value) {
    if(pos > m_size) {
        throw std::out_of_range("Invalid Position");
    }

    if(count <= 0) {
        throw std::invalid_argument("Cant Element Count Be Less 0 Or 0");
    }

    if(m_size + count >= m_capacity) {
        reallocate(m_capacity ? (m_capacity + count) * 2 : 1 + count);
    }

    for (size_type i = m_size; i > pos; --i) {
        m_data[i + count - 1] = m_data[i - 1];
    }

    for (size_type i = 0; i < count; ++i) {
        m_data[pos + i] = value;
    }

    m_size += count;
}

template <typename T>
void Vector<T>::insert(size_type pos, std::initializer_list<value_type> ilist) {
    if(pos < 0 || pos > m_size) {
        throw std::out_of_range("Invalid Position");
    }

    if(m_size + ilist.size() >= m_capacity) {
        reallocarray(m_capacity ? (m_capacity + ilist.size()) * 2: 1 + ilist.size());
    }

    for (size_type i = m_size; i > pos; --i) {
        m_data[i + ilist.size() - 1] = m_data[i - 1];
    }
    size_type index = pos;
    for(auto &val : ilist) {
        m_data[index++] = val;
    } 

    m_size += ilist.size();
}

template <typename T>
void Vector<T>::erase(size_type first, size_type last) {
    if (first >= m_size || last > m_size || first >= last) {
        throw std::out_of_range("Invalid Range");
    }

    size_type count = last - first + 1;
    for (size_type i = first; i < m_size - count; ++i) {
        m_data[i] = std::move(m_data[i + count]);
    }
    m_size -= count;
}
template <typename T>
void Vector<T>::erase(size_type pos) {
    if (pos >= m_size) {
        throw std::out_of_range("Invalid Position");
    }
    for (size_type i = pos; i < m_size - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }
    --m_size;
}


/*----------------------------Equality operators------------------------------------*/
template <typename T>
bool Vector<T>::operator==(const Vector& other) const { // check is vector size and elements equal
    if(m_size == other.m_size) {
        for(size_t i = 0; i < m_size ; i++) {
            if(m_data[i] != other.m_data[i]) {
                return false;
            } 
        }
    }
    return true;
}
template <typename T>
bool Vector<T>::operator!=(const Vector& other) const { // check is vector size and elements not equal 
    return !(*this == other);
}

/*----------------------------------Relational Operators----------------------------------*/
template <typename T>
bool Vector<T>::operator<(const Vector& other) const {
    if (m_size < other.m_size) {
        return true;
    }
    if (m_size > other.m_size) {
        return false;
    }

    for (size_type i = 0; i < m_size; ++i) {
        if (m_data[i] < other.m_data[i]) {
            return true; 
        } else if (m_data[i] > other.m_data[i]) {
            return false;
        }
    }
    return false;
}
 
template <typename T>
bool Vector<T>::operator>(const Vector& other) const {
    return other < *this;
}


template <typename T>
bool Vector<T>::operator>=(const Vector& other) const {
    return other > *this || other == *this;
}

template <typename T>
bool Vector<T>::operator<=(const Vector& other) const {
    return other < *this || other == *this;
}

/*--------------------------------Operator cast to bool-----------------------------------------*/
template <typename T>
Vector<T>::operator bool() const noexcept { // check is vector empty
    return !empty();
}

/*--------------------------------Vector concatenation----------------------------*/
template <typename T>
Vector<T> Vector<T>::operator+(const Vector& other) const { // concat vector size capacity and elements
    Vector result;
    result.reserve(m_size + other.m_size);
    for (size_t i = 0; i < m_size; i++) {
        result.push_back(m_data[i]);
    }
    for (size_t i = 0; i < other.m_size; i++) {
        result.push_back(other.m_data[i]);
    }
    return result;
}

/*-------------------------------Addition assignment operator---------------------------------*/
template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector& other) { //concat vector size capacity and elements and store to this
    *this = std::move(*this + other);
    return *this;
}

}


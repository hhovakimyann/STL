#include "array.hpp"

template <class T, std::size_t N>
constexpr Array<T, N>::Array(std::initializer_list<T> list) {
    std::size_t count = 0;
    for (const T& x : list) {
        if (count < N) elements[count++] = x;
        else break;
    }
}

template <class T, std::size_t N>
constexpr Array<T, N>::Array(const Array& other) {
    for (std::size_t i = 0; i < N; ++i)
        elements[i] = other.elements[i];
}

template <class T, std::size_t N>
constexpr Array<T, N>::Array(Array&& other) noexcept {
    for (std::size_t i = 0; i < N; ++i)
        elements[i] = std::move(other.elements[i]);
}

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::operator=(const Array& other) {
    if (this != &other) {
        for (std::size_t i = 0; i < N; ++i)
            elements[i] = other.elements[i];
    }
    return *this;
}

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::operator=(Array&& other) noexcept {
    if (this != &other) {
        for (std::size_t i = 0; i < N; ++i)
            elements[i] = std::move(other.elements[i]);
    }
    return *this;
}

template <class T, std::size_t N>
typename Array<T, N>::const_reference Array<T, N>::at(size_type pos) const {
    if (pos >= N) throw std::out_of_range("Invalid Position");
    return elements[pos];
}

template <class T, std::size_t N>
typename Array<T, N>::reference Array<T, N>::at(size_type pos) {
    if (pos >= N) throw std::out_of_range("Invalid Position");
    return elements[pos];
}

template <class T, std::size_t N>
typename Array<T, N>::reference Array<T, N>::operator[](size_type pos) {
    return elements[pos];
}

template <class T, std::size_t N>
typename Array<T, N>::const_reference Array<T, N>::operator[](size_type pos) const {
    return elements[pos];
}

template <class T, std::size_t N>
typename Array<T, N>::reference Array<T, N>::front() {
    return elements[0];
}

template <class T, std::size_t N>
typename Array<T, N>::const_reference Array<T, N>::front() const {
    return elements[0];
}

template <class T, std::size_t N>
typename Array<T, N>::reference Array<T, N>::back() {
    return elements[N - 1];
}

template <class T, std::size_t N>
typename Array<T, N>::const_reference Array<T, N>::back() const {
    return elements[N - 1];
}

template <class T, std::size_t N>
typename Array<T, N>::pointer Array<T, N>::data() noexcept {
    return elements;
}

template <class T, std::size_t N>
typename Array<T, N>::const_pointer Array<T, N>::data() const noexcept {
    return elements;
}

template <class T, std::size_t N>
typename Array<T, N>::iterator Array<T, N>::begin() noexcept {
    return iterator(elements);
}

template <class T, std::size_t N>
typename Array<T, N>::const_iterator Array<T, N>::begin() const noexcept {
    return const_iterator(elements);
}

template <class T, std::size_t N>
typename Array<T, N>::const_iterator Array<T, N>::cbegin() const noexcept {
    return const_iterator(elements);
}

template <class T, std::size_t N>
typename Array<T, N>::iterator Array<T, N>::end() noexcept {
    return iterator(elements + N);
}

template <class T, std::size_t N>
typename Array<T, N>::const_iterator Array<T, N>::end() const noexcept {
    return const_iterator(elements + N);
}

template <class T, std::size_t N>
typename Array<T, N>::const_iterator Array<T, N>::cend() const noexcept {
    return const_iterator(elements + N);
}

template <class T, std::size_t N>
typename Array<T, N>::reverse_iterator Array<T, N>::rbegin() noexcept {
    return reverse_iterator(end());
}

template <class T, std::size_t N>
typename Array<T, N>::const_reverse_iterator Array<T, N>::rbegin() const noexcept {
    return const_reverse_iterator(end());
}

template <class T, std::size_t N>
typename Array<T, N>::const_reverse_iterator Array<T, N>::crbegin() const noexcept {
    return const_reverse_iterator(end());
}

template <class T, std::size_t N>
typename Array<T, N>::reverse_iterator Array<T, N>::rend() noexcept {
    return reverse_iterator(begin());
}

template <class T, std::size_t N>
typename Array<T, N>::const_reverse_iterator Array<T, N>::rend() const noexcept {
    return const_reverse_iterator(begin());
}

template <class T, std::size_t N>
typename Array<T, N>::const_reverse_iterator Array<T, N>::crend() const noexcept {
    return const_reverse_iterator(begin());
}

template <class T, std::size_t N>
constexpr bool Array<T, N>::empty() const noexcept {
    return N == 0;
}

template <class T, std::size_t N>
constexpr typename Array<T, N>::size_type Array<T, N>::size() const noexcept {
    return N;
}

template <class T, std::size_t N>
constexpr typename Array<T, N>::size_type Array<T, N>::max_size() const noexcept {
    return N;
}

template <class T, std::size_t N>
void Array<T, N>::fill(const T& value) {
    std::fill_n(elements, N, value);
}

template <class T, std::size_t N>
void Array<T, N>::swap(Array& other) noexcept {
    std::swap_ranges(elements, elements + N, other.elements);
}

template <class T, std::size_t N>
bool Array<T, N>::operator==(const Array<T, N>& rhs) const {
    return std::equal(begin(), end(), rhs.begin());
}

template <class T, std::size_t N>
bool Array<T, N>::operator!=(const Array<T, N>& rhs) const {
    return !(*this == rhs);
}

template <class T, std::size_t N>
bool Array<T, N>::operator<(const Array<T, N>& rhs) const {
    return std::lexicographical_compare(begin(), end(), rhs.begin(), rhs.end());
}

template <class T, std::size_t N>
bool Array<T, N>::operator>(const Array<T, N>& rhs) const {
    return rhs < *this;
}

template <class T, std::size_t N>
bool Array<T, N>::operator<=(const Array<T, N>& rhs) const {
    return !(rhs < *this);
}

template <class T, std::size_t N>
bool Array<T, N>::operator>=(const Array<T, N>& rhs) const {
    return !(*this < rhs);
}
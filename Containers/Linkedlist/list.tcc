#include "include.hpp"

/* Constructors and Destructor */
template <typename T>
List<T>::List(const std::initializer_list<value_type>& init) : m_head(nullptr), m_size(0) {
    for (const auto& value : init) {
        push_back(value);
    }
}
template <typename T>
List<T>::List(const List& obj) : m_head(nullptr), m_size(0) {
    Node* current = obj.m_head;
    while (current) {
        push_back(current->data);
        current = current->next;
    }
}
template <typename T>
List<T>::List(List&& other) noexcept : m_head(other.m_head), m_size(other.m_size) {
    other.m_head = nullptr;
    other.m_size = 0;
}
template <typename T>
List<T>::~List() {
    clear();
}

/* Assignment Operators */
template <typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other) {
        clear();
        Node* current = other.m_head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}
template <typename T>
List<T>& List<T>::operator=(List&& other) noexcept {
    if (this != &other) {
        clear();
        m_head = other.m_head;
        m_size = other.m_size;
        other.m_head = nullptr;
        other.m_size = 0;
    }
    return *this;
}

/* Element Access */
template <typename T>
typename List<T>::reference List<T>::operator[](size_type index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    Node* temp = m_head;
    for (size_type i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->data;
}
template <typename T>
typename List<T>::const_reference List<T>::operator[](size_type index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    Node* temp = m_head;
    for (size_type i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->data;
}
template <typename T>
typename List<T>::reference List<T>::front() {
    if (m_head == nullptr) {
        throw std::out_of_range("No element in the list");
    }
    return m_head->data;
}
template <typename T>
typename List<T>::const_reference List<T>::front() const {
    if (m_head == nullptr) {
        throw std::out_of_range("No element in the list");
    }
    return m_head->data;
}
template <typename T>
typename List<T>::reference List<T>::back() {
    if (m_head == nullptr) {
        throw std::out_of_range("No element in the list");
    }
    Node* temp = m_head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp->data;
}

template <typename T>
typename List<T>::const_reference List<T>::back() const {
    if (m_head == nullptr) {
        throw std::out_of_range("No element in the list");
    }
    Node* temp = m_head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp->data;
}

/* Capacity */
template <typename T>
bool List<T>::empty() const {
    return m_size == 0;
}

template <typename T>
typename List<T>::size_type List<T>::size() const {
    return m_size;
}

/* Modifiers */
template <typename T>
void List<T>::push_front(const_reference value) {
    Node* new_node = new Node(value);
    new_node->next = m_head;
    m_head = new_node;
    ++m_size;
}

template <typename T>
void List<T>::push_back(const_reference value) {
    Node* new_node = new Node(value);
    if (m_head == nullptr) {
        m_head = new_node;
    } else {
        Node* temp = m_head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    ++m_size;
}

template <typename T>
void List<T>::pop_front() {
    if (m_head == nullptr) return;
    Node* temp = m_head;
    m_head = m_head->next;
    delete temp;
    --m_size;
}

template <typename T>
void List<T>::pop_back() {
    if (m_head == nullptr) return;
    if (m_head->next == nullptr) {
        delete m_head;
        m_head = nullptr;
    } else {
        Node* temp = m_head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    --m_size;
}

template <typename T>
void List<T>::erase(size_type pos) {
    if (pos >= m_size) {
        throw std::out_of_range("Invalid position");
    }
    if (pos == 0) {
        pop_front();
        return;
    }
    Node* current = m_head;
    for (size_type i = 1; i < pos; ++i) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    --m_size;
}

template <typename T>
void List<T>::insert(size_type position, const_reference value) {
    if (position > m_size) {
        throw std::out_of_range("Invalid position");
    }
    if (position == 0) {
        push_front(value);
        return;
    }
    Node* current = m_head;
    for (size_type i = 1; i < position; ++i) {
        current = current->next;
    }
    Node* new_node = new Node(value);
    new_node->next = current->next;
    current->next = new_node;
    ++m_size;
}
template <typename T>
void List<T>::clear() noexcept {
    while (m_head) {
        pop_front();
    }
}

template <typename T>
void List<T>::assign(size_type count, const_reference value) {
    clear();
    while (count--) {
        push_back(value);
    }
}
template <typename T>
void List<T>::assign(const std::initializer_list<value_type>& ilist) {
    clear();
    for (const auto& value : ilist) {
        push_back(value);
    }
}
template <typename T>
void List<T>::reverse() {
    Node* prev = nullptr;
    Node* current = m_head;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    m_head = prev;
}
template <typename T>
void List<T>::swap(List& other) noexcept {
    std::swap(m_head, other.m_head);
    std::swap(m_size, other.m_size);
}
template <typename T>
void List<T>::remove(const_reference value) {
    while (m_head && m_head->data == value) {
        pop_front();
    }
    Node* current = m_head;
    while (current && current->next) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            --m_size;
        } else {
            current = current->next;
        }
    }
}

template <typename T>
bool List<T>::find(const_reference value) const {
    Node* current = m_head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}
template <typename T>
void List<T>::print() const {
    Node* current = m_head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}




//----------------------- Const Iterator ----------------------------//
template <class T>
List<T>::const_iterator::const_iterator() : current(nullptr) {}

template <class T>
List<T>::const_iterator::const_iterator(Node * node) : current(node) {}

template <class T>
typename List<T>::const_iterator& List<T>::const_iterator::operator=(const const_iterator& other) {
    current = other->current;
}

template <class T>
typename List<T>::reference List<T>::const_iterator::operator*() {
    return current->data;
}

template <class T>
typename List<T>::pointer List<T>::const_iterator::operator->() {
    return &(current->data);
}

template <class T>
typename List<T>::const_iterator::const_iterator& List<T>::const_iterator::operator++() {
    if(current) {
        current = current->next;
    }
    return *this;
}

template <class T>
typename List<T>::const_iterator::const_iterator List<T>::const_iterator::operator++(int) {
    const_iterator tmp = current;
    if(current) {
        current = current->next;
    }
    return tmp;
}

template <class T>
bool List<T>::const_iterator::operator==(const const_iterator& other) const {
    return current == other.current;
}

template <class T>
bool List<T>::const_iterator::operator!=(const const_iterator& other) const {
    return current != other.current;
}


//----------------------- Iterator ----------------------------//
template <class T>
List<T>::iterator::iterator() : current(nullptr) {}

template <class T>
List<T>::iterator::iterator(Node * node) : current(node) {}

template <class T>
typename List<T>::iterator& List<T>::iterator::operator=(const iterator& other) {
    current = other->current;
}

template <class T>
typename List<T>::reference List<T>::iterator::operator*() {
    return current->data;
}

template <class T>
typename List<T>::pointer List<T>::iterator::operator->() {
    return &(current->data);
}

template <class T>
typename List<T>::iterator::iterator& List<T>::iterator::operator++() {
    if(current) {
        current = current->next;
    }
    return *this;
}

template <class T>
typename List<T>::iterator::iterator List<T>::iterator::operator++(int) {
    iterator tmp = current;
    if(current) {
        current = current->next;
    }
    return tmp;
}

template <class T>
bool List<T>::iterator::operator==(const iterator& other) const {
    return current == other.current;
}

template <class T>
bool List<T>::iterator::operator!=(const iterator& other) const {
    return current != other.current;
}
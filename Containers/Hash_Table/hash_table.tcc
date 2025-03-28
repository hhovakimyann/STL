#include "include.hpp"

template <class Key, class T, class Hash>
unordered_map<Key, T, Hash>::unordered_map(float max_load_factor, size_type bucket_count)
    : max_load_factor(max_load_factor), bucket_count(bucket_count), element_count(0), tables(bucket_count){};

template <class Key, class T, class Hash>
template <class InputIt>
unordered_map<Key, T, Hash>::unordered_map(InputIt first, InputIt last, size_type bucket_count, float max_load_factor) : max_load_factor(max_load_factor), bucket_count(bucket_count), element_count(0), tables(bucket_count)
{

    for (auto it = first; it != last; ++it)
    {
        insert(*it);
    }
}

template <class Key, class T, class Hash>
unordered_map<Key, T, Hash>::unordered_map(std::initializer_list<value_type> init, size_type bucket_count, float max_load_factor) : max_load_factor(max_load_factor), bucket_count(bucket_count), element_count(0), tables(bucket_count)
{
    for (const auto &x : init)
    {
        insert(x.first,x.second);
    }
}

template <class Key, class T, class Hash>
unordered_map<Key, T, Hash>::unordered_map(const unordered_map &other)
    : max_load_factor(other.max_load_factor),
      bucket_count(other.bucket_count),
      element_count(other.element_count),
      tables(other.bucket_count)
{
   
    for (size_type i = 0; i < bucket_count; ++i) {
        tables[i] = other.tables[i]; 
    }
}
template <class Key, class T, class Hash>
unordered_map<Key, T, Hash> &unordered_map<Key, T, Hash>::operator=(const unordered_map &other)
{
    tables.clear();
    if (this != &other)
    {
        max_load_factor = other.max_load_factor;
        bucket_count = other.bucket_count;
        element_count = other.element_count;
        tables = other.tables;
    }
    return *this;
}
template <class Key, class T, class Hash>
unordered_map<Key, T, Hash>::unordered_map(unordered_map &&other) :
    max_load_factor(other.max_load_factor),
    bucket_count(other.bucket_count),
    element_count(other.element_count),
    tables(std::move(other.tables))
{

    other.max_load_factor = 0;
    other.bucket_count = 0;
    other.element_count = 0;
}
template <class Key, class T, class Hash>
unordered_map<Key,T,Hash>& unordered_map<Key, T, Hash>::operator=(unordered_map && other) {
    if(this != &other) {
        element_count = other.element_count;
        max_load_factor = other.max_load_factor;
        bucket_count = other.bucket_count;
        other.element_count = 0;
        other.max_load_factor = 0;
        other.bucket_count = 0;
        tables = std::move(other.tables);
        
    }
    return *this;
}

template<class Key, class T, class Hash>
unordered_map<Key,T,Hash>::~unordered_map() {
    clear();
}



template <class Key, class T, class Hash>
typename unordered_map<Key,T,Hash>::size_type unordered_map<Key,T,Hash>::size() const noexcept {
    return element_count;
}

template <class Key, class T, class Hash>
bool unordered_map<Key,T,Hash>::empty() const noexcept {
    return element_count == 0;
}


template <class Key, class T, class Hash>
typename unordered_map<Key,T,Hash>::size_type unordered_map<Key,T,Hash>::max_size() const noexcept {
    return std::numeric_limits<std::size_t>::max();
}




template <class Key, class T, class Hash>
typename unordered_map<Key,T,Hash>::hasher unordered_map<Key,T,Hash>::hash_function() const {
    return hasher(); 
}

template <class Key, class T, class Hash>
typename unordered_map<Key,T,Hash>::size_type unordered_map<Key,T,Hash>::load_factor() const {
    return static_cast<float>(element_count) / bucket_count;
}

template<class Key, class T, class Hash>
float unordered_map<Key, T, Hash>::max_load_factors() const {
    return static_cast<float>(max_load_factor);  
}


template<class Key, class T, class Hash>
void unordered_map<Key, T, Hash>::max_load_factors(float ml) {
    if (ml <= 0.0f) {
        throw std::invalid_argument("max_load_factor must be greater than 0.");
    }
    max_load_factor = ml;
}


template <class Key, class T, class Hash>
void unordered_map<Key,T,Hash>::insert(const Key& key, const T& value) {
    if(max_load_factor < load_factor()) {
        rehash(nextPrime(bucket_count));
    }

    int index = hash_function()(key) % bucket_count;
    std::forward_list<value_type> & list = tables[index];

    auto it = std::find_if(list.begin(), list.end(), [&key](const auto& pair) {return pair.first == key;});

    if(it == list.end()) {
        list.push_front(std::make_pair(key,value));
        element_count++;
    }
}
template <class Key, class T, class Hash>
void unordered_map<Key,T,Hash>::insert(std::initializer_list<value_type> ilist) {
    for (const auto& x : ilist) {
        size_type index = hash_function()(x.first) % bucket_count;
        std::forward_list<value_type>& list = tables[index];

        auto it = std::find_if(list.begin(), list.end(), [&x](const value_type& pair) {
            return pair.first == x.first;
        });

        if (it == list.end()) {
            list.push_front(x);
            ++element_count;  
        }
    }
}
template <class Key,class T, class Hash>
void unordered_map<Key,T,Hash>::rehash(size_type new_bucket_count) {
    Table newtable(new_bucket_count);
    
    for(const auto& table : tables) {
        for (auto& pair : table) {
            size_t new_index = hash_function()(pair.first) % new_bucket_count;
            newtable[new_index].push_front(std::move(pair));
        }
    }
    tables.swap(newtable);
}



template <class Key, class T, class Hash>
typename unordered_map<Key, T, Hash>::size_type unordered_map<Key, T, Hash>::erase(const Key& key) {
    int index = hash_function()(key) % bucket_count;
    std::forward_list<value_type>& list = tables[index];

    auto prev = list.before_begin(); 
    auto it = list.begin();

    while (it != list.end()) {
        if (it->first == key) {
            list.erase_after(prev);
            element_count--;
            return 1;
        }
        prev = it;
        ++it;
    }
    return 0;
}


template <class Key, class T, class Hash>
void unordered_map<Key,T,Hash>::clear() noexcept {
    for (size_type i = 0; i < bucket_count; ++i) {
        tables[i].clear();
    }
    element_count = 0;
}



template <class Key, class T, class Hash>
void unordered_map<Key,T,Hash>::swap(unordered_map& other) noexcept {
    std::swap(other.tables,tables);
    std::swap(other.max_load_factor,max_load_factor);
    std::swap(other.bucket_count,bucket_count);
    std::swap(element_count,other.element_count);
}



template<class Key,class T, class Hash>
T& unordered_map<Key,T,Hash>::at(const Key& key){
    int index = hash_function()(key) % bucket_count;
    std::forward_list<value_type>& list = tables[index];

   auto it = std::find_if(list.begin(), list.end(),[&key](const value_type& pair){return pair.first == key;});


    if(it != list.end()) {
        return it->second;
    }

    throw std::invalid_argument("Invalid Key");
}


template<class Key,class T, class Hash>
const T& unordered_map<Key,T,Hash>::at(const Key& key) const {
    int index = hash_function()(key) % bucket_count;
    const std::forward_list<value_type>& list = tables[index];

   auto it = std::find_if(list.begin(), list.end(),[&key](const value_type& pair){return pair.first == key;});


    if(it != list.end()) {
        return it->second;
    }

    throw std::invalid_argument("Invalid Key");
}


template <class Key, class T, class Hash>
T& unordered_map<Key,T,Hash>::operator[](const Key& key)  {
    int index= hash_function()(key) % bucket_count;
    std::forward_list<value_type>& list = tables[index];

    auto it = std::find_if(list.begin(), list.end(),[&key](const value_type& pair){return pair.first == key;});

    if(it != list.end()) {
        return it->second;
    }

    list.push_front(std::make_pair(key, T{}));
    element_count++;
    return list.front().second;
}


template <class Key, class T, class Hash>
T& unordered_map<Key,T,Hash>::operator[](Key&& key)  {
    int index= hash_function()(key) % bucket_count;
    std::forward_list<value_type>& list = tables[index];

    auto it = std::find_if(list.begin(), list.end(),[&key](const value_type& pair){return pair.first == key;});

    if(it != list.end()) {
        return it->second;
    }

    list.push_front(std::make_pair(std::move(key), T{}));
    element_count++;
    return list.front().second;
}

template <class Key, class T, class Hash>
typename unordered_map<Key, T, Hash>::size_type  unordered_map<Key, T, Hash>::count(const Key& key) const {
    int index = hash_function()(key) % bucket_count;
    const std::forward_list<value_type>& list = tables[index];

    auto it = std::find_if(list.begin(), list.end(),[&key](const value_type& pair) { return pair.first == key;});
    return it == list.end() ? 1 : 0;

}

template <class Key, class T, class Hash>
typename unordered_map<Key, T, Hash>::iterator unordered_map<Key, T, Hash>::find(const Key& key) {
    size_type index = hash_function()(key) % bucket_count;
    std::forward_list<value_type>& list = tables[index];

    auto it = std::find_if(list.begin(), list.end(), [&key](const value_type& pair) {
        return pair.first == key;
    });

    if (it != list.end()) {
        return iterator(this, index, it);
    }

    return end();
}

template <class Key, class T, class Hash>
typename unordered_map<Key, T, Hash>::const_iterator unordered_map<Key, T, Hash>::find(const Key& key) const {
    size_type index = hash_function()(key) % bucket_count;
    const std::forward_list<value_type>& list = tables[index];

    auto it = std::find_if(list.begin(), list.end(), [&key](const value_type& pair) {
        return pair.first == key;
    });

    if (it != list.end()) {
        return const_iterator(this, index, it);
    }

    return end();
}


template <class Key, class T, class Hash>
typename unordered_map<Key, T, Hash>::iterator unordered_map<Key, T, Hash>::begin() {
    for (size_t i = 0; i < bucket_count; ++i) {
        if (!tables[i].empty()) {
            return iterator(this, i, tables[i].begin());
        }
    }
    return end();
}

template <class Key, class T, class Hash>
typename unordered_map<Key, T, Hash>::iterator unordered_map<Key, T, Hash>::end() {
    return iterator(this, bucket_count, typename std::forward_list<value_type>::iterator());
}



template <class Key, class T, class Hash>
typename unordered_map<Key, T, Hash>::const_iterator unordered_map<Key, T, Hash>::cbegin() const {
    for (size_t i = 0; i < bucket_count; ++i) {
        if (!tables[i].empty()) {
            return const_iterator(this, i, tables[i].cbegin());
        }
    }
    return cend();
}

template <class Key, class T, class Hash>
typename unordered_map<Key, T, Hash>::const_iterator unordered_map<Key, T, Hash>::cend() const {
    return const_iterator(this, bucket_count, typename std::forward_list<value_type>::const_iterator());
}




#ifndef HASH_TABLE
#define HASH_TABLE

#include <iterator>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <forward_list>
#include <cassert>

template <
    class Key,
    class T,
    class Hash = std::hash<Key>>
class unordered_map
{
public:
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const Key, T>;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using Table = std::vector<std::forward_list<value_type>>;
    using hasher = Hash;

private:
    class iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = typename unordered_map::value_type;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type *;
        using reference = value_type &;
        using list_it = typename std::forward_list<value_type>::iterator;

    public:
        iterator(unordered_map *map_, size_type bucket_index_, list_it it_) : map(map_), bucket_index(bucket_index_), it(it_)
        {
            bucket_count = map->bucket_count;
        }
        reference operator*() { return *it; }
        pointer operator->() { return &(*it); }

        iterator &operator++()
        {
            ++it;
            while (bucket_index < map->bucket_count && it == map->tables[bucket_index].end())
            {
                bucket_index++;
                if (bucket_index == map->bucket_count)
                {
                    it = typename std::forward_list<value_type>::iterator();
                    return *this;
                }
                it = map->tables[bucket_index].begin();
            }
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator &other) const
        {
            return map == other.map && bucket_index == other.bucket_index && it == other.it;
        }

        bool operator!=(const iterator &other) const
        {
            return !(*this == other);
        }

    private:
        unordered_map *map;
        size_type bucket_index;
        size_type bucket_count;
        list_it it;
    };
    class const_iterator;

public:
    unordered_map(float max_load_factor = 0.75, size_type bucket_count = 11); //++
    template <typename InputIt>
    unordered_map(InputIt first, InputIt last, size_type bucket_count = 11, float max_load_factor = 0.75);            //++
    unordered_map(std::initializer_list<value_type> init, size_type bucket_count = 11, float max_load_factor = 0.75); //++
    unordered_map(const unordered_map &other);                                                                        //++
    unordered_map &operator=(const unordered_map &other);                                                             //++
    unordered_map(unordered_map &&other);                                                                             //++
    unordered_map &operator=(unordered_map &&other);                                                                  //++
    ~unordered_map();                                                                                                 //++

public:
    size_type size() const noexcept;     //++
    bool empty() const noexcept;         //++
    size_type max_size() const noexcept; //++

public:
    void rehash(size_type new_bucket_count);              //++
    void insert(std::initializer_list<value_type> ilist); //++
    void insert(const Key &key, const T &value);          //++
    void clear() noexcept;                                //++
    iterator erase(iterator pos);
    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);
    size_type erase(const Key &key);          //++
    void swap(unordered_map &other) noexcept; //++

public:
    size_type load_factor() const;   //++
    float max_load_factors() const;  // ++
    void max_load_factors(float ml); //++
    hasher hash_function() const;    //++
public:
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

public:
    T &at(const Key &key);
    const T &at(const Key &key) const;
    T &operator[](const Key &key);
    T &operator[](Key &&key);
    size_type count(const Key &key) const;
    iterator find(const Key &key);
    const_iterator find(const Key &key) const;

private:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    size_type nextPrime(int N)
    {
        if (N <= 1)
            return 2;

        int prime = N;
        bool found = false;

        while (!found)
        {
            prime++;

            if (isPrime(prime))
                found = true;
        }

        return prime;
    }

private:
    size_type element_count = 0;
    size_type bucket_count;
    float max_load_factor;
    Table tables;
};

template <class Key, class T, class Hash>
class unordered_map<Key, T, Hash>::const_iterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = typename unordered_map::value_type;
    using list_it = typename std::forward_list<value_type>::const_iterator;
    using difference_type = std::ptrdiff_t;
    using pointer = const value_type *;
    using reference = const value_type &;

public:
    const_iterator(const unordered_map *map_, size_type bucket_index_, list_it it)
        : map(map_), bucket_index(bucket_index_), bucket_count(map_->bucket_count), it(it)
    {
    }

    reference operator*() const { return *it; }
    pointer operator->() const { return &(*it); }

    const_iterator &operator++()
    {
        ++it;

        while (bucket_index < map->bucket_count && it == map->tables[bucket_index].cend())
        {
            ++bucket_index;
            if (bucket_index == map->bucket_count)
            {
                it = typename std::forward_list<value_type>::const_iterator();
                return *this;
            }
            it = map->tables[bucket_index].cbegin();
        }
        return *this;
    }

    const_iterator operator++(int)
    {
        const_iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const const_iterator &other) const
    {
        return map == other.map && bucket_index == other.bucket_index && it == other.it;
    }

    bool operator!=(const const_iterator &other) const
    {
        return !(*this == other);
    }

private:
    const unordered_map *map;
    size_type bucket_index;
    size_type bucket_count;
    list_it it;
};
#include "hash_table.tcc"

#endif // HASH_TABLE

#include "p_4_header.hpp"
#include <algorithm> // std::min only

// 2.1 length
std::size_t length(char const *a) {
    if (a == nullptr) return 0;
    std::size_t len = 0;
    while (a[len] != '\0') ++len;
    return len;
}

// 2.2 compare
int compare(char const *str1, char const *str2) {
    if (str1 == nullptr && str2 == nullptr) return 0;
    if (str1 == nullptr) return -1;
    if (str2 == nullptr) return 1;

    std::size_t k = 0;
    while (true) {
        char c1 = str1[k];
        char c2 = str2[k];
        if (c1 == '\0' && c2 == '\0') return 0;
        if (c1 == '\0') return -1;
        if (c2 == '\0') return 1;
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        ++k;
    }
}

// 2.3 assign
void assign(char *str1, char const *str2) {
    if (str1 == nullptr || str2 == nullptr) return;
    std::size_t i = 0;
    do {
        str1[i] = str2[i];
    } while (str2[i++] != '\0');
}

// 2.4 distance (recursive Levenshtein)
unsigned int distance(char const *s1, char const *s2) {
    if (s1 == nullptr || s2 == nullptr) return 0;
    if (s1[0] == '\0') return length(s2);
    if (s2[0] == '\0') return length(s1);
    if (s1[0] == s2[0])
        return distance(s1 + 1, s2 + 1);
    unsigned int del = distance(s1 + 1, s2);
    unsigned int ins = distance(s1, s2 + 1);
    unsigned int sub = distance(s1 + 1, s2 + 1);
    return 1 + std::min({del, ins, sub});
}

// 2.5 is_sorted
std::size_t is_sorted(char *array[], std::size_t capacity) {
    if (capacity <= 1) return capacity;
    for (std::size_t i = 1; i < capacity; ++i) {
        if (array[i] == nullptr || array[i - 1] == nullptr) {
            // Treat nullptr as smaller than any valid string
            if (array[i] == nullptr && array[i - 1] != nullptr) return i;
            if (array[i] != nullptr && array[i - 1] == nullptr) continue;
            // both null → equal, continue
            continue;
        }
        if (compare(array[i], array[i - 1]) < 0)
            return i;
    }
    return capacity;
}

// 2.6 insert
void insert(char *array[], std::size_t capacity) {
    if (capacity <= 1) return;
    char *value = array[capacity - 1];
    if (value == nullptr) return;

    std::size_t pos = 0;
    while (pos < capacity - 1) {
        if (array[pos] == nullptr) {
            ++pos;
            continue;
        }
        if (compare(array[pos], value) >= 0) break;
        ++pos;
    }

    for (std::size_t i = capacity - 1; i > pos; --i) {
        array[i] = array[i - 1];
    }
    array[pos] = value;
}

// 2.7 insertion_sort
void insertion_sort(char *array[], std::size_t capacity) {
    for (std::size_t k = 1; k < capacity; ++k) {
        char *key = array[k];
        if (key == nullptr) continue;

        std::size_t j = k;
        while (j > 0) {
            if (array[j - 1] == nullptr) {
                array[j] = array[j - 1];
                --j;
                continue;
            }
            if (compare(array[j - 1], key) <= 0) break;
            array[j] = array[j - 1];
            --j;
        }
        array[j] = key;
    }
}

// 2.8 remove_duplicates
std::size_t remove_duplicates(char *array[], std::size_t capacity) {
    if (capacity == 0) return 0;
    std::size_t write = 0;
    for (std::size_t read = 0; read < capacity; ++read) {
        if (array[read] == nullptr) continue;
        if (write == 0 || compare(array[read], array[write - 1]) != 0) {
            array[write++] = array[read];
        }
    }
    return write;
}

// 2.9 find
std::size_t find(char *array[], std::size_t capacity, char const *str) {
    if (capacity == 0 || str == nullptr || array == nullptr) return 0;

    // Check index 0
    unsigned int best_dist = (array[0] == nullptr) ? length(str) : distance(array[0], str);
    std::size_t best_idx = 0;
    if (array[0] != nullptr && best_dist == 0) return 0;

    // Check rest
    for (std::size_t i = 1; i < capacity; ++i) {
        if (array[i] == nullptr) continue;
        unsigned int d = distance(array[i], str);
        if (d == 0) return i;  // First exact match
        if (d < best_dist) {
            best_dist = d;
            best_idx = i;
        }
    }
    return best_idx;
}

// 2.11 free_word_array
void free_word_array(char **word_array) {
    if (word_array == nullptr) return;
    if (word_array[0] != nullptr) {
        delete[] word_array[0];
    }
    delete[] word_array;
}
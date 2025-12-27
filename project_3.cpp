#include <iostream>
#include <climits>
#include <cassert>

double* geometric(double a, double ratio, std::size_t cap);
double* cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1);
std::size_t shift_duplicates(int array[], std::size_t capacity);
void deallocate(double*& ptr, bool is_array, std::size_t capacity = 0);

int main() {
    return 0;
}

double* geometric(double a, double ratio, std::size_t cap) {
    double* arr = new double[cap];
    for (std::size_t i = 0; i < cap; ++i) {
        arr[i] = a;
        a *= ratio;
    }
    return arr;
}

double* cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1) {
    std::size_t outSize = cap0 + cap1 - 1;
    double* result = new double[outSize]();  
    for (std::size_t i = 0; i < cap0; ++i) {
        for (std::size_t j = 0; j < cap1; ++j) {
            result[i + j] += array0[i] * array1[j];
        }
    }
    return result;
}

std::size_t shift_duplicates(int array[], std::size_t capacity) {
    if (capacity == 0) return 0;
    std::size_t writeIdx = 0;
    for (std::size_t readIdx = 0; readIdx < capacity; ++readIdx) {
        bool duplicate = false;
        for (std::size_t k = 0; k < writeIdx; ++k) {
            if (array[k] == array[readIdx]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            if (readIdx != writeIdx) {
                int temp = array[writeIdx];
                array[writeIdx] = array[readIdx];
                array[readIdx] = temp;
            }
            ++writeIdx;
        }
    }
    return writeIdx;
}

void deallocate(double*& ptr, bool is_array, std::size_t capacity) {
    if (ptr == nullptr) return;
    if (is_array) {
        for (std::size_t i = 0; i < capacity; ++i) {
            ptr[i] = 0.0;
        }
        delete[] ptr;
    } else {
        *ptr = 0.0;
        delete ptr;
    }
    ptr = nullptr;
}

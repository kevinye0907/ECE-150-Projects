#include <iostream>
#include <cassert>

void pattern( unsigned int n);
unsigned int log10(unsigned int n);
unsigned int count( unsigned int n, unsigned int bit);
unsigned int swap_bytes( unsigned int n, unsigned int b0, unsigned int b1);

void pattern ( unsigned int n){
    if (n == 0u){
        std::cout << "*" << std::endl;
        return;
    }
    unsigned int width = 2 * n + 1;
    for (int i = n; i >= 0; --i){
        unsigned int stars = 2* i + 1;
        unsigned int spaces = (width - stars)/ 2;
        for (unsigned int s = 0; s < spaces; ++s) {
            std::cout << " ";
        }
        for (unsigned int j =0; j < stars; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
        }
    for (unsigned int i = 1; i <= n; ++i){
        unsigned int stars = 2* i +1;
        unsigned int spaces = (width - stars)/ 2;
        for (unsigned int s= 0; s < spaces; ++s){
        std::cout << " ";
    }
    for (unsigned int j = 0; j < stars; ++j){
        std::cout << "*";
    }
    std::cout << std::endl;
}
}
unsigned int log10(unsigned int n) {
    assert (n != 0);
    unsigned int m = 0;
    while (n >= 10){
        n = n / 10;
        m = m + 1;
    }
    return m;
}
unsigned int count( unsigned int n, unsigned int bit) {
    assert( bit == 0 || bit ==1);
    unsigned int cnt = 0;
    for (unsigned int i = 0; i < 32; i = i +1){
        unsigned int current = (n >> i)& 1U;
        if (current == bit){
            cnt = cnt +1;
        }
    }
    return cnt;
}
unsigned int swap_bytes( unsigned int n, unsigned int b0, unsigned int b1){
    assert (b0 < 4 && b1 <4);
    if (b0 == b1){
        return n;
    }
    unsigned int shift0 = b0 * 8;
    unsigned int shift1 = b1 * 8;
    unsigned int byte0 = (n >> shift0) & 0xFFU;
    unsigned int byte1 = (n >> shift1) & 0xFFU;
    n = n & ~(0xFFU << shift0);
    n = n & ~ (0xFFU << shift1);
    n = n | (byte0 << shift1);
    n = n | (byte1 << shift0);
    return n;
}

int main() {
    std::cout << "n = 1:" << std::endl;
    pattern(1u);
    for (unsigned int n = 2; n <= 5; n = n + 1 ){
        std::cout << std::endl;
        std::cout << "n = " << n << ":" << std::endl;
        pattern(n);
    }
    
    return 0;
}



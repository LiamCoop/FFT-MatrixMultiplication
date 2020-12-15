#include "matrix_multiply.hpp"
#include <iostream>
#include <vector>

template<class T>
void print_rowmajor(T a, std::size_t m, std::size_t n);
void test_naive_matrix_multiply();
void test_matrix_multiply();

int main() {

    test_naive_matrix_multiply();
    test_matrix_multiply();
    return 0;
} 

void test_matrix_multiply() {
    std::vector<int> va = {};
    std::vector<int> vb = {};
    std::vector<int> vc = {};

    for (auto i = 1; i < 3000; i++) {
        va.push_back(i);
    }
    for (auto i = 1; i < 3000; i++) {
        vb.push_back(i);
    }

    int* pa = &*va.begin();
    int* pb = &*vb.begin();
    
    auto p0c = new int[4 * 5];
    auto p1c = new int[3 * 3];
    auto p2c = new int[4 * 5];
    auto p3c = new int[12 * 14];
    auto p4c = new int[12 * 12];
    auto p5c = new int[32 * 30];

    ra::cache::matrix_multiply(pa, pb, 4, 1, 5, p0c);
    print_rowmajor(p0c, 4, 5);

    ra::cache::matrix_multiply(pa, pb, 2, 3, 2, p1c);
    print_rowmajor(p1c, 2, 2);

    ra::cache::matrix_multiply(pa, pb, 3, 3, 3, p2c);
    print_rowmajor(p2c, 3, 3);

    ra::cache::matrix_multiply(pa, pb, 4, 6, 5, p3c);
    print_rowmajor(p3c, 4, 5);

    ra::cache::matrix_multiply(pa, pb, 12, 6, 14, p4c);
    print_rowmajor(p4c, 12, 14);

    ra::cache::matrix_multiply(pa, pb, 32, 64, 30, p5c);
    print_rowmajor(p5c, 32, 30);
}


void test_naive_matrix_multiply() {
    std::vector<int> va = {};
    std::vector<int> vb = {};
    std::vector<int> vc = {};

    for (auto i = 1; i < 3000; i++) {
        va.push_back(i);
    }
    for (auto i = 1; i < 3000; i++) {
        vb.push_back(i);
    }

    int* pa = &*va.begin();
    int* pb = &*vb.begin();

    auto p0c = new int[4 * 5];
    auto p1c = new int[3 * 3];
    auto p2c = new int[4 * 5];
    auto p3c = new int[12 * 14];
    auto p4c = new int[12 * 12];
    auto p5c = new int[32 * 30];

    ra::cache::matrix_multiply(pa, pb, 4, 1, 5, p0c);
    print_rowmajor(p0c, 4, 5);

    ra::cache::matrix_multiply(pa, pb, 2, 3, 2, p1c);
    print_rowmajor(p1c, 2, 2);

    ra::cache::matrix_multiply(pa, pb, 3, 3, 3, p2c);
    print_rowmajor(p2c, 3, 3);

    ra::cache::matrix_multiply(pa, pb, 4, 6, 5, p3c);
    print_rowmajor(p3c, 4, 5);

    ra::cache::matrix_multiply(pa, pb, 12, 6, 14, p4c);
    print_rowmajor(p4c, 12, 14);

    ra::cache::matrix_multiply(pa, pb, 32, 64, 30, p5c);
    print_rowmajor(p5c, 32, 30);
}

template<class T>
void print_rowmajor(T a, std::size_t m, std::size_t n) {
    for (auto i = 0; i < m; i++) {
        for (auto j = 0; j < n; j++) {
            std::cout << *(a + i * n + j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

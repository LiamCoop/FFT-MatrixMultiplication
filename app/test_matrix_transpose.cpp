#include "matrix_transpose.hpp"
#include <iostream>
#include <vector>

template<class T>
void print_rowmajor(T a, std::size_t m, std::size_t n);
template<class T>
void test_naiveT();
template<class T>
void test_T();

int main(){
    test_naiveT<int>();
    test_T<int>();
    return 0;
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

template<class T>
void test_naiveT() {
    
    std::vector<int> v1 = {};
    for (auto i = 0; i < 4096; i++) {
        v1.push_back(i);
    }

    int* p1 = &*v1.begin();
    auto p2 = new int[6];
    auto p3 = new int[8];
    auto p4 = new int[16];
    auto p5 = new int[25];
    auto p6 = new int[64];
    auto p7 = new int[100];
    auto p8 = new int[144];
    auto p9 = new int[225];
    auto p10 = new int[1024];
    auto p11 = new int[4096];

    print_rowmajor(p1, 2, 3);
    ra::cache::naive_matrix_transpose(p1, 2, 3, p2);
    print_rowmajor(p2, 3, 2);

    print_rowmajor(p1, 1, 8);
    ra::cache::naive_matrix_transpose(p1, 1, 8, p3);
    print_rowmajor(p3, 8, 1);
   
    print_rowmajor(p1, 8, 1);
    ra::cache::naive_matrix_transpose(p1, 8, 1, p3);
    print_rowmajor(p3, 1, 8);
   
    print_rowmajor(p1, 4, 4);
    ra::cache::naive_matrix_transpose(p1, 4, 4, p4);
    print_rowmajor(p4, 4, 4);

    print_rowmajor(p1, 5, 5);
    ra::cache::naive_matrix_transpose(p1, 5, 5, p5);
    print_rowmajor(p5, 5, 5);

    print_rowmajor(p1, 8, 8);
    ra::cache::naive_matrix_transpose(p1, 8, 8, p6);
    print_rowmajor(p6, 8, 8);

    print_rowmajor(p1, 10, 10);
    ra::cache::naive_matrix_transpose(p1, 10, 10, p7);
    print_rowmajor(p7, 10, 10);
    
    print_rowmajor(p1, 12, 12);
    ra::cache::naive_matrix_transpose(p1, 12, 12, p8);
    print_rowmajor(p8, 12, 12);

    print_rowmajor(p1, 15, 15);
    ra::cache::naive_matrix_transpose(p1, 15, 15, p9);
    print_rowmajor(p9, 15, 15);

    print_rowmajor(p1, 32, 32);
    ra::cache::naive_matrix_transpose(p1, 32, 32, p10);
    print_rowmajor(p10, 32, 32);

    print_rowmajor(p1, 64, 64);
    ra::cache::naive_matrix_transpose(p1, 64, 64, p11);
    print_rowmajor(p11, 64, 64);
}

template<class T>
void test_T() {

    std::vector<int> v1 = {};
    for (auto i = 0; i < 4096; i++) {//16x16
        v1.push_back(i);
    }

    int* p1 = &*v1.begin();
    auto p2 = new int[6];
    auto p3 = new int[8];
    auto p4 = new int[16];
    auto p5 = new int[25];
    auto p6 = new int[64];
    auto p7 = new int[100];
    auto p8 = new int[144];
    auto p9 = new int[225];
    auto p10 = new int[1024];
    auto p11 = new int[4096];

    print_rowmajor(p1, 2, 3);
    ra::cache::matrix_transpose(p1, 2, 3, p2);
    print_rowmajor(p2, 3, 2);
    
    print_rowmajor(p1, 1, 8);
    ra::cache::matrix_transpose(p1, 1, 8, p3);
    print_rowmajor(p3, 8, 1);

    print_rowmajor(p1, 8, 1);
    ra::cache::matrix_transpose(p1, 8, 1, p3);
    print_rowmajor(p3, 1, 8);
    
    print_rowmajor(p1, 4, 4);
    ra::cache::matrix_transpose(p1, 4, 4, p4);
    print_rowmajor(p4, 4, 4);

    print_rowmajor(p1, 5, 5);
    ra::cache::matrix_transpose(p1, 5, 5, p5);
    print_rowmajor(p5, 5, 5);
    
    print_rowmajor(p1, 8, 8);
    ra::cache::matrix_transpose(p1, 8, 8, p6);
    print_rowmajor(p6, 8, 8);

    print_rowmajor(p1, 10, 10);
    ra::cache::matrix_transpose(p1, 10, 10, p7);
    print_rowmajor(p7, 10, 10);

    print_rowmajor(p1, 12, 12);
    ra::cache::matrix_transpose(p1, 12, 12, p8);
    print_rowmajor(p8, 12, 12);

    print_rowmajor(p1, 15, 15);
    ra::cache::matrix_transpose(p1, 15, 15, p9);
    print_rowmajor(p9, 15, 15);

    print_rowmajor(p1, 32, 32);
    ra::cache::matrix_transpose(p1, 32, 32, p10);
    print_rowmajor(p10, 32, 32);

    print_rowmajor(p1, 64, 64);
    ra::cache::matrix_transpose(p1, 64, 64, p11);
    print_rowmajor(p11, 64, 64);

}

//#include "boost/math/constants/constants.hpp"
#include "fft.hpp"
#include <iostream>
#include <vector>
#include <complex>

void test_forwardFFT();
void test_MultByTwid();

int main(){
    
    test_forwardFFT();

    return 0;
}

void test_getDFTfactors() {
    auto a = ra::cache::getDFTfactors(8);
    auto n1 = std::get<0>(a);
    auto n2 = std::get<1>(a);
    std::cout << "n1: " << n1 << std::endl << "n2: " << n2 << std::endl;

    auto b = ra::cache::getDFTfactors(16);
    auto n3 = std::get<0>(b);
    auto n4 = std::get<1>(b);
    std::cout << "n3: " << n3 << std::endl << "n4: " << n4 << std::endl;

    auto c = ra::cache::getDFTfactors(225);
    auto n5 = std::get<0>(c);
    auto n6 = std::get<1>(c);
    std::cout << "n5: " << n5 << std::endl << "n6: " << n6 << std::endl;
}

std::vector<std::complex<float>> make_complex_vec(int n) {
    std::vector<std::complex<float>> v = {};
    for (auto i = 0; i < n; i++) {
        v.push_back(std::complex<float> (i, i));
    }
    return v;
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

void test_forwardFFT()
{
    
    std::complex<float> d[4] = { {3,0}, {2,0}, {1,0}, {5,0} };// {9,0}, {1,0}, {3,0}, {0,0} };
    ra::cache::forward_fft<std::complex<float>>(d, 4);
    print_rowmajor(d, 4, 1);

    std::complex<float> j(0, 1);
    std::complex<float> a[8] = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7} };
    ra::cache::forward_fft<std::complex<float>>(a, 8);
    print_rowmajor(a, 8, 1);
    
    std::complex<float> c[8] = { {3,0}, {2,0}, {1,0}, {5,0}, {9,0}, {1,0}, {3,0}, {0,0} };
    ra::cache::forward_fft<std::complex<float>>(c, 8);
    print_rowmajor(c, 8, 1);

    std::complex<float> b[64];
    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 4; j++) {
            b[i*4+j] = static_cast<std::complex<float>>(j+1);
        }
    }
    print_rowmajor(b, 4, 4);
    ra::cache::forward_fft<std::complex<float>>(b, 16);
    print_rowmajor(b, 4, 4);


    return;
}

void test_MultByTwid()
{
    std::complex<float> c[4] = { {1,1},{1,1}, {1,1}, {1,1} };
    print_rowmajor(c, 2, 2);
    ra::cache::MultByTwid(c, 2, 2);
    print_rowmajor(c, 2, 2);

    std::complex<float> d[4] = { {},{1,1}, {3,3}, {4,4} };
    print_rowmajor(d, 1, 4);
    ra::cache::MultByTwid(d, 1, 4);
    print_rowmajor(d, 1, 4);

    std::complex<float> d1[4] = { {},{1,1}, {3,3}, {4,4} };
    print_rowmajor(d1, 4, 1);
    ra::cache::MultByTwid(d1, 4, 1);
    print_rowmajor(d1, 4, 1);

    std::complex<float> d2[16] = { {1,0}, {1,1}, {1,2}, {1,3},
                                   {2,0}, {2,1}, {2,2}, {2,3},
                                   {3,0}, {3,1}, {3,2}, {3,3},
                                   {4,0}, {4,1}, {4,2}, {4,3} };
    print_rowmajor(d2, 4, 4);
    ra::cache::MultByTwid(d2, 4, 4);
    print_rowmajor(d2, 4, 4);

    std::complex<float> b[16];
    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 4; j++) {
            b[i * 4 + j] = static_cast<std::complex<float>>(j + 1);
        }
    }
    print_rowmajor(b, 4, 4);
    ra::cache::MultByTwid(b, 4,4);
    print_rowmajor(b, 4, 4);

}



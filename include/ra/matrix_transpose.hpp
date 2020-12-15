#include <cstddef>
#include <cassert>
#include <array>
#include <algorithm>

#define small_enough 64

namespace ra {
    namespace cache {

        template <class T>
        struct state {
            const T* a;
            std::size_t m;
            std::size_t n;
            T* b;
        };

        struct offsets {
            std::size_t M;
            std::size_t N;
        };

        template <class T>
        void rec_matrix_transpose(struct state<T> s0, const T* a, std::size_t m, std::size_t n, struct offsets os, T* b) {
            if ((m * n) <= small_enough) {
                for (auto i = 0; i < m; i++) {
                    for (auto j = 0; j < n; j++) {
                        *(b + (j + os.N) * s0.m + i + os.M) = *(a + (i + os.M) * s0.n + j + os.N);
                    }
                }
            } else {
                if (m > n) { //chop rows in half
                    struct offsets osL = { os.M, os.N };
                    struct offsets osR = { os.M + (m - m / 2), os.N };
                    rec_matrix_transpose<T>(s0, a, m - m / 2, n, osL, b);
                    rec_matrix_transpose<T>(s0, a, m / 2, n, osR, b);
                }
                else { //chop columns in half
                    struct offsets osL = { os.M, os.N };
                    struct offsets osR = { os.M, os.N + (n - n / 2) };
                    rec_matrix_transpose<T>(s0, a, m, n - n / 2, osL, b);
                    rec_matrix_transpose<T>(s0, a, m, n / 2, osR, b);
                }
            }
        }

        template <class T>
        void matrix_transpose(const T* a, std::size_t m, std::size_t n, T* b) {
            if (a != b) {
                struct state<T> s0 = { a, m, n, b };
                struct offsets os = { 0,0 };
                rec_matrix_transpose<T>(s0, a, m, n, os, b);
            } else {
                auto c = new T[m * n];
                std::copy(a, a + (m * n), c);
                struct state<T> s0 = { c, m, n, b };
                struct offsets os = { 0,0 };
                rec_matrix_transpose<T>(s0, c, m, n, os, b);
            }
        }

        template <class T>
        void naive_matrix_T(const T* a, std::size_t m, std::size_t n, T* b) {
            for (auto i = 0; i < m; i++) {
                for (auto j = 0; j < n; j++) {
                    *(b + j * m + i) = *(a + i * n + j);
                }
            }
        }

        template <class T>
        void naive_matrix_transpose(const T* a, std::size_t m, std::size_t n, T* b) {
            if (a != b) {
                naive_matrix_T<T>(a, m, n,  b);
            } else {
                auto c = new T[m * n];
                std::copy(a, a + (m * n), c);
                naive_matrix_T<T>(c, m, n, b);
            }
        }
    }
} 

#include <cstddef>
#include <algorithm>

#define small_enough 1
namespace ra{ 
    namespace cache {

        template <class T>
        struct state {
            const T* a;
            const T* b;
            std::size_t m;
            std::size_t n;
            std::size_t p;
            T* c;
        };

        struct offsets {
            std::size_t M;
            std::size_t N;
            std::size_t P;
        };

        template<class T>
        void matrix_multiply(const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c) {
            struct offsets os = {0,0,0};
            struct state<T> s0 = { a,b,m,n,p,c };
            std::fill(c, c + (m * p), 0);
            rec_matrix_multiply(s0, os, a, b, m, n, p, c);
        }

        template <class T>
        void rec_matrix_multiply(struct state<T> s0, struct offsets os, const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c) {

            auto max = std::max(std::max(m, n), p);
            if ((m * n * p) <= small_enough) {
                for (auto i = 0; i < m; i++) {
                    for (auto j = 0; j < p; j++) {
                        for (auto k = 0; k < n; k++) {
                            auto D = (*(a + (i + os.M)*s0.n + (k + os.N)) * *(b + (k + os.N) * s0.p + (j + os.P)));
                            *(c + (i + os.M) * s0.p + (j + os.P)) += D;
                        }
                    }
                }
            } else {
                if (max == m) {
                    struct offsets osL = { os.M, os.N, os.P };
                    struct offsets osR = { os.M + (m - m / 2), os.N, os.P }; //divide on A,C
                    rec_matrix_multiply(s0, osL, a, b, m - m / 2, n, p, c);
                    rec_matrix_multiply(s0, osR, a, b, m / 2, n, p, c);
                }
                else if (max == n) {
                    struct offsets osL = { os.M, os.N, os.P };
                    struct offsets osR = { os.M, os.N + (n - n / 2), os.P }; //divide on A, B
                    rec_matrix_multiply(s0, osL, a, b, m, n - n / 2, p, c);
                    rec_matrix_multiply(s0, osR, a, b, m, n / 2, p, c);
                }
                else { //max == p OR all equal
                    struct offsets osL = { os.M, os.N, os.P };
                    struct offsets osR = { os.M, os.N, os.P + (p - p / 2) }; //divide on A, C
                    rec_matrix_multiply(s0, osL, a, b, m, n, p - p / 2, c);
                    rec_matrix_multiply(s0, osR, a, b, m, n, p / 2, c);
                }
            }
        }

        template<class T>
        void naive_matrix_multiply(const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c) {
            for (auto i = 0; i < m; i++) {
                for (auto j = 0; j < p; j++) {
                    *(c + i * p + j) = 0;
                    for (auto k = 0; k < n; k++) {
                        *(c + i * p + j) += (*(a + n * i + k) * *(b + p * k + j));
                    }
                }
            }
        }
    }
} 

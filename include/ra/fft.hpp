#include "matrix_transpose.hpp"
#include <boost/math/constants/constants.hpp>
//#include "boost/math/constants/constants.hpp"
#include <complex>
#include <iostream>

namespace ra {
	namespace cache {

		template <class T>
		void forward_fft(T* x, std::size_t n);
	
		template <class T>
		void MultByTwid(T* x, int n, int m);

		template <class T>
		void base_dft(T* x, std::size_t n);

		std::pair<int, int> getDFTfactors(std::size_t n);

		template <class T>
		void forward_fft(T* x, std::size_t n) {
			assert(n > 0);
			auto n1n2 = getDFTfactors(n);
			auto n1 = std::get<0>(n1n2);
			auto n2 = std::get<1>(n1n2);
			if (n <= 2) {
				if (n == 1) { return; }
				base_dft(x, n);
			} else {
				matrix_transpose(x, n1, n2, x);
				for (auto i = 0; i < n2; ++i) {
					forward_fft(x + i * n1, n1);
				}
				MultByTwid(x, n2, n1);
				matrix_transpose(x, n2, n1, x);
				for (auto i = 0; i < n1; ++i) {
					forward_fft(x + i * n2, n2);
				}
				matrix_transpose(x, n1, n2, x);
			}
		}
		
		std::complex<double> getW(int n, int m) {
			std::complex<double> j(0, 1);
			std::complex<double> w = std::pow<double>(boost::math::constants::e<double>(), 
				j * boost::math::constants::two_pi<double>() / static_cast<double>(m * n));
			return w;
		}

		template <class T>
		void MultByTwid(T* x, int n, int m) {
			std::complex<double> w = getW(n, m);
			for (auto ii = 0; ii < n; ++ii) {
				for (auto jj = 0; jj < m; ++jj) {
					std::complex<double> twid = std::pow<double>(w, -ii * jj);
					*(x + ii * m + jj) *= static_cast<T>(twid);
				}
			}
		}

		template <class T>
		void base_dft(T* x, std::size_t n) {
			for (auto i = 0; i < n; i = i+2) {
				auto tmp = *(x + i);
				auto tmp2 = *(x + i + 1);
				*(x + i) = tmp + tmp2;
				*(x + i + 1) = tmp - tmp2;
			}
		}

		std::pair<int,int> getDFTfactors(std::size_t n) {
			auto test_n1 = static_cast<int>(std::sqrt(n));
			while (n % test_n1 != 0) {
				test_n1--;
			}
			return std::make_pair(test_n1, n / test_n1);
		}
	}
}

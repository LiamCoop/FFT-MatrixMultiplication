# Introduction
The two tools included in this repository are C++ implementations of the Fast Fourier Transform and Matrix Multiplication.
These tools make use of cache optimization while remaining agnostic of cache-size.

# Cache-obliviousness
The functions included in this repository are developed to be cache (size) oblivious, however intentionally still benefit from temporal and spatial locality [1].
These functions are therefore more efficient than their naive equivalents due to optimizations that increase this locality.


[1] https://en.wikipedia.org/wiki/Locality_of_reference

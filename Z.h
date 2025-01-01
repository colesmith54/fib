#pragma once
#include <gmpxx.h>

struct Z {
    // a + b * sqrt(5)
    mpz_class a, b;

    Z operator *(const Z& o) {
        return Z(a * o.a + (5 * b * o.b), a * o.b + b * o.a);
    }

    Z& operator *=(const Z& o) {
        return *this = *this * o;
    }

    Z& operator >>=(int n) {
        a >>= n;
        b >>= n;
        return *this;
    }
};
#pragma once
#include <gmpxx.h>

struct M2x2 {
    mpz_class a, b, c, d;
    M2x2(mpz_class w, mpz_class x, mpz_class y, mpz_class z) : a(std::move(w)), b(std::move(x)), c(std::move(y)), d(std::move(z)) {}
    M2x2 operator *(const M2x2& o) const {
        return {
                a * o.a + b * o.c,
                a * o.b + b * o.d,
                c * o.a + d * o.c,
                c * o.b + d * o.d
        };
    }
    M2x2& operator *=(const M2x2& o) {
        return *this = *this * o;
    }
};

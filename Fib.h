#pragma once
#include "Ans.h"
#include "M2x2.h"
#include "Z.h"

////////// BASE CLASS //////////

template <typename Derived>
class Fib {
public:
    // Return the Nth fibonacci number, and how much time the computation took
    static Ans test(mpz_class N) {
        auto t1 = std::chrono::high_resolution_clock::now();
        mpz_class v = Derived::compute(N);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
        return {v, dur};
    }
};

////////// IMPLEMENTATIONS //////////

class NaiveRecursion : public Fib<NaiveRecursion> {
    public:
    static mpz_class compute(mpz_class n) {
        if (n <= 1) return n;
        return compute(n - 1) + compute(n - 2);
    }
};

class DP : public Fib<DP> {
public:
    static mpz_class compute(mpz_class n) {
        if (n <= 1) return n;
        mpz_class a = 0, b = 1, c = 1;
        for (mpz_class i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

class NaiveMatrix : public Fib<NaiveMatrix> {
public:
    static mpz_class compute(mpz_class n) {
        M2x2 fib(0, 1, 1, 1);
        M2x2 step(fib);

        while (n--) {
            fib *= step;
        }

        return fib.a;
    }
};

class FastExpMatrix : public Fib<FastExpMatrix> {
public:
    static mpz_class compute(mpz_class n) {
        M2x2 fib(0, 1, 1, 1);
        M2x2 step(fib);

        while (n) {
            if ((n & 1) != 0) {
                fib *= step;
            }
            step *= step;
            n >>= 1;
        }

        return fib.a;
    }
};

class Binet : public Fib<Binet> {
public:
    static mpz_class compute(mpz_class n) {
        Z fib(1, 1);
        Z step(fib);

        n--;
        while (n) {
            if ((n & 1) != 0) {
                fib *= step;
                fib >>= 1;
            }

            step *= step;
            step >>= 1;
            n >>= 1;
        }

        return fib.b;
    }
};

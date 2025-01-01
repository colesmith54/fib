#include "Fib.h"
#include <functional>

mpz_class find_n(const std::function<Ans(mpz_class)>& f) {
    mpz_class n = 35;

    // determine reasonable binary search range
    while (true) {
        Ans a = f(n);
        if (a.time > std::chrono::milliseconds (1000)) break;
        n *= 2;
    }

    mpz_class ret = n;
    mpz_class l = n / 2;
    mpz_class r = n;

    while (l <= r) {
        mpz_class m = (l + r) / 2;
        Ans a = f(m);
        if (a.time > std::chrono::milliseconds (1000)) {
            r = m - 1;
        } else {
            ret = m;
            l = m + 1;
        }
    }

    return ret;
}

int main() {
//    std::cout <<
//              "-- Naive Recursion --\n" << to_scientific(find_n(NaiveRecursion::test)) << "\n\n" <<
//              "-- DP --\n" << to_scientific(find_n(DP::test)) << "\n\n" <<
//              "-- Naive Matrix --\n" << to_scientific(find_n(NaiveMatrix::test)) << "\n\n" <<
//              "-- FastExp Matrix --\n" << to_scientific(find_n(FastExpMatrix::test)) << "\n\n" <<
//              "-- Binet --\n" << to_scientific(find_n(Binet::test)) << "\n\n" <<
//    std::endl;

    std::cout << Binet::test(6.66e7) << std::endl;
    return 0;
}

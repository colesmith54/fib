#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <gmpxx.h>

struct Ans {
    mpz_class val;
    std::chrono::milliseconds time;
    Ans(mpz_class v, std::chrono::milliseconds t) : val(std::move(v)), time(t) {}
};

std::string to_scientific(const mpz_class& num) {
    std::string str = num.get_str();
    size_t len = str.length();

    if (len == 0) {
        return "0";
    }

    std::string mantissa = str[0] + std::string(".") + str.substr(1, 5);
    unsigned long long exponent = len - 1;

    std::ostringstream oss;
    oss << mantissa << "e+" << exponent;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Ans& a) {
    os << "value: " << to_scientific(a.val) << ", time elapsed: " << a.time.count() << "ms";
    return os;
}

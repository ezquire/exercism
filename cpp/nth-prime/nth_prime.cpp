#include "nth_prime.h"
#include <vector>
#include <iostream>
#include <cmath>
namespace nth_prime {
    int nth(int n) {
        if (n < 1) 
            throw std::domain_error("the given n is out of bounds");
        if (n == 1) 
            return 2;
        if (n == 2) 
            return 3;
        int limit, root, count = 1;
        limit = (int)(n*(log(n) + log(log(n)))) + 3;
        root = (int)sqrt(limit) + 1;
        limit = (limit-1)/2;
        root = root/2 - 1;
        std::vector<bool> sieve(limit, true);
        for(int i = 0; i < root; ++i) {
            if (sieve[i]) {
                ++count;
                for(int j = 2*i*(i+3)+3, p = 2*i+3; j < limit; j += p) {
                    sieve[j] = false;
                }
            }
        }
        int p;
        for(p = root; count < n; ++p) {
            if (sieve[p]) {
                ++count;
            }
        }
        return 2*p+1;
    }
}  // namespace nth_prime

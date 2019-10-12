#include "sieve.h"

namespace sieve {
    std::vector<int> primes(int n) {
        std::vector<int> primes = {};
        if(n < 2)
            return std::vector<int> {};
        std::vector<bool> isprime (n + 1, true);
        for(int i = 2; i * i <= n; ++i)
            if(isprime[i] == true)
                for(int j = i * i; j <= n; j += i)
                    isprime[j] = false;
        for(uint64_t i = 2; i < isprime.size(); ++i)
            if(isprime[i])
                primes.push_back(i);
        return primes;
    }
}  // namespace sieve

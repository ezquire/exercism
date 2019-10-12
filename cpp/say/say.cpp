#include "say.h"
#include <iostream>
#include <vector>
namespace say {
    const std::string ones[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const std::string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const std::string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    std::string in_english(uint64_t n) {
        if(n < 0 || n >= 1000ULL * 1000ULL * 1000ULL * 1000ULL)
            throw std::domain_error("The given number is out of range");
        if(n < 10)
            return ones[n];
        else if(n > 9 && n < 20)
            return teens[n - 10];
        else if(n > 19 && n < 100)
            return tens_in_english(n);
        else if(n > 99 && n < 1000)
            return hundreds_in_english(n);
        else {
            std::string number = "";
            int count = 0;
            while(n > 0) {
                auto chunk = n % 1000;
                while(chunk == 0) {
                    ++count;
                    n /= 1000;
                    chunk = n % 1000;
                }
                switch(count) {
                case 1:
                    number = number == "" ? "thousand" : "thousand " + number;
                    break;
                case 2:
                    number = number == "" ? "million" : "million " + number;
                    break;
                case 3:
                    number = number == "" ? "billion" : "billion " + number;
                }
                number = number == "" ? in_english(chunk) : in_english(chunk) + " " + number;
                ++count;
                n /= 1000;
            }
            return number;
        }
        return "";
    }

    std::string tens_in_english(uint64_t n) {
        if(n % 10 == 0)
            return tens[n / 10];
        return tens[n / 10] + "-" + ones[n % 10];
    }

    std::string hundreds_in_english(uint64_t n) {
        std::string prefix = ones[n / 100] + " hundred";
        n -= 100 * (n / 100);
        std::string suffix = tens_in_english(n);
        if(suffix != "")
            return prefix + " " + suffix;
        return prefix;
    }
} //namespace say

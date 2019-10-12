#if !defined(SAY_H)
#define SAY_H

#include <string>

namespace say {
    std::string in_english(uint64_t);
    std::string tens_in_english(uint64_t);
    std::string hundreds_in_english(uint64_t);
}  // namespace say

#endif // SAY_H

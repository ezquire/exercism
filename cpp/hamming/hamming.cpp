#include "hamming.h"
#include <stdexcept>
int hamming::compute(std::string s1, std::string s2) {
  
  int diff = 0;

  if(s1.length() != s2.length())
    throw std::domain_error("Both strings must be equal length\n");

  if(s1 == s2)
    return 0;

  for(unsigned i = 0; i < s1.length(); ++i) {
    if(s1[i] != s2[i]) diff++;
  }

  return diff;
}

#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <string>
#include <map>

namespace dna {
  class counter {
  public:
    counter(std::string);
    int count(char) const;
    std::map<char, int> nucleotide_counts() const;
  private:
    std::map<char, int> counts;
  };
}

#endif //NUCLEOTIDE_COUNT_H

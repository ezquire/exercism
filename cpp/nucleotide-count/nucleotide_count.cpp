#include "nucleotide_count.h"
#include <stdexcept>

dna::counter::counter(std::string seq) {
    counts = {{'A',0},{'C',0},{'T',0},{'G',0}};
    for(char c : seq) {
        if(counts.find(c) == counts.end()) 
            throw std::invalid_argument("Only characters ACTG are allowed\n");
        else counts.find(c)->second++;
    }
}

int dna::counter::count(char c) const {
    if(counts.find(c) == counts.end()) 
        throw std::invalid_argument("Character must be one of ACTG\n");
    return counts.find(c)->second;
}

std::map<char, int> dna::counter::nucleotide_counts() const {
    return counts;
}

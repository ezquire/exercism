#include "rna_transcription.h"

char transcription::to_rna(char c) {
    if(c == 'A') return 'U';
    else if(c == 'T') return'A';
    else if(c == 'C') return'G';
    else if(c == 'G') return'C';
    return '\0';
}

std::string transcription::to_rna(const char* c) {
    std::string S(c);
    for(char& c : S)
        c = to_rna(c);
    return S;
}


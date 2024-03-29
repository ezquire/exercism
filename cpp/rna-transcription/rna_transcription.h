#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H

#include <string>

namespace transcription {
    char to_rna(char);
    std::string to_rna(const char*);
}

#endif //RNA_TRANSCRIPTION_H

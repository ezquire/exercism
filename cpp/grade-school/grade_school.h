#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <vector>
#include <string>

namespace grade_school {
    class school {
    public:
        school() = default;
        std::map<int, std::vector<std::string>> roster() const;
        void add(const std::string&, int);
        std::vector<std::string> grade(int) const;
    private:
        std::map<int, std::vector<std::string>> _roster;
    };
}

#endif

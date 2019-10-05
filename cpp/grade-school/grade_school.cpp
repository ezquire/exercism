#include "grade_school.h"
#include <algorithm>

std::map<int, std::vector<std::string>> grade_school::school::roster() const {
    return _roster;
}

void grade_school::school::add(const std::string& name, int grade) {
    if(_roster.find(grade) == _roster.end()) {
        std::vector<std::string> names {name};
        _roster.emplace(grade, names);
    } else {
        _roster.find(grade)->second.push_back(name);
        std::sort(_roster.find(grade)->second.begin(),
                  _roster.find(grade)->second.end());
    }
}

std::vector<std::string> grade_school::school::grade(int g) const {
    if(_roster.find(g) != _roster.end())
        return _roster.find(g)->second;
    return std::vector<std::string>();
}

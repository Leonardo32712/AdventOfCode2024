#include "../include/safetyManual.h"

safetyManual::safetyManual() {}

safetyManual::safetyManual(intPairVector rules, intMatrix updatePages) {
    this->rules = rules;
    this->updatePages = updatePages;
}

safetyManual::~safetyManual() {}

void safetyManual::emplaceRule(int a, int b) {
    this->rules.emplace_back(a, b);
}

void safetyManual::pushUpdatePages(intVector page) {
    this->updatePages.push_back(page);
}

int safetyManual::sumCorrectPages() {
    int summary = 0;

    for(size_t page = 0; page < updatePages.size(); page++) {
        if(!checkPage(updatePages[page])) {
            size_t midTerm = (updatePages[page].size()) / 2;
            summary += updatePages[page][midTerm];
        }
    }

    return summary;
}

bool safetyManual::checkPage(intVector& page) {
    bool correctPage = true;

    for(size_t first = 0; first < page.size() - 1; first++) {
        for(size_t second = first + 1; second < page.size(); second++) {
            if(!checkRules(page[first], page[second])) {
                correctPage = false;
                reorderPage(page, first, second);
                second = first + 1;
            }
        }
    }

    return correctPage;
}

void safetyManual::reorderPage(intVector& page, const int first, const int second) {
    for(int i = first; i < second; i++) {
        std::swap(page[i],page[i+1]);
    }
}

bool safetyManual::checkRules(const int first, const int second) {
    for(size_t rule = 0; rule < rules.size(); rule++){
        if(rules[rule].first == second && rules[rule].second == first) {
            return false;
        } else if(rules[rule].first == first && rules[rule].second == second) {
            return true;
        }
    }
    return true;
}

void safetyManual::printManual() {
    std::cout << "Safety Manual Rules:" << std::endl;
    for (const auto& rule : rules) {
        std::cout << "Rule: " << rule.first << "|" << rule.second << std::endl;
    }

    std::cout << "\nUpdate Pages:" << std::endl;
    for (const auto& page : updatePages) {
        std::cout << "Page: ";
        for (const auto& value : page) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
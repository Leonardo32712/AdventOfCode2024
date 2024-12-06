#include "safetyManual.h"

safetyManual::safetyManual() {}

safetyManual::safetyManual(intPairVector rules, intMatrix updatePages) {
    this->rules = rules;
    this->updatePages = updatePages;
}

safetyManual::~safetyManual() {}

void safetyManual::emplaceRule(int a, int b) {
    this->rules.emplace_back(a, b);
}

void safetyManual::pushUpdatePages(std::vector<int> page) {
    this->updatePages.push_back(page);
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
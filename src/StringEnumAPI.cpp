#include <Geode/Geode.hpp>
#include "../include/StringEnumAPI.hpp"
#include "StringEnumNode.hpp"

using namespace geode::prelude;

namespace myth::StringEnum {
    StringEnumNode* createStringEnum(const std::vector<std::string>& options) {
        auto strEnum = StringEnumNode::create(options);
        return strEnum;
    }

    std::string getSelectedOption(StringEnumNode* strEnum) {
        return StringEnumNode::getSelectedOption(strEnum);
    }

    int getSelectedOptionIndex(StringEnumNode* strEnum) {
        return StringEnumNode::getSelectedOptionIndex(strEnum);
    }

    void setSelectedOption(StringEnumNode* strEnum, int optionIndex) {
        StringEnumNode::setSelectedOption(strEnum, optionIndex);
    }
}
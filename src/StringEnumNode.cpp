#include "StringEnumNode.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

StringEnumNode* StringEnumNode::create(const std::vector<std::string>& options) {
    auto ret = new StringEnumNode();
    if (ret->init(options)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void StringEnumNode::optionLeft(CCObject* sender) {
    if (m_currentIndex == 0) {
        m_currentIndex = m_options.size() - 1;
    } else {
        m_currentIndex--;
    }

    m_selectedOption = m_options[m_currentIndex];
    m_settingLabel->setString(m_selectedOption.c_str());
}

void StringEnumNode::optionRight(CCObject* sender) {
    if (m_currentIndex == m_options.size() - 1) {
        m_currentIndex = 0;
    } else {
        m_currentIndex++;
    }
    
    m_selectedOption = m_options[m_currentIndex];
    m_settingLabel->setString(m_selectedOption.c_str());
}

std::string StringEnumNode::getSelectedOption(StringEnumNode* strEnum) {
    return strEnum->m_selectedOption;
}

int StringEnumNode::getSelectedOptionIndex(StringEnumNode* strEnum) {
    return strEnum->m_currentIndex;
}

void StringEnumNode::setSelectedOption(StringEnumNode* strEnum, int optionIndex) {
    if (optionIndex >= 0 && optionIndex < static_cast<int>(strEnum->m_options.size())) {
        strEnum->m_currentIndex = optionIndex;
        strEnum->m_selectedOption = strEnum->m_options[optionIndex];
        strEnum->m_settingLabel->setString(strEnum->m_selectedOption.c_str());
    }
}
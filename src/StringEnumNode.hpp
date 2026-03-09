#pragma once

#include <Geode/Geode.hpp>
#include <string>

using namespace geode::prelude;

class StringEnumNode : public CCMenu {
protected:
    bool init(const std::vector<std::string>& options) {
        if (!CCMenu::init() or options.empty()) {
            return false;
        }

        this->setContentSize({200,40});

        m_settingLabel = CCLabelBMFont::create(options[0].c_str(), "bigFont.fnt");
        m_settingLabel->setContentWidth(100);
        m_settingLabel->limitLabelWidth(100, 1.0f, 0.25f);
        this->addChild(m_settingLabel);
        m_settingLabel->updateAnchoredPosition(Anchor::Center);

        auto lSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
        lSpr->setFlipX(true);
        lSpr->setScale(0.5f);

        auto rSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
        rSpr->setScale(0.5f);

        m_leftButton = CCMenuItemSpriteExtra::create(
            lSpr,
            this,
            menu_selector(StringEnumNode::optionLeft)
        );

        m_rightButton = CCMenuItemSpriteExtra::create(
            rSpr,
            this,
            menu_selector(StringEnumNode::optionRight)
        );

        this->addChild(m_leftButton);
        this->addChild(m_rightButton);
        m_leftButton->updateAnchoredPosition(Anchor::Left, ccp(35,0));
        m_rightButton->updateAnchoredPosition(Anchor::Right, ccp(-35,0));

        m_options = options;
        m_currentIndex = 0;
        m_selectedOption = options[0];

        return true;
    }
public:
    int m_currentIndex;
    std::string m_selectedOption;
    std::vector<std::string> m_options;

    CCMenuItemSpriteExtra* m_leftButton;
    CCMenuItemSpriteExtra* m_rightButton;
    CCLabelBMFont* m_settingLabel;

    void optionLeft(CCObject* sender);
    void optionRight(CCObject* sender);

    static StringEnumNode* create(const std::vector<std::string>& options);

    static std::string getSelectedOption(StringEnumNode* strEnum);
    static int getSelectedOptionIndex(StringEnumNode* strEnum);
    static void setSelectedOption(StringEnumNode* strEnum, int optionIndex);
};
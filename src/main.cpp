#include <Geode/Geode.hpp>
#include "../include/StringEnumAPI.hpp"

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	struct Fields {
		StringEnumNode* m_strEnum;
	};

	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);

		myButton->setID("my-button"_spr);

		menu->updateLayout();

		m_fields->m_strEnum = myth::StringEnum::createStringEnum({"Option 1", "Option 2", "Option 3"});
		menu->addChild(m_fields->m_strEnum);
		m_fields->m_strEnum->updateAnchoredPosition(Anchor::Center);

		return true;
	}

	void onMyButton(CCObject*) {
		log::info("Selected option: {}", myth::StringEnum::getSelectedOption(m_fields->m_strEnum));
		log::info("Selected index: {}", myth::StringEnum::getSelectedOptionIndex(m_fields->m_strEnum));
	}
};
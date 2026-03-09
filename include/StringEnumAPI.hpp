#pragma once

#include "../src/StringEnumNode.hpp"

#ifdef GEODE_IS_WINDOWS
    #ifdef STRING_ENUM_API_EXPORTING
        #define STRING_ENUM_API_DLL __declspec(dllexport)
    #else
        #define STRING_ENUM_API_DLL __declspec(dllimport)
    #endif
#else
    #define STRING_ENUM_API_DLL __attribute__((visibility("default")))
#endif

namespace myth::StringEnum {
    STRING_ENUM_API_DLL StringEnumNode* createStringEnum(const std::vector<std::string>& options);

    STRING_ENUM_API_DLL std::string getSelectedOption(StringEnumNode* strEnum);
    STRING_ENUM_API_DLL int getSelectedOptionIndex(StringEnumNode* strEnum);
    STRING_ENUM_API_DLL void setSelectedOption(StringEnumNode* strEnum, int optionIndex);
}
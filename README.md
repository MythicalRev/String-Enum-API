# StringEnumAPI

Allows you to create a String Enum Selector in your own UI.

## How to Use?

### Import API
    #include <mythicalrev.string-enum-api/include/StringEnumAPI.hpp>

### Creating a Node
Usage: 
    StringEnumNode* createStringEnum(const std::vector<std::string>& options);
Example:
    auto enumNode = createStringEnum({"Option 1", "Option 2"});

### Getting Node Data
#### Get Option String
Usage: 
    std::string getSelectedOption(StringEnumNode* strEnum);
Example:
    auto enumNode = createStringEnum({"Option 1", "Option 2"});
    auto selectedString = getSelectedOption(enumNode);

#### Get Option Index
Usage: 
    int getSelectedOptionIndex(StringEnumNode* strEnum);
Example:
    auto enumNode = createStringEnum({"Option 1", "Option 2"});
    auto selectedIndex = getSelectedOption(enumNode);

### Setting Node Data
Usage: 
    void setSelectedOption(StringEnumNode* strEnum, int optionIndex);
Example:
    auto enumNode = createStringEnum({"Option 1", "Option 2"});
    setSelectedOption(enumNode, 1);

## Credits

##### Mod Logo

-  DominoKiddoo
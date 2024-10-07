/*
Copyright (c) 2024 i-am-shodan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <functional>
#include <string>
#include <vector>
#include <stack>

#include "Logging.h"

class USBKeyDefinition
{
public:
    enum class UsbHidModifiers : uint8_t
    {
        None = 0,
        LeftControl = 0x01,
        LeftShift = 0x02,
        LeftAlt = 0x04,
        LeftGui = 0x08,
        RightControl = 0x10,
        RightShift = 0x20,
        RightAlt = 0x40,
        RightGui = 0x80,
        INVALID = 0xFF
    };

    UsbHidModifiers modifier = UsbHidModifiers::INVALID;
    uint8_t hidCode = 0;

    USBKeyDefinition(UsbHidModifiers mod, uint8_t code)
    {
        this->modifier = mod;
        this->hidCode = code;
    }

    USBKeyDefinition(uint8_t code)
    {
        this->hidCode = code;
        this->modifier = UsbHidModifiers::None;
    }

    USBKeyDefinition(UsbHidModifiers mod)
    {
        this->hidCode = 0;
        this->modifier = mod;
    }

    USBKeyDefinition()
    {
        // invalid
    }

    bool isValid()
    {
        return modifier != UsbHidModifiers::INVALID;
    }
};

/// @brief Class for handling the implementation of Duck Script parsing
class DuckyInterpreter
{
public:
    static const int16_t SCRIPT_ERROR = -2;
    static const int16_t END_OF_FILE = -1;

    enum class USB_MODE : uint8_t
    {
        OFF = 0,
        HID = 1,
        STORAGE = 2,
    };

    enum class DuckyScriptOperator : uint8_t
    {
        EQ,
        NE,
        GT,
        GTE,
        LT,
        LTE,
        ASSIGN,
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        MOD,
    };

    /// @brief Helper function to split a string by DuckScript delimiters
    /// @param input
    /// @return vector of tokens
    std::vector<std::string> splitString(const std::string &input);

private:
    std::function<void(uint32_t)> _delayFunc;
    std::function<std::string(const std::string &, int)> _readLineFunc;
    std::function<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)> _keyboardPressFunc;
    std::function<void()> _keyboardReleaseFunc;
    std::function<void(bool, uint8_t, uint8_t, uint8_t, uint8_t)> _changeLEDStateFunc;
    std::function<void()> _waitForButtonPressFunc;
    std::function<void(DuckyInterpreter::USB_MODE &, const uint16_t &, const uint16_t &, const std::string &, const std::string &, const std::string &)> _changeModeFunc;
    std::function<void()> _reset;
    std::unordered_map<std::string, std::function<bool(std::string)>> _commandMap;
    std::unordered_map<std::string, std::string> _constants;
    std::unordered_map<std::string, int> _variables;
    std::stack<int> _whileLoopLineNumbers;
    std::string keyboardLayout;

    USBKeyDefinition getUSBKeyDefinition(const std::string &);
    bool performKeyPressesForList(const std::vector<std::pair<bool, uint8_t>> &);
    int handleIF(const std::string &, int, std::string &, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &);
    int handleWHILE(const std::string &, int, std::string &, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &);
    bool evaluateStatement(std::string &, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &, bool *condition);
    std::vector<std::tuple<std::string, DuckyScriptOperator, std::string>> parseCondition(std::string &condition);
    int evaluate(std::string &str, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands);
    inline std::tuple<std::string, DuckyInterpreter::DuckyScriptOperator, std::string> parseStatement(std::string statement);
    int skipLineUntilCondition(const std::string &filePath, int lineNumber, const std::vector<std::string> &nestingConditions, const std::vector<std::string> &endConditions, const std::vector<std::string> &matchingConditions, int nestingCount = 0);
    bool assignToVariable(const std::string &variableName, std::string &args, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands);

public:
    DuckyInterpreter(
        std::function<void(uint32_t)> delayFunc,
        std::function<std::string(const std::string &, int)> readLineFunc,
        std::function<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)> keyboardPressFunc,
        std::function<void()> keyboardReleaseFunc,
        std::function<void(bool, uint8_t, uint8_t, uint8_t, uint8_t)> changeLEDStateFunc,
        std::function<void()> waitForButtonPressFunc,
        std::function<void(DuckyInterpreter::USB_MODE &, const uint16_t &, const uint16_t &, const std::string &, const std::string &, const std::string &)> changeModeFunc,
        std::function<void()> reset);

    int Execute(const std::string &filePath, 
                int lineNumber, 
                std::unordered_map<std::string, 
                std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands, 
                std::vector<std::function<std::pair<std::string, std::string>()>> &userDefinedConstValues);

    bool SetKeyboardLayout(const std::string& layout);
};

inline DuckyInterpreter::USB_MODE operator|(DuckyInterpreter::USB_MODE a, DuckyInterpreter::USB_MODE b)
{
    return static_cast<DuckyInterpreter::USB_MODE>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

inline bool operator&(DuckyInterpreter::USB_MODE a, DuckyInterpreter::USB_MODE b)
{
    return static_cast<uint8_t>(a) & static_cast<uint8_t>(b);
}

namespace Ducky
{
    // Function to split a string into words
    static std::vector<std::string> SplitString(const std::string &input)
    {
        std::vector<std::string> words;
        std::string word;

        for (char c : input)
        {
            if (std::isspace(c))
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word += c;
            }
        }

        if (!word.empty())
        {
            words.push_back(word);
        }

        return words;
    }
}
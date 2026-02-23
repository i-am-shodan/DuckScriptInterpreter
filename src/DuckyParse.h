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
#include <algorithm>

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
        ShiftAltGr = 0x42,
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

typedef int DuckyReturn;
typedef std::function<int(const std::string &, const std::unordered_map<std::string, std::string> &, const std::unordered_map<std::string, std::string> &)> ExtensionCommand;
typedef std::unordered_map<std::string, ExtensionCommand> ExtensionCommands;
typedef std::vector<std::function<std::pair<std::string, std::string>()>> UserDefinedConstants;
typedef std::function<DuckyReturn(const std::string &, const std::string &, const ExtensionCommands &, const UserDefinedConstants &)> StatementHandler;

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
    struct EvaluationResult
    {
        bool error = true;
        bool requiresScriptEvaluation = false;
        std::string evaluationResult;
        std::string functionName;
    };

    struct CallStackItem
    {
        bool error = false;
        int returnLineNumber = -1;
        std::string functionName;
    };

    std::function<void(uint32_t)> _delayFunc;
    std::function<std::string(const std::string &, int)> _readLineFunc;
    std::function<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)> _keyboardPressFunc;
    std::function<void()> _keyboardReleaseFunc;
    std::function<void(bool, uint8_t, uint8_t, uint8_t, uint8_t)> _changeLEDStateFunc;
    std::function<void()> _waitForButtonPressFunc;
    std::function<void(DuckyInterpreter::USB_MODE &, const uint16_t &, const uint16_t &, const std::string &, const std::string &, const std::string &)> _changeModeFunc;
    std::function<void()> _reset;

    std::unordered_map<std::string, StatementHandler> _statementHandlers;
    std::unordered_map<std::string, std::string> _constants;
    std::unordered_map<std::string, std::string> _variables;
    std::stack<int> _whileLoopLineNumbers;
    std::string _keyboardLayout;
    std::unordered_map<std::string, int> _funcLookup;
    std::stack<CallStackItem> _callstack;
    std::stack<std::pair<int, int>> _linesToIgnore;
    int _lineNumber;
    std::string currentlyExecutingFile;

    USBKeyDefinition getUSBKeyDefinition(const std::string &);
    bool performKeyPressesForList(const std::vector<std::pair<bool, uint8_t>> &);
    int handleIF(const std::string &filePath, const int &lineNumber, const std::string &line, const ExtensionCommands &extCommands, const UserDefinedConstants &userDefinedConstValues);
    int handleWHILE(const std::string &filePath, const int &lineNumber, const std::string &line, const ExtensionCommands &extCommands, const UserDefinedConstants &userDefinedConstValues);
    int handleFUNCTION(const std::string &filePath, const int &lineNumber, const std::string &line, const ExtensionCommands &extCommands, const UserDefinedConstants &userDefinedConstValues);
    CallStackItem evaluateStatement(const std::string &line, const int &lineNumber, const ExtensionCommands &extCommands, bool *conditionToCheck);
    std::vector<std::tuple<std::string, DuckyScriptOperator, std::string>> parseCondition(std::string &condition);
    EvaluationResult evaluate(std::string &str, const ExtensionCommands &extCommands);
    inline std::tuple<std::string, DuckyInterpreter::DuckyScriptOperator, std::string> parseStatement(std::string statement);
    int skipLineUntilCondition(const std::string &filePath, int lineNumber, const UserDefinedConstants &userDefinedConstValues, const std::vector<std::string> &nestingConditions, const std::vector<std::string> &endConditions, const std::vector<std::string> &matchingConditions, const std::vector<std::string> &errorConditions, int nestingCount = 0, const StatementHandler func = nullptr);
    bool assignToVariable(const std::string &variableName, std::string &arg, const ExtensionCommands &extCommands);
    std::string evaluateExpression(const std::string &line);
    int pushCallStack(const CallStackItem &item);
    int getLineAndProcess(const std::string &filePath, const int &lineNum, const UserDefinedConstants &userDefinedConstValues, std::string &line);
    void replaceVariablesInLine(std::string &line, bool dequoteStrValues);

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
                const ExtensionCommands &extCommands,
                const UserDefinedConstants &userDefinedConstValues);

    bool SetKeyboardLayout(const std::string &layout);

    void Restart()
    {
        _lineNumber = 0;

        while (!_whileLoopLineNumbers.empty())
        {
            _whileLoopLineNumbers.pop();
        }

        while (!_callstack.empty())
        {
            _callstack.pop();
        }

        while (!_linesToIgnore.empty())
        {
            _linesToIgnore.pop();
        }
    }

    void AddOrUpdateVariable(const std::string &name, const std::string& value)
    {
        _variables[name] = value;
    }
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
    static std::vector<std::string> SplitString(const std::string &input)
    {
        std::vector<std::string> words;
        std::string word;
        bool inQuotes = false;

        for (size_t i = 0; i < input.size(); ++i)
        {
            const char c = input[i];

            if (c == '"')
            {
                if (inQuotes)
                {
                    // Closing quote: push whatever we accumulated (even if empty)
                    words.push_back("\"" + word + "\"");
                    word.clear();
                    inQuotes = false;
                }
                else
                {
                    // Opening quote: if we had been accumulating an unquoted word, push it first
                    if (!word.empty())
                    {
                        words.push_back(word);
                        word.clear();
                    }
                    inQuotes = true;
                }
            }
            else if (std::isspace(c) && !inQuotes)
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

        // If we ended while still inside quotes, that's an error
        if (inQuotes)
        {
            return {};
        }

        if (!word.empty())
        {
            words.push_back(word);
        }

        return words;
    }

    static std::string lowerCaseString(const std::string &str)
    {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });
        return result;
    }

    static std::string replaceString(std::string subject, const std::string &search, const std::string &replace)
    {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != std::string::npos)
        {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
        return subject;
    }

    static std::string replaceAllOccurrences(const std::string &subject, const std::string &search, const std::string &replace)
    {
        std::string result = subject;
        size_t pos = 0;

        while ((pos = result.find(search, pos)) != std::string::npos)
        {
            result.replace(pos, search.length(), replace);
            pos += replace.length();
        }

        return result;
    }

    static void replaceAllOccurrences(std::string &str, const char from, const char to)
    {
        size_t pos = 0;
        while ((pos = str.find(from, pos)) != std::string::npos)
        {
            str.replace(pos, 1, 1, to);
            ++pos; // Move to the next position
        }
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                             { return !std::isspace(ch); })
                    .base(),
                s.end());
    }

    static inline void ltrim(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                        { return !std::isspace(ch); }));
    }

    static std::pair<std::string, std::string> extractFirstWord(const std::string &input)
    {
        // Find the position of the first space
        const size_t spacePos = input.find(' ');

        if (spacePos != std::string::npos)
        {
            // Extract the first word
            const std::string firstWord = input.substr(0, spacePos);

            // Get the remainder of the string (excluding the first word)
            std::string remainder = input.substr(spacePos + 1);
            rtrim(remainder);

            return {firstWord, remainder};
        }
        else
        {
            // If no space found, the entire input is the first word
            return {input, ""};
        }
    }

    static bool isStringDigits(const std::string &str)
    {
        for (char c : str)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }

}
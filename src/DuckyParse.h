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
        enum class UsbHidModifiers : uint8_t {
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
class DuckyInterpreter {  
    public:
        static const int16_t SCRIPT_ERROR = -2;
        static const int16_t END_OF_FILE = -1;

        static constexpr const char* UP = "UP";  
        static constexpr const char* DOWN = "DOWN";  
        static constexpr const char* LEFT = "LEFT";  
        static constexpr const char* RIGHT = "RIGHT";  
        static constexpr const char* UPARROW = "UPARROW";  
        static constexpr const char* DOWNARROW = "DOWNARROW";  
        static constexpr const char* LEFTARROW = "LEFTARROW";  
        static constexpr const char* RIGHTARROW = "RIGHTARROW";  
        static constexpr const char* PAGEUP = "PAGEUP";  
        static constexpr const char* PAGEDOWN = "PAGEDOWN";  
        static constexpr const char* HOME = "HOME";  
        static constexpr const char* END = "END";  
        static constexpr const char* INSERT = "INSERT";  
        static constexpr const char* DELETE = "DELETE";  
        static constexpr const char* DEL = "DEL";  
        static constexpr const char* BACKSPACE = "BACKSPACE";  
        static constexpr const char* TAB = "TAB";  
        static constexpr const char* SPACE = "SPACE";  
        static constexpr const char* ENTER = "ENTER";  
        static constexpr const char* ESCAPE = "ESCAPE";  
        static constexpr const char* PAUSE = "PAUSE";  
        static constexpr const char* BREAK = "BREAK";  
        static constexpr const char* PRINTSCREEN = "PRINTSCREEN";  
        static constexpr const char* MENU_APP = "MENU APP";  
        static constexpr const char* F1 = "F1";  
        static constexpr const char* F2 = "F2";  
        static constexpr const char* F3 = "F3";  
        static constexpr const char* F4 = "F4";  
        static constexpr const char* F5 = "F5";  
        static constexpr const char* F6 = "F6";  
        static constexpr const char* F7 = "F7";  
        static constexpr const char* F8 = "F8";  
        static constexpr const char* F9 = "F9";  
        static constexpr const char* F10 = "F10";  
        static constexpr const char* F11 = "F11";  
        static constexpr const char* F12 = "F12";  
        static constexpr const char* SHIFT = "SHIFT";  
        static constexpr const char* ALT = "ALT";  
        static constexpr const char* CONTROL = "CONTROL";  
        static constexpr const char* CTRL = "CTRL";  
        static constexpr const char* COMMAND = "COMMAND";  
        static constexpr const char* WINDOWS = "WINDOWS";  
        static constexpr const char* GUI = "GUI";  
        static constexpr const char* CAPSLOCK = "CAPSLOCK";  
        static constexpr const char* NUMLOCK = "NUMLOCK";  
        static constexpr const char* SCROLLOCK = "SCROLLOCK";

        static constexpr const uint8_t SHIFT_KEY = 0xe1;

        enum class USB_MODE : uint8_t {
            OFF             = 0,
            HID             = 1,
            STORAGE         = 2,
        };

        /// @brief Helper function to split a string by DuckScript delimiters
        /// @param input 
        /// @return vector of tokens
        std::vector<std::string> splitString(const std::string& input);

    private:
        std::function<void(uint32_t)> _delayFunc;  
        std::function<std::string(const std::string&, int)> _readLineFunc;  
        std::function<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)> _keyboardPressFunc;  
        std::function<void()> _keyboardReleaseFunc;  
        std::function<void(bool, uint8_t, uint8_t, uint8_t, uint8_t)> _changeLEDStateFunc;  
        std::function<void()> _waitForButtonPressFunc;  
        std::function<void(DuckyInterpreter::USB_MODE&, const uint16_t&, const uint16_t&, const std::string&, const std::string&, const std::string&)> _changeModeFunc;
        std::function<void()> _reset;
        std::unordered_map<std::string, std::function<bool(std::string)>> _commandMap;
        std::unordered_map<std::string, std::string> _constants;
        std::unordered_map<std::string, int> _variables;
        std::stack<int> _whileLoopLineNumbers;

        std::unordered_map<std::string, USBKeyDefinition> keyLookupTable = {
            {"a", USBKeyDefinition(0x04) },
            {"A", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x04) },
            {"b", USBKeyDefinition(0x05) },
            {"B", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x05) },
            {"c", USBKeyDefinition(0x06) }, 
            {"C", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x06) },
            {"d", USBKeyDefinition(0x07) }, 
            {"D", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x07) },
            {"e", USBKeyDefinition(0x08) }, 
            {"E", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x08) },
            {"f", USBKeyDefinition(0x09) },   
            {"F", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x09) },
            {"g", USBKeyDefinition(0x0a) },
            {"G", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0a) },
            {"h", USBKeyDefinition(0x0b) }, 
            {"H", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0b) },
            {"i", USBKeyDefinition(0x0c) }, 
            {"I", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0c) },
            {"j", USBKeyDefinition(0x0d) }, 
            {"J", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0d) },
            {"k", USBKeyDefinition(0x0e) }, 
            {"K", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0e) },
            {"l", USBKeyDefinition(0x0f) },   
            {"L", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0f) },
            {"m", USBKeyDefinition(0x10) }, 
            {"M", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x10) },
            {"n", USBKeyDefinition(0x11) }, 
            {"N", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x11) },
            {"o", USBKeyDefinition(0x12) }, 
            {"O", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x12) },
            {"p", USBKeyDefinition(0x13) }, 
            {"P", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x13) },
            {"q", USBKeyDefinition(0x14) }, 
            {"Q", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x14) },
            {"r", USBKeyDefinition(0x15) },
            {"R", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x15) },
            {"s", USBKeyDefinition(0x16) }, 
            {"S", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x16) },
            {"t", USBKeyDefinition(0x17) }, 
            {"T", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x17) },
            {"u", USBKeyDefinition(0x18) }, 
            {"U", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x18) },
            {"v", USBKeyDefinition(0x19) }, 
            {"V", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x19) },
            {"w", USBKeyDefinition(0x1a) }, 
            {"W", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1a) },
            {"x", USBKeyDefinition(0x1b) },   
            {"X", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1b) },
            {"y", USBKeyDefinition(0x1c) }, 
            {"Y", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1c) },
            {"z", USBKeyDefinition(0x1d) }, 
            {"Z", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1d) },

            {"1", USBKeyDefinition(0x1e) }, 
            {"2", USBKeyDefinition(0x1f) }, 
            {"3", USBKeyDefinition(0x20) },   
            {"4", USBKeyDefinition(0x21) }, 
            {"5", USBKeyDefinition(0x22) }, 
            {"6", USBKeyDefinition(0x23) }, 
            {"7", USBKeyDefinition(0x24) }, 
            {"8", USBKeyDefinition(0x25) }, 
            {"9", USBKeyDefinition(0x26) },
            {"0", USBKeyDefinition(0x27) }, 
            {"-", USBKeyDefinition(0x2d) }, 
            {"=", USBKeyDefinition(0x2e) }, 

            {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e) }, 
            {"\"",USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f) }, 
            {"£", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20) },   
            {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21) }, 
            {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22) }, 
            {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23) }, 
            {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24) }, 
            {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25) }, 
            {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26) },
            {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27) },
            {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d) }, 
            {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e) }, 

            {"[", USBKeyDefinition(0x27) },
            {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f ) },
            {"]", USBKeyDefinition(0x30) },
            {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30 ) },
            {"\\", USBKeyDefinition(0x31) },
            {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31 ) },

            {";", USBKeyDefinition(0x33) },
            {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33 ) },
            {"'", USBKeyDefinition(0x34) },
            {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34 ) }, // UK

            {"#", USBKeyDefinition(0x33) }, // TODO
            {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33 ) }, // TODO

            {",", USBKeyDefinition(0x36) },
            {"<", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36 ) },
            {".", USBKeyDefinition(0x37) },
            {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37 ) },
            {"/", USBKeyDefinition(0x38) },
            {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38 ) },

            {" ", USBKeyDefinition(0x2c) },
            {DuckyInterpreter::SPACE, USBKeyDefinition(0x2c) },
            {DuckyInterpreter::BACKSPACE, USBKeyDefinition(0x2a) },
            {DuckyInterpreter::TAB, USBKeyDefinition(0x2b) },
            {DuckyInterpreter::ENTER, USBKeyDefinition(0x28) },   
            {DuckyInterpreter::CTRL, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftControl) },
            {DuckyInterpreter::CONTROL, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftControl) },
            {DuckyInterpreter::ALT, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftAlt) },
            {DuckyInterpreter::SHIFT, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift) },
            {DuckyInterpreter::DEL, USBKeyDefinition(0x4c) },
            {DuckyInterpreter::F1, USBKeyDefinition(0x3a) },
            {DuckyInterpreter::F2, USBKeyDefinition(0x3b) },
            {DuckyInterpreter::F3, USBKeyDefinition(0x3c) },
            {DuckyInterpreter::F4, USBKeyDefinition(0x3d) },
            {DuckyInterpreter::F5, USBKeyDefinition(0x3e) },
            {DuckyInterpreter::F6, USBKeyDefinition(0x3f) }, 
            {DuckyInterpreter::F7, USBKeyDefinition(0x40) },
            {DuckyInterpreter::F8, USBKeyDefinition(0x41) },
            {DuckyInterpreter::F9, USBKeyDefinition(0x42) },
            {DuckyInterpreter::F10, USBKeyDefinition(0x43) },
            {DuckyInterpreter::F11, USBKeyDefinition(0x44) },
            {DuckyInterpreter::F12, USBKeyDefinition(0x45) },   
            {DuckyInterpreter::RIGHT, USBKeyDefinition(0x4e) },
            {DuckyInterpreter::LEFT, USBKeyDefinition(0x4f) },
            {DuckyInterpreter::DOWN, USBKeyDefinition(0x50) },
            {DuckyInterpreter::UP, USBKeyDefinition(0x51) },
            {DuckyInterpreter::GUI, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftGui) },
            {DuckyInterpreter::END, USBKeyDefinition(0x4d) }
        };

        std::vector<const char *> systemKeys =
        {
            DuckyInterpreter::UP, 
            DuckyInterpreter::DOWN, 
            DuckyInterpreter::LEFT, 
            DuckyInterpreter::RIGHT, 
            DuckyInterpreter::UPARROW, 
            DuckyInterpreter::DOWNARROW, 
            DuckyInterpreter::LEFTARROW, 
            DuckyInterpreter::RIGHTARROW, 
            DuckyInterpreter::PAGEUP, 
            DuckyInterpreter::PAGEDOWN, 
            DuckyInterpreter::HOME, 
            DuckyInterpreter::END, 
            DuckyInterpreter::INSERT, 
            DuckyInterpreter::DELETE, 
            DuckyInterpreter::DEL, 
            DuckyInterpreter::BACKSPACE, 
            DuckyInterpreter::TAB, 
            DuckyInterpreter::SPACE, 
            DuckyInterpreter::ENTER, 
            DuckyInterpreter::ESCAPE, 
            DuckyInterpreter::PAUSE, 
            DuckyInterpreter::BREAK, 
            DuckyInterpreter::PRINTSCREEN, 
            DuckyInterpreter::MENU_APP, 
            DuckyInterpreter::F1, 
            DuckyInterpreter::F2, 
            DuckyInterpreter::F3, 
            DuckyInterpreter::F4, 
            DuckyInterpreter::F5, 
            DuckyInterpreter::F6, 
            DuckyInterpreter::F7, 
            DuckyInterpreter::F8, 
            DuckyInterpreter::F9, 
            DuckyInterpreter::F10, 
            DuckyInterpreter::F11, 
            DuckyInterpreter::F12, 
            DuckyInterpreter::SHIFT, 
            DuckyInterpreter::ALT, 
            DuckyInterpreter::CONTROL, 
            DuckyInterpreter::CTRL, 
            DuckyInterpreter::COMMAND, 
            DuckyInterpreter::WINDOWS, 
            DuckyInterpreter::GUI, 
            DuckyInterpreter::CAPSLOCK, 
            DuckyInterpreter::NUMLOCK, 
            DuckyInterpreter::SCROLLOCK
        };

        enum class DuckyScriptOperator : uint8_t {
            EQ,
            NE,
            GT,
            GTE,
            LT,
            LTE,
        };

        std::unordered_map<std::string, DuckyScriptOperator> operatorMap = {  
            {"==", DuckyScriptOperator::EQ},
            {"!=", DuckyScriptOperator::NE},
            {">", DuckyScriptOperator::GT},
            {">=", DuckyScriptOperator::GTE},
            {"<", DuckyScriptOperator::LT},
            {"<=", DuckyScriptOperator::LTE},
        };

        USBKeyDefinition getUSBKeyDefinition(const std::string&);
        bool performKeyPressesForList(const std::vector<std::pair<bool, uint8_t>>&);
        int handleIF(const std::string&, int, std::string&, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>>&);
        int handleWHILE(const std::string &, int , std::string& , std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &);
        bool evaluateStatement(std::string&, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &);
        std::vector<std::tuple<std::string, DuckyScriptOperator, std::string>> parseCondition(std::string &condition);
        int evaluate(const std::string &str, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands);
        inline std::tuple<std::string, DuckyInterpreter::DuckyScriptOperator, std::string> parseStatement(std::string statement);
  
    public:  
        DuckyInterpreter(
                     std::function<void(uint32_t)> delayFunc,
                     std::function<std::string(const std::string&, int)> readLineFunc,
                     std::function<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)> keyboardPressFunc,
                     std::function<void()> keyboardReleaseFunc,
                     std::function<void(bool, uint8_t, uint8_t, uint8_t, uint8_t)> changeLEDStateFunc,
                     std::function<void()> waitForButtonPressFunc,
                     std::function<void(DuckyInterpreter::USB_MODE&, const uint16_t&, const uint16_t&, const std::string&, const std::string&, const std::string&)> changeModeFunc,
                     std::function<void()> reset
                     );
  
        int Execute(const std::string& filePath, int lineNumber, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>>& extCommands, std::vector<std::function<std::pair<std::string, std::string>()>>& userDefinedConstValues);
};  

inline DuckyInterpreter::USB_MODE operator|(DuckyInterpreter::USB_MODE a, DuckyInterpreter::USB_MODE b) {
    return static_cast<DuckyInterpreter::USB_MODE>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

inline bool operator&(DuckyInterpreter::USB_MODE a, DuckyInterpreter::USB_MODE b) {
    return static_cast<uint8_t>(a) & static_cast<uint8_t>(b);
}
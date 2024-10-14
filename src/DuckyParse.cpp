/*
Copyright (c) 2024 i-am-shodan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

// TODO
// INJECT_MOD WINDOWS - Injecting a modifier key alone without another key
// BUTTON_DEF - function when button is pressed
// DISABLE_BUTTON
// ENABLE_BUTTON
// RANDOM...
// HOLD RELEASE
// STOP_PAYLOAD
// JITTER
// WAIT_FOR_CAPS_ON etc
// SAVE_HOST_KEYBOARD_LOCK_STATE
// make faster by holding multiple keys

#include "DuckyParse.h"

#include <algorithm>

using namespace std;
using namespace Ducky;

static const int16_t SCRIPT_ERROR = -2;
static const int16_t END_OF_FILE = -1;

static constexpr const char *UP = "UP";
static constexpr const char *DOWN = "DOWN";
static constexpr const char *LEFT = "LEFT";
static constexpr const char *RIGHT = "RIGHT";
static constexpr const char *UPARROW = "UPARROW";
static constexpr const char *DOWNARROW = "DOWNARROW";
static constexpr const char *LEFTARROW = "LEFTARROW";
static constexpr const char *RIGHTARROW = "RIGHTARROW";
static constexpr const char *PAGEUP = "PAGEUP";
static constexpr const char *PAGEDOWN = "PAGEDOWN";
static constexpr const char *HOME = "HOME";
static constexpr const char *END = "END";
static constexpr const char *INSERT = "INSERT";
static constexpr const char *DELETE = "DELETE";
static constexpr const char *DEL = "DEL";
static constexpr const char *BACKSPACE = "BACKSPACE";
static constexpr const char *TAB = "TAB";
static constexpr const char *SPACE = "SPACE";
static constexpr const char *ENTER = "ENTER";
static constexpr const char *ESCAPE = "ESCAPE";
static constexpr const char *PAUSE = "PAUSE";
static constexpr const char *BREAK = "BREAK";
static constexpr const char *PRINTSCREEN = "PRINTSCREEN";
static constexpr const char *MENU_APP = "MENU APP";
static constexpr const char *F1 = "F1";
static constexpr const char *F2 = "F2";
static constexpr const char *F3 = "F3";
static constexpr const char *F4 = "F4";
static constexpr const char *F5 = "F5";
static constexpr const char *F6 = "F6";
static constexpr const char *F7 = "F7";
static constexpr const char *F8 = "F8";
static constexpr const char *F9 = "F9";
static constexpr const char *F10 = "F10";
static constexpr const char *F11 = "F11";
static constexpr const char *F12 = "F12";
static constexpr const char *SHIFT = "SHIFT";
static constexpr const char *ALT = "ALT";
static constexpr const char *CONTROL = "CONTROL";
static constexpr const char *CTRL = "CTRL";
static constexpr const char *COMMAND = "COMMAND";
static constexpr const char *WINDOWS = "WINDOWS";
static constexpr const char *GUI = "GUI";
static constexpr const char *CAPSLOCK = "CAPSLOCK";
static constexpr const char *NUMLOCK = "NUMLOCK";
static constexpr const char *SCROLLOCK = "SCROLLOCK";
static constexpr const uint8_t SHIFT_KEY = 0xe1;

static const std::string prefixIF = "IF ";
static const std::string prefixEND_IF = "END_IF";
static const std::string prefixELSE_IF = "ELSE IF ";
static const std::string prefixELSE = "ELSE";
static const std::string PrefixWHILE = "WHILE ";
static const std::string EndWHILE = "END_WHILE";
static const std::string THENSuffix = " THEN";
static const std::string RestartPayload = "RESTART_PAYLOAD";

static std::unordered_map<std::string, USBKeyDefinition> keyLookupTable = {
    {"a", USBKeyDefinition(0x04)},
    {"A", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x04)},
    {"b", USBKeyDefinition(0x05)},
    {"B", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x05)},
    {"c", USBKeyDefinition(0x06)},
    {"C", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x06)},
    {"d", USBKeyDefinition(0x07)},
    {"D", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x07)},
    {"e", USBKeyDefinition(0x08)},
    {"E", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x08)},
    {"f", USBKeyDefinition(0x09)},
    {"F", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x09)},
    {"g", USBKeyDefinition(0x0a)},
    {"G", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0a)},
    {"h", USBKeyDefinition(0x0b)},
    {"H", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0b)},
    {"i", USBKeyDefinition(0x0c)},
    {"I", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0c)},
    {"j", USBKeyDefinition(0x0d)},
    {"J", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0d)},
    {"k", USBKeyDefinition(0x0e)},
    {"K", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0e)},
    {"l", USBKeyDefinition(0x0f)},
    {"L", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0f)},
    {"m", USBKeyDefinition(0x10)},
    {"M", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x10)},
    {"n", USBKeyDefinition(0x11)},
    {"N", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x11)},
    {"o", USBKeyDefinition(0x12)},
    {"O", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x12)},
    {"p", USBKeyDefinition(0x13)},
    {"P", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x13)},
    {"q", USBKeyDefinition(0x14)},
    {"Q", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x14)},
    {"r", USBKeyDefinition(0x15)},
    {"R", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x15)},
    {"s", USBKeyDefinition(0x16)},
    {"S", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x16)},
    {"t", USBKeyDefinition(0x17)},
    {"T", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x17)},
    {"u", USBKeyDefinition(0x18)},
    {"U", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x18)},
    {"v", USBKeyDefinition(0x19)},
    {"V", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x19)},
    {"w", USBKeyDefinition(0x1a)},
    {"W", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1a)},
    {"x", USBKeyDefinition(0x1b)},
    {"X", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1b)},
    {"y", USBKeyDefinition(0x1c)},
    {"Y", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1c)},
    {"z", USBKeyDefinition(0x1d)},
    {"Z", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1d)},

    {"1", USBKeyDefinition(0x1e)},
    {"2", USBKeyDefinition(0x1f)},
    {"3", USBKeyDefinition(0x20)},
    {"4", USBKeyDefinition(0x21)},
    {"5", USBKeyDefinition(0x22)},
    {"6", USBKeyDefinition(0x23)},
    {"7", USBKeyDefinition(0x24)},
    {"8", USBKeyDefinition(0x25)},
    {"9", USBKeyDefinition(0x26)},
    {"0", USBKeyDefinition(0x27)},
    {"-", USBKeyDefinition(0x2d)},
    {"=", USBKeyDefinition(0x2e)},

    {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
    {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
    {"£", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
    {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
    {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
    {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
    {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
    {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
    {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
    {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
    {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
    {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},

    {"[", USBKeyDefinition(0x27)},
    {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
    {"]", USBKeyDefinition(0x30)},
    {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
    {"\\", USBKeyDefinition(0x31)},
    {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},

    {";", USBKeyDefinition(0x33)},
    {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
    {"'", USBKeyDefinition(0x34)},
    {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)}, // UK

    {"#", USBKeyDefinition(0x33)},                                               // TODO
    {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)}, // TODO

    {",", USBKeyDefinition(0x36)},
    {"<", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
    {".", USBKeyDefinition(0x37)},
    {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
    {"/", USBKeyDefinition(0x38)},
    {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},

    {" ", USBKeyDefinition(0x2c)},
    {SPACE, USBKeyDefinition(0x2c)},
    {BACKSPACE, USBKeyDefinition(0x2a)},
    {TAB, USBKeyDefinition(0x2b)},
    {ENTER, USBKeyDefinition(0x28)},
    {CTRL, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftControl)},
    {CONTROL, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftControl)},
    {ALT, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftAlt)},
    {SHIFT, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift)},
    {DEL, USBKeyDefinition(0x4c)},
    {F1, USBKeyDefinition(0x3a)},
    {F2, USBKeyDefinition(0x3b)},
    {F3, USBKeyDefinition(0x3c)},
    {F4, USBKeyDefinition(0x3d)},
    {F5, USBKeyDefinition(0x3e)},
    {F6, USBKeyDefinition(0x3f)},
    {F7, USBKeyDefinition(0x40)},
    {F8, USBKeyDefinition(0x41)},
    {F9, USBKeyDefinition(0x42)},
    {F10, USBKeyDefinition(0x43)},
    {F11, USBKeyDefinition(0x44)},
    {F12, USBKeyDefinition(0x45)},
    {RIGHT, USBKeyDefinition(0x4e)},
    {LEFT, USBKeyDefinition(0x4f)},
    {DOWN, USBKeyDefinition(0x50)},
    {UP, USBKeyDefinition(0x51)},
    {GUI, USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftGui)},
    {END, USBKeyDefinition(0x4d)}};

static std::vector<const char *> systemKeys =
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        UPARROW,
        DOWNARROW,
        LEFTARROW,
        RIGHTARROW,
        PAGEUP,
        PAGEDOWN,
        HOME,
        END,
        INSERT,
        DELETE,
        DEL,
        BACKSPACE,
        TAB,
        SPACE,
        ENTER,
        ESCAPE,
        PAUSE,
        BREAK,
        PRINTSCREEN,
        MENU_APP,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        SHIFT,
        ALT,
        CONTROL,
        CTRL,
        COMMAND,
        WINDOWS,
        GUI,
        CAPSLOCK,
        NUMLOCK,
        SCROLLOCK};

static std::unordered_map<std::string, DuckyInterpreter::DuckyScriptOperator> operatorMap = {
    {"==", DuckyInterpreter::DuckyScriptOperator::EQ},
    {"!=", DuckyInterpreter::DuckyScriptOperator::NE},
    {">", DuckyInterpreter::DuckyScriptOperator::GT},
    {">=", DuckyInterpreter::DuckyScriptOperator::GTE},
    {"<", DuckyInterpreter::DuckyScriptOperator::LT},
    {"<=", DuckyInterpreter::DuckyScriptOperator::LTE},
    {"=", DuckyInterpreter::DuckyScriptOperator::ASSIGN},
    {"+", DuckyInterpreter::DuckyScriptOperator::ADD},
    {"-", DuckyInterpreter::DuckyScriptOperator::SUBTRACT},
    {"*", DuckyInterpreter::DuckyScriptOperator::MULTIPLY},
    {"/", DuckyInterpreter::DuckyScriptOperator::DIVIDE},
    {"%", DuckyInterpreter::DuckyScriptOperator::MOD}};

static std::unordered_map<std::string, std::unordered_map<std::string, USBKeyDefinition>> langLookupTable = {
    #include "locales/win_be.h"
    #include "locales/win_ca-FR.h"
    #include "locales/win_ca.h"
    #include "locales/win_ch.h"
    #include "locales/win_cs-CZ.h"
    #include "locales/win_de-DE.h"
    #include "locales/win_da-DK.h"
    #include "locales/win_es.h"
    #include "locales/win_es-MX.h"
    #include "locales/win_fi.h"
    #include "locales/win_fr.h"
    #include "locales/win_en-GB.h"
    #include "locales/win_hr-HR.h"
    #include "locales/win_hu-HU.h"
    #include "locales/win_it.h"
    #include "locales/win_ja-JP.h"
    #include "locales/win_no.h"
    #include "locales/win_pt-BR.h"
    #include "locales/win_pt-PT.h"
    #include "locales/win_se.h"
    #include "locales/win_si.h"
    #include "locales/win_sk-SK.h"
    #include "locales/win_tr-TK.h"
};

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
    size_t spacePos = input.find(' ');

    if (spacePos != std::string::npos)
    {
        // Extract the first word
        std::string firstWord = input.substr(0, spacePos);

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

static void replaceAllOccurrences(std::string &str, const char from, const char to)
{
    size_t pos = 0;
    while ((pos = str.find(from, pos)) != std::string::npos)
    {
        str.replace(pos, 1, 1, to);
        ++pos; // Move to the next position
    }
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

bool DuckyInterpreter::SetKeyboardLayout(const std::string &layout)
{
    if (layout == "win_en-US")
    {
        keyboardLayout.clear();
        return true;
    }
    else if (langLookupTable.find(layout) != langLookupTable.cend())
    {
        keyboardLayout = layout;
        return true;
    }
    return false;
}

USBKeyDefinition DuckyInterpreter::getUSBKeyDefinition(const std::string &keyStr)
{
    // First look to see if a locale has been set and we have a lookup for this key
    if (keyboardLayout.length() != 0)
    {
        auto &table = langLookupTable[keyboardLayout];
        if (table.find(keyStr) != table.cend())
        {
            LOG(Log::LOG_DEBUG, "Key string (%s) found in langLookupTable\n", keyStr.c_str());
            return table[keyStr];
        }
    }

    const auto it = keyLookupTable.find(keyStr);
    if (it != keyLookupTable.cend())
    {
        return it->second;
    }
    else
    {
        LOG(Log::LOG_ERROR, "Key string (%s) not found in map\n", keyStr.c_str());
        return USBKeyDefinition();
    }
}

DuckyInterpreter::DuckyInterpreter(
    std::function<void(uint32_t)> delayFunc,
    std::function<std::string(const std::string &, int)> readLineFunc,
    std::function<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)> keyboardPressFunc,
    std::function<void()> keyboardReleaseFunc,
    std::function<void(bool, uint8_t, uint8_t, uint8_t, uint8_t)> changeLEDStateFunc,
    std::function<void()> waitForButtonPressFunc,
    std::function<void(DuckyInterpreter::USB_MODE &, const uint16_t &, const uint16_t &, const std::string &, const std::string &, const std::string &)> changeModeFunc,
    std::function<void()> reset)
    : _delayFunc(delayFunc),
      _readLineFunc(readLineFunc),
      _keyboardPressFunc(keyboardPressFunc),
      _keyboardReleaseFunc(keyboardReleaseFunc),
      _changeLEDStateFunc(changeLEDStateFunc),
      _waitForButtonPressFunc(waitForButtonPressFunc),
      _changeModeFunc(changeModeFunc),
      _reset(reset)
{

    _commandMap["VAR"] = [this](string line)
    {
        const auto args = Ducky::SplitString(line);

        if (args.size() != 3 || args[1] != "=")
        {
            LOG(Log::LOG_ERROR, "Invalid variable declaration %d\n", args.size());
            return false;
        }

        auto varName = args[0];
        auto varValue = args[2];

        int intValue = 0;

        if (varValue == "TRUE")
        {
            intValue = 1;
        }
        else if (varValue == "FALSE")
        {
            intValue = 0;
        }
        else
        {
            intValue = stoi(varValue);
        }

        _variables[varName] = intValue;
        LOG(Log::LOG_DEBUG, "Added variable %s = %d\n", varName.c_str(), intValue);

        return true;
    };

    _commandMap["DELAY"] = [this](string arg)
    {
        this->_delayFunc(stoi(arg));
        return true;
    };

    _commandMap["STRING"] = [this](string arg)
    {
        bool ret = true;
        LOG(Log::LOG_DEBUG, "STRING arg = %s\n", arg.c_str());
        for (const char c : arg)
        {
            LOG(Log::LOG_DEBUG, "Trying to print '%c'\n", c);
            const std::string mystring = std::string(1, c);

            auto key = this->getUSBKeyDefinition(mystring);

            if (key.isValid())
            {
                LOG(Log::LOG_DEBUG, "Got a valid key\n");
                this->_keyboardPressFunc((uint8_t)key.modifier, key.hidCode, 0, 0, 0, 0, 0);
                this->_keyboardReleaseFunc();
            }
            else
            {
                ret = false;
                LOG(Log::LOG_ERROR, "Got a invalid key\n");
                break;
            }
        }
        return ret;
    };

    _commandMap["STRINGLN"] = [this](string arg)
    {
        const auto ret = _commandMap["STRING"](arg);

        if (ret)
        {
            const auto keyText = std::string("ENTER");
            auto key = this->getUSBKeyDefinition(keyText);
            if (key.isValid())
            {
                this->_keyboardPressFunc((uint8_t)key.modifier, key.hidCode, 0, 0, 0, 0, 0);
                this->_keyboardReleaseFunc();
            }
            else
            {
                LOG(Log::LOG_ERROR, "Got a invalid key\n");
            }
        }
        else
        {
            LOG(Log::LOG_ERROR, "Got a invalid key\n");
        }
        return ret;
    };

    _commandMap["_SYSTEMKEY"] = [this](string line)
    {
        // this is our internal function to handle all the system keys
        bool ret = false;
        std::vector<uint8_t> keysToHold;
        uint8_t modifier = 0;

        LOG(Log::LOG_DEBUG, "System key line '%s'\n", line.c_str());

        for (std::string &word : Ducky::SplitString(line))
        {
            LOG(Log::LOG_DEBUG, "\tSystem key '%s'\n", word.c_str());

            // when a system key is first any other single key needs to be lowered
            // CONTROL R for instance is actually CONTROL r
            if (word.length() == 1)
            {
                word[0] = std::tolower(word[0]);
            }

            auto key = this->getUSBKeyDefinition(word);

            if (key.isValid() && key.hidCode != 0) // multi key press
            {
                keysToHold.emplace_back(key.hidCode);
                modifier = modifier | (uint8_t)key.modifier;
                ret = true;
            }
            else if (key.isValid()) // just modifier
            {
                modifier = modifier | (uint8_t)key.modifier;
                ret = true;
            }
            else
            {
                LOG(Log::LOG_ERROR, "Got a invalid key\n");
                ret = false;
                break;
            }
        }

        LOG(Log::LOG_DEBUG, "\tGot %d keys\n", keysToHold.size());

        if (ret)
        {
            uint8_t key1 = keysToHold.size() >= 1 ? keysToHold[0] : 0;
            uint8_t key2 = keysToHold.size() >= 2 ? keysToHold[1] : 0;
            uint8_t key3 = keysToHold.size() >= 3 ? keysToHold[2] : 0;
            uint8_t key4 = keysToHold.size() >= 4 ? keysToHold[3] : 0;
            uint8_t key5 = keysToHold.size() >= 5 ? keysToHold[4] : 0;
            uint8_t key6 = keysToHold.size() >= 6 ? keysToHold[5] : 0;

            LOG(Log::LOG_DEBUG, "\tCalling _keyboardPressFunc\n");
            this->_keyboardPressFunc(modifier, key1, key2, key3, key4, key5, key6);
            this->_keyboardReleaseFunc();
        }

        return ret;
    };

    _commandMap["DELAY"] = [this](string arg)
    {
        const int delay = atoi(arg.c_str());
        _delayFunc(delay);
        return true;
    };

    _commandMap["WAIT_FOR_BUTTON_PRESS"] = [this](string arg)
    {
        _waitForButtonPressFunc();
        return true;
    };

    _commandMap["LED_OFF"] = [this](string arg)
    {
        _changeLEDStateFunc(false, 0, 0, 0, 0);
        return true;
    };

    _commandMap["LED_ON"] = [this](string arg)
    {
        _changeLEDStateFunc(true, 100, 100, 100, 255);
        return true;
    };

    _commandMap["LED_R"] = [this](string arg)
    {
        _changeLEDStateFunc(true, 0, 100, 100, 255);
        return true;
    };

    _commandMap["LED_G"] = [this](string arg)
    {
        _changeLEDStateFunc(true, 100, 100, 100, 255);
        return true;
    };

    _commandMap["REM"] = [this](string arg)
    {
        // do nothing
        return true;
    };

    _commandMap["END_IF"] = [this](string arg)
    {
        // do nothing
        return true;
    };

    _commandMap["RESET"] = [this](string arg)
    {
        _reset();
        return true;
    };

    _commandMap["DEFINE"] = [this](string arg)
    {
        const auto ret = extractFirstWord(arg);

        // add this constant to our list
        _constants[ret.first] = ret.second;

        return true;
    };

    _commandMap["ATTACKMODE"] = [this](string arg)
    {
        // ATTACKMODE HID VID_046D PID_C31C
        // ATTACKMODE HID VID_05AC PID_021E MAN_HAK5 PROD_DUCKY SERIAL_1337
        // ATTACKMODE HID STORAGE MAN_HAK5 PROD_DUCKY SERIAL_RANDOM

        // If no MAN, PROD and SERIAL parameters are specified, the USB Rubber Ducky will enumerate with the defaults "USB Input Device" (for both MAN and PROD) and a SERIAL of 111111111111.
        // If specified, the SERIAL_RANDOM parameter will use the pseudorandom number generator to select a unique 12 digit serial number. This is covered in greater detail in the section on randomization.

        uint16_t vid = 0;
        uint16_t pid = 0;
        std::string manufacturer = "USB Input Device";
        std::string product = "USB Input Device";
        std::string serial = "111111111111";
        DuckyInterpreter::USB_MODE mode = DuckyInterpreter::USB_MODE::OFF;

        std::string VIDPrefix = "VID_";
        std::string PIDPrefix = "PID_";
        std::string MANPrefix = "MAN_";
        std::string PRODPrefix = "PROD_";
        std::string SERIALPrefix = "SERIAL_";

        const auto keyWords = Ducky::SplitString(arg);
        if (keyWords.size() == 0)
        {
            return false;
        }

        for (const auto &keyword : keyWords)
        {
            if (keyword == "HID")
            {
                mode = mode | DuckyInterpreter::USB_MODE::HID;
            }
            else if (keyword == "STORAGE")
            {
                mode = mode | DuckyInterpreter::USB_MODE::STORAGE;
            }
            else if (keyword == "OFF")
            {
                mode = DuckyInterpreter::USB_MODE::OFF;
            }
            else if (keyword.substr(0, VIDPrefix.size()) == VIDPrefix)
            {
                string hexString = keyword.substr(VIDPrefix.size(), std::min(keyword.find(' '), keyword.length() - 1));
                char *endPtr = nullptr;
                vid = strtol(hexString.c_str(), &endPtr, 16);
            }
            else if (keyword.substr(0, PIDPrefix.size()) == PIDPrefix)
            {
                string hexString = keyword.substr(PIDPrefix.size(), std::min(keyword.find(' '), keyword.length() - 1));
                char *endPtr = nullptr;
                pid = strtol(hexString.c_str(), &endPtr, 16);
            }
            else if (keyword.substr(0, MANPrefix.size()) == MANPrefix)
            {
                manufacturer = keyword.substr(MANPrefix.size(), std::min(keyword.find(' '), keyword.length() - 1));
            }
            else if (keyword.substr(0, PRODPrefix.size()) == PRODPrefix)
            {
                product = keyword.substr(PRODPrefix.size(), std::min(keyword.find(' '), keyword.length() - 1));
            }
            else if (keyword.substr(0, SERIALPrefix.size()) == SERIALPrefix)
            {
                serial = keyword.substr(SERIALPrefix.size(), std::min(keyword.find(' '), keyword.length() - 1));
            }
            else
            {
                return false;
            }
        }

        _changeModeFunc(mode, vid, pid, manufacturer, product, serial);
        return true;
    };
};

inline std::tuple<std::string, DuckyInterpreter::DuckyScriptOperator, std::string> DuckyInterpreter::parseStatement(std::string statement)
{
    ltrim(statement);
    rtrim(statement);

    const auto words = Ducky::SplitString(statement);
    if (words.size() >= 3)
    {
        std::string lhs = words[0];
        std::string op = words[1];
        std::string rhs = words[2];

        return std::make_tuple(lhs, operatorMap[op], rhs);
    }
    else if (words.size() == 1)
    {
        return std::make_tuple(words[0], DuckyInterpreter::DuckyScriptOperator::EQ, "1");
    }
    else
    {
        LOG(Log::LOG_WARNING, "Unexpected conditions in IF statement '%s'\r\n", statement.c_str());
        return std::make_tuple("", DuckyInterpreter::DuckyScriptOperator::NE, "");
    }
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

std::vector<std::tuple<std::string, DuckyInterpreter::DuckyScriptOperator, std::string>> DuckyInterpreter::parseCondition(std::string &condition)
{
    std::vector<std::tuple<std::string, DuckyScriptOperator, std::string>> result;

    LOG(Log::LOG_DEBUG, "\t\t\tDuckyInterpreter::parseCondition parsing line = '%s'\r\n", condition.c_str());

    ltrim(condition);
    rtrim(condition);

    const auto maskedString = replaceString(condition, "()", "XX");

    size_t statementStartPosition = 0;
    size_t statementEndPosition = std::string::npos;
    int nestedBracketCount = 0;
    for (int pos = 0; pos < condition.length(); ++pos)
    {
        if (condition[pos] == '(' && nestedBracketCount == 0)
        {
            statementStartPosition = pos;
            ++nestedBracketCount;
        }
        else if (maskedString[pos] == '(')
        {
            ++nestedBracketCount;
        }
        else if (maskedString[pos] == ')')
        {
            --nestedBracketCount;

            if (nestedBracketCount == 0)
            {
                statementEndPosition = pos;
                auto statement = condition.substr(statementStartPosition + 1, statementEndPosition - statementStartPosition - 1);
                ltrim(statement);
                rtrim(statement);

                if (statement.length() < 5)
                {
                    LOG(Log::LOG_WARNING, "\t\t\tStatement is too short %s\r\n", statement.c_str());
                    break;
                }

                LOG(Log::LOG_DEBUG, "\t\t\tnext statement = '%s'\r\n", statement.c_str());
                // check if statement contains any ()

                bool containsNoFurtherNesting = statement[0] != '(' && statement[statement.length() - 1] != ')';

                if (containsNoFurtherNesting == false)
                {
                    LOG(Log::LOG_DEBUG, "\t\t\tContains further nesting, parsing again\r\n", statement.c_str());
                    auto newResult = parseCondition(statement);
                    result.insert(result.end(), newResult.begin(), newResult.end());
                }
                else
                {
                    LOG(Log::LOG_DEBUG, "\t\t\tPreparing statements\r\n", statement.c_str());
                    result.emplace_back(parseStatement(statement));
                }
            }
        }
    }

    if (statementEndPosition == std::string::npos)
    {
        // we didn't find any bracketed expressions
        LOG(Log::LOG_DEBUG, "\t\t\tNo bracketed statement found for %s\r\n", condition.c_str());
        result.emplace_back(parseStatement(condition));
    }

    return result;
}

static std::string extractCondition(const std::string &line)
{
    // WHILE (TRUE_FIVE_TIMES() == TRUE)
    // IF (FUNC3() == FALSE) THEN

    std::string condition = line;

    std::string prefix;
    std::string suffix;

    if (line.substr(0, PrefixWHILE.size()) == PrefixWHILE)
    {
        prefix = PrefixWHILE;
    }
    else if (line.substr(0, prefixIF.size()) == prefixIF)
    {
        prefix = prefixIF;
        suffix = THENSuffix;
    }
    else if (line.substr(0, prefixELSE_IF.size()) == prefixELSE_IF)
    {
        prefix = prefixELSE_IF;
        suffix = THENSuffix;
    }
    else
    {
        LOG(Log::LOG_ERROR, "\t\tCannot extract condition for = '%s'\r\n", line.c_str());
        return std::string();
    }

    if (prefix.size() != 0)
    {
        if (condition.substr(0, prefix.size()) == prefix)
        {
            condition = condition.substr(prefix.size());
        }
    }

    if (suffix.size() != 0)
    {
        if (condition.substr(condition.size() - suffix.size()) == suffix)
        {
            condition = condition.substr(0, condition.size() - suffix.size());
        }
    }

    return condition;
}

static std::string lowerCaseString(const std::string &str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return result;
}

int DuckyInterpreter::evaluate(std::string &str, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands)
{
    LOG(Log::LOG_DEBUG, "\t\tStatement = '%s'\r\n", str.c_str());

    for (const auto &pair : _variables)
    {
        size_t pos = str.find(pair.first);
        while (pos != std::string::npos)
        {
            auto replacementText = std::to_string(pair.second);

            str.replace(pos, pair.first.length(), replacementText);
            pos = str.find(pair.first, pos + replacementText.length());
        }
    }

    // first try to evaluate any functions in the LHS or RHS
    if (extCommands.find(str) != extCommands.cend())
    {
        LOG(Log::LOG_DEBUG, "\t\tFound extension command to run: %s\r\n", str.c_str());
        return extCommands[str](str, _constants, _variables);
    }
    else
    {
        LOG(Log::LOG_DEBUG, "\t\tEvaluating text expression: %s\r\n", str.c_str());
        const auto &lower = lowerCaseString(str);
        if (lower == "true")
        {
            return 1;
        }
        else if (lower == "false")
        {
            return 0;
        }
        else
        {
            // convert to int
            return atoi(str.c_str());
        }
    }
}

bool DuckyInterpreter::evaluateStatement(std::string &line, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands, bool *conditionToCheck)
{
    LOG(Log::LOG_DEBUG, "Handling statement\r\n");
    auto conditionStr = extractCondition(line);

    if (conditionStr.length() == 0)
    {
        return false;
    }

    LOG(Log::LOG_DEBUG, "\tCondition = '%s'\r\n", conditionStr.c_str());

    *conditionToCheck = true;

    for (auto &condition : parseCondition(conditionStr))
    {
        auto lhsStr = std::get<0>(condition);
        auto rhsStr = std::get<2>(condition);
        auto op = std::get<1>(condition);

        LOG(Log::LOG_DEBUG, "\tEvaluating condition LHS = %s, OP = %d, RHS = %s\r\n", lhsStr.c_str(), op, rhsStr.c_str());
        int lhsValue = this->evaluate(lhsStr, extCommands);
        int rhsValue = this->evaluate(rhsStr, extCommands);

        switch (op)
        {
        case DuckyScriptOperator::EQ:
            *conditionToCheck &= lhsValue == rhsValue;
            break;
        case DuckyScriptOperator::NE:
            *conditionToCheck &= lhsValue != rhsValue;
            break;
        case DuckyScriptOperator::GT:
            *conditionToCheck &= lhsValue > rhsValue;
            break;
        case DuckyScriptOperator::GTE:
            *conditionToCheck &= lhsValue >= rhsValue;
            break;
        case DuckyScriptOperator::LT:
            *conditionToCheck &= lhsValue < rhsValue;
            break;
        case DuckyScriptOperator::LTE:
            *conditionToCheck &= lhsValue <= rhsValue;
            break;
        default:
            break;
        }
    }

    return true;
}

// the job of this function is to evaluate the condition and if true to increment the line number
// if false we read until END_IF
int DuckyInterpreter::handleIF(const std::string &filePath, int lineNumber, std::string &line, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands)
{
    bool conditionToCheck = false;

    if (!evaluateStatement(line, extCommands, &conditionToCheck))
    {
        LOG(Log::LOG_ERROR, "Could not evaluate statement %s", line.c_str());
        return SCRIPT_ERROR;
    }

    if (conditionToCheck)
    {
        LOG(Log::LOG_DEBUG, "\tIF..ELSE evaluated to success, moving to next line %d\r\n", lineNumber);
        // we can execute inside the IF statement
        return lineNumber + 1;
    }
    else
    {
        LOG(Log::LOG_DEBUG, "\tEvaluation was false, skipping to next statement\r\n");

        // need to skip instructions until we hit ELSE, ELSE IF or END_IF
        lineNumber = skipLineUntilCondition(filePath, lineNumber, std::vector<std::string>{prefixIF}, std::vector<std::string>{prefixEND_IF}, std::vector<std::string>{prefixELSE_IF, prefixELSE, prefixEND_IF});

        if (lineNumber == SCRIPT_ERROR)
        {
            LOG(Log::LOG_ERROR, "Could not find end of IF statement");
            return SCRIPT_ERROR;
        }

        LOG(Log::LOG_DEBUG, "\tSkipped until %d\r\n", lineNumber);

        line = _readLineFunc(filePath, lineNumber);

        ltrim(line);
        rtrim(line);

        if (line.empty())
        {
            LOG(Log::LOG_DEBUG, "Error EOF while looking for END_IF\r\n");
            return SCRIPT_ERROR;
        }

        if (line.substr(0, prefixEND_IF.size()) == prefixEND_IF)
        {
            return lineNumber + 1;
        }
        else if (line.substr(0, prefixELSE_IF.size()) == prefixELSE_IF)
        {
            LOG(Log::LOG_DEBUG, "\tFound ELSE IF to evaluate on line %d\r\n", lineNumber);
            return handleIF(filePath, lineNumber, line, extCommands);
        }
        else if (line.substr(0, prefixELSE.size()) == prefixELSE)
        {
            LOG(Log::LOG_DEBUG, "\tELSE found, moving to next line\r\n");
            // we can execute inside the IF statement
            return lineNumber + 1;
        }
    }

    return lineNumber;
}

int DuckyInterpreter::handleWHILE(const std::string &filePath, int lineNumber, std::string &line, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands)
{
    bool conditionToCheck = false;

    if (!evaluateStatement(line, extCommands, &conditionToCheck))
    {
        LOG(Log::LOG_DEBUG, "\tCould not evaluate statement %s\r\n", line.c_str());
        return SCRIPT_ERROR;
    }

    if (conditionToCheck)
    {
        LOG(Log::LOG_DEBUG, "\tWHILE evaluated to success, preserving line %d, moving to next line\r\n", lineNumber);
        _whileLoopLineNumbers.push(lineNumber);
        // we can execute inside the WHILE statement
        return lineNumber + 1;
    }
    else
    {
        // need to skip instructions until we hit END_WHILE
        lineNumber = skipLineUntilCondition(filePath, lineNumber, std::vector<std::string>{PrefixWHILE}, std::vector<std::string>{EndWHILE}, std::vector<std::string>{EndWHILE});

        if (lineNumber == SCRIPT_ERROR)
        {
            LOG(Log::LOG_DEBUG, "\tError EOF while looking for END_WHILE\r\n");
            return SCRIPT_ERROR;
        }

        return lineNumber + 1;
    }
}

int DuckyInterpreter::skipLineUntilCondition(const std::string &filePath, int lineNumber, const std::vector<std::string> &nestingConditions, const std::vector<std::string> &endConditions, const std::vector<std::string> &matchingConditions, int nestingCount)
{
    LOG(Log::LOG_DEBUG, "\tSkipping lines until condition(s) is met\r\n");

    // need to skip instructions until we hit endCondition whilst making sure that we aren't
    // using any statements that would cause nesting with our comparisions!

    while (true)
    {
        // increment line and read
        lineNumber++;
        auto line = _readLineFunc(filePath, lineNumber);

        if (line.empty())
        {
            LOG(Log::LOG_DEBUG, "\tError EOF while looking for end condition\r\n");
            return SCRIPT_ERROR;
        }

        // sanitise
        ltrim(line);
        rtrim(line);

        bool incrementLineNumber = false;

        for (const auto &nestCondition : nestingConditions)
        {
            if (line.substr(0, nestCondition.size()) == nestCondition)
            {
                nestingCount++;
                incrementLineNumber = true;
                LOG(Log::LOG_DEBUG, "\tFound inner nesting condition (%s) line %d, increasing nesting count to %d\r\n", nestCondition.c_str(), lineNumber, nestingCount);
                continue;
            }
        }

        if (incrementLineNumber)
        {
            continue;
        }

        if (nestingCount > 0)
        {
            for (const auto &endCondition : endConditions)
            {
                if (line.substr(0, endCondition.size()) == endCondition)
                {
                    nestingCount--;
                    incrementLineNumber = true;
                    LOG(Log::LOG_DEBUG, "\tFound end condition (%s) line %d, decrementing nesting count to %d\r\n", endCondition.c_str(), lineNumber, nestingCount);
                    continue;
                }
            }
        }

        if (incrementLineNumber)
        {
            continue;
        }

        if (nestingCount == 0)
        {
            for (const auto &matchCondition : matchingConditions)
            {
                if (line.substr(0, matchCondition.size()) == matchCondition)
                {
                    LOG(Log::LOG_DEBUG, "\tFound matching statement (%s) line %d\r\n", matchCondition.c_str(), lineNumber);
                    nestingCount--;

                    if (nestingCount <= 0)
                    {
                        return lineNumber;
                    }
                }
            }
        }
    }

    return lineNumber;
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

bool DuckyInterpreter::assignToVariable(const std::string &variableName, std::string &arg, std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands)
{
    LOG(Log::LOG_DEBUG, "Assigning expression %s to variable %s\r\n", arg.c_str(), variableName.c_str());
    int currentValue = _variables[variableName];

    if (isStringDigits(arg))
    {
        currentValue = atoi(arg.c_str());
    }
    else if (arg == "TRUE")
    {
        currentValue = 1;
    }
    else if (arg == "FALSE")
    {
        currentValue = 0;
    }
    else
    {
        for (auto &condition : parseCondition(arg))
        {
            int lhsValue = this->evaluate(std::get<0>(condition), extCommands);
            int rhsValue = this->evaluate(std::get<2>(condition), extCommands);
            auto op = std::get<1>(condition);
            LOG(Log::LOG_DEBUG, "Processing condition LHS=%d, OP=%d, RHS=%d\r\n", lhsValue, op, rhsValue);

            switch (op)
            {
            case DuckyScriptOperator::ADD:
                currentValue = lhsValue + rhsValue;
                break;
            case DuckyScriptOperator::SUBTRACT:
                currentValue = lhsValue - rhsValue;
                break;
            case DuckyScriptOperator::MULTIPLY:
                currentValue = lhsValue * rhsValue;
                break;
            case DuckyScriptOperator::DIVIDE:
                currentValue = lhsValue / rhsValue;
                break;
            case DuckyScriptOperator::MOD:
                currentValue = lhsValue % rhsValue;
                break;
            default:
                LOG(Log::LOG_DEBUG, "Invalid operator %d\r\n", op);
                return false;
            }
        }
    }

    LOG(Log::LOG_DEBUG, "Setting variable %s to %d\r\n", variableName.c_str(), currentValue);
    _variables[variableName] = currentValue;

    return true;
}

// -1 error
//
int DuckyInterpreter::Execute(const std::string &filePath,
                              int lineNumber,
                              std::unordered_map<std::string,
                                                 std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> &extCommands,
                              std::vector<std::function<std::pair<std::string, std::string>()>> &userDefinedConstValues)
{
    if (lineNumber < 0)
    {
        LOG(Log::LOG_DEBUG, "Bad line number %d\r\n", lineNumber);
        return lineNumber;
    }

    std::string line = _readLineFunc(filePath, lineNumber);
    if (line.empty())
    {
        LOG(Log::LOG_DEBUG, "EOF\r\n");
        return END_OF_FILE;
    }

    LOG(Log::LOG_DEBUG, "Processing line %d\r\n", lineNumber);

    int ret = SCRIPT_ERROR;
    bool commandExitCode = true;

    ltrim(line);
    rtrim(line);
    if (!line.empty())
    {
        // First we need to loop through any constants that have been defined and replace
        // their usage in the current line
        for (const auto &constant : _constants)
        {
            line = replaceAllOccurrences(line, constant.first, constant.second);
        }
        for (const auto &userDefinedFunction : userDefinedConstValues)
        {
            const auto &constant = userDefinedFunction();
            line = replaceAllOccurrences(line, constant.first, constant.second);
        }

        string command = line.substr(0, std::min(line.find(' '), line.find('-')));
        rtrim(command);
        LOG(Log::LOG_DEBUG, "COMMAND = '%s'\r\n", command.c_str());

        if (line.substr(0, prefixIF.size()) == prefixIF) // is this an IF statement, if so we handle lineNumber differently
        {
            // line starts with "IF "
            return handleIF(filePath, lineNumber, line, extCommands);
        }
        else if (line.substr(0, PrefixWHILE.size()) == PrefixWHILE) // is this an IF statement, if so we handle lineNumber differently
        {
            // line starts with "WHILE "
            return handleWHILE(filePath, lineNumber, line, extCommands);
        }
        else if (line.substr(0, EndWHILE.size()) == EndWHILE) // END_WHILE needs to pop stack and evaluate initial condition
        {
            // line starts with "END_WHILE"
            if (_whileLoopLineNumbers.size() == 0)
            {
                // we've exited the while loop
                LOG(Log::LOG_DEBUG, "No return point, WHILE LOOP complete\r\n", lineNumber);
                commandExitCode = true;
            }
            else
            {
                lineNumber = _whileLoopLineNumbers.top();
                _whileLoopLineNumbers.pop();
                LOG(Log::LOG_DEBUG, "Jumping to line '%d'\r\n", lineNumber);
                return Execute(filePath, lineNumber, extCommands, userDefinedConstValues);
            }
        }
        else if (line.substr(0, prefixELSE.size()) == prefixELSE) // current execution has ended in a ELSE, we need to skip until END_IF
        {
            auto endIfConditions = std::vector<std::string>{prefixEND_IF};
            lineNumber = skipLineUntilCondition(filePath, lineNumber, std::vector<std::string>{prefixIF}, endIfConditions, endIfConditions);
        }
        else if (line.substr(0, RestartPayload.size()) == RestartPayload) // need to handle this cmd here as its changing the line number
        {
            return 0;
        }
        else if (extCommands.find(command) != extCommands.cend()) // first check if we have a extension command set for this string
        {
            commandExitCode = extCommands[command](line, _constants, _variables) != 0;
        }
        else if (_commandMap.find(command) != _commandMap.cend())
        {
            LOG(Log::LOG_DEBUG, "COMMAND FOUND\r\n");
            string arg = line.substr(line.find(' ') + 1);

            rtrim(arg);

            LOG(Log::LOG_DEBUG, "arg = '%s'\n", arg.c_str());
            commandExitCode = _commandMap[command](arg);
        }
        else if (line.size() >= 2 && line[0] == '$')
        {
            LOG(Log::LOG_DEBUG, "Variable assignment\r\n");
            const auto variableName = command;
            if (_variables.find(variableName) == _variables.cend())
            {
                LOG(Log::LOG_ERROR, "Variable not declared %s\r\n", variableName.c_str());
                commandExitCode = false;
            }
            else
            {
                auto args = line.substr(variableName.size() + 1);
                ltrim(args);
                if (args[0] == '=')
                {
                    args = args.substr(1);
                    ltrim(args);
                    commandExitCode = assignToVariable(variableName, args, extCommands);
                }
                else
                {
                    LOG(Log::LOG_DEBUG, "Variable assignment error %s\r\n", args.c_str());
                    commandExitCode = false;
                }
            }
        }
        else if (std::find(systemKeys.begin(), systemKeys.end(), command) != systemKeys.end())
        {
            LOG(Log::LOG_DEBUG, "_SYSTEMKEY FOUND\n");

            replaceAllOccurrences(line, '-', ' ');
            commandExitCode = _commandMap["_SYSTEMKEY"](line);
        }
        else
        {
            commandExitCode = false;
        }

        if (!commandExitCode)
        {
            LOG(Log::LOG_ERROR, "Failed processing = '%s'\n", line.c_str());
        }
    }

    if (commandExitCode)
    {
        ++lineNumber;
        ret = lineNumber;
    }

    return ret;
}
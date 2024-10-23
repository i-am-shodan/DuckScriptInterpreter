#pragma once

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
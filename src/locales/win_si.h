#pragma once

// Language: Serbian (Serbia)
#ifdef LOCALE_win_si

    {"win_si",
     {
        // Serbian Special Characters
        {"č", USBKeyDefinition(0x2c)},
        {"Č", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
        {"ž", USBKeyDefinition(0x1e)},
        {"Ž", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
        {"š", USBKeyDefinition(0x1f)},
        {"Š", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
        {"đ", USBKeyDefinition(0x20)},
        {"Đ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
        {"ć", USBKeyDefinition(0x21)},
        {"Ć", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
        
        // Symbols - Regular
        {"'", USBKeyDefinition(0x2d)},
        {"+", USBKeyDefinition(0x2e)},
        {",", USBKeyDefinition(0x36)},
        {".", USBKeyDefinition(0x37)},
        {"-", USBKeyDefinition(0x38)},
        {"<", USBKeyDefinition(0x64)},
        
        // Symbols - With Shift
        {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
        {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
        {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
        {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
        {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
        {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
        {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
        {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
        {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
        {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
        {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
        {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
        
        // Symbols - With AltGr (Right Alt)
        {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x05)},
        {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x09)},
        {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x0a)},
        {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x11)},
        {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x14)},
        {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x19)},
        {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1a)},
        {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1e)},
        {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
        {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
        
     }},

#endif

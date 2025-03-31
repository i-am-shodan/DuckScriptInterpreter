#pragma once

// Language: Turkish (Turkey)
#ifdef LOCALE_win_tr_TK

    {"win_tr-TR",
     {
        // Turkish Special Characters
        {"ğ", USBKeyDefinition(0x2f)},
        {"Ğ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
        {"ü", USBKeyDefinition(0x34)},
        {"Ü", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
        {"ş", USBKeyDefinition(0x33)},
        {"Ş", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
        {"ı", USBKeyDefinition(0x24)},
        {"İ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
        {"ö", USBKeyDefinition(0x2c)},
        {"Ö", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
        {"ç", USBKeyDefinition(0x2e)},
        {"Ç", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
        
        // Special Symbols
        {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x14)},
        {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
        {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
        {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
        {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
        {"*", USBKeyDefinition(0x2d)},
        {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
        {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
        {"-", USBKeyDefinition(0x2e)},
        {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
        {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
        {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
        {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x25)},
        {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
        {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x26)},
        {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x27)},
        {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2d)},
        {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2e)},
        {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
        {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
        {"'", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
        {"\"", USBKeyDefinition(0x35)},
        {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x31)},
        {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x30)},
        {",", USBKeyDefinition(0x31)},
        {"<", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x35)},
        {".", USBKeyDefinition(0x38)},
        {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1e)},
        {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
        {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
     }},

#endif
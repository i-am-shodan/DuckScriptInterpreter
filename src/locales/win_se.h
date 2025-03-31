#pragma once

// Language: Swedish (Sweden)
#ifdef LOCALE_win_se

    {"win_se",
     {  
        // Swedish Special Characters
        {"å", USBKeyDefinition(0x2f)},
        {"Å", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
        {"ä", USBKeyDefinition(0x34)},
        {"Ä", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
        {"ö", USBKeyDefinition(0x33)},
        {"Ö", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
        
        // Other European Characters
        {"é", USBKeyDefinition(0x20)},
        {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
        {"æ", USBKeyDefinition(0x2c)},
        {"Æ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
        {"ø", USBKeyDefinition(0x2e)},
        {"Ø", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
        {"ç", USBKeyDefinition(0x2c)},
        {"Ç", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
        {"ñ", USBKeyDefinition(0x31)},
        {"Ñ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
        
        // Basic Punctuation
        {".", USBKeyDefinition(0x37)},
        {",", USBKeyDefinition(0x36)},
        {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
        {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
        {"'", USBKeyDefinition(0x31)},
        {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
        {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
        {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
        
        // Mathematical Symbols
        {"+", USBKeyDefinition(0x2d)},
        {"-", USBKeyDefinition(0x38)},
        {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
        {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
        {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
        {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
        
        // Brackets and Special Characters
        {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
        {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
        {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x25)},
        {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x26)},
        {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
        {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x27)},
        {"<", USBKeyDefinition(0x64)},
        {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
        
        // Other Special Characters
        {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1f)},
        {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
        {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
        {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
        {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
        {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
        {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
        {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2d)},
        {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x64)},
     }},

#endif

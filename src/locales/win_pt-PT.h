#pragma once

// Language: Portuguese (Portugal)
#ifdef LOCALE_win_pt_PT

    {"win_pt-PT",
     {
        // Special Portuguese Characters - Lowercase
        {"á", USBKeyDefinition(0x1e)},
        {"à", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
        {"â", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
        {"ã", USBKeyDefinition(0x24)},
        {"ç", USBKeyDefinition(0x33)},
        {"é", USBKeyDefinition(0x20)},
        {"ê", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
        {"í", USBKeyDefinition(0x21)},
        {"ó", USBKeyDefinition(0x22)},
        {"ô", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
        {"õ", USBKeyDefinition(0x25)},
        {"ú", USBKeyDefinition(0x23)},
        
        // Special Portuguese Characters - Uppercase
        {"À", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
        {"Á", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
        {"Â", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
        {"Ã", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
        {"Ç", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
        {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
        {"Ê", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
        {"Í", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
        {"Ó", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
        {"Ô", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
        {"Õ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
        {"Ú", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
        
        // Basic Punctuation
        {".", USBKeyDefinition(0x37)},
        {",", USBKeyDefinition(0x36)},
        {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
        {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
        {"'", USBKeyDefinition(0x2d)},
        {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
        
        // Mathematical Symbols
        {"+", USBKeyDefinition(0x2f)},
        {"-", USBKeyDefinition(0x38)},
        {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
        {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
        {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
        {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
        
        // Brackets
        {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
        {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
        {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x25)},
        {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x26)},
        {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
        {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x27)},
        
        // Special Characters
        {"~", USBKeyDefinition(0x32)},
        {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
        {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
        {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1f)},
        {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
        {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
        {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
        {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x32)},
        {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
        {"\\", USBKeyDefinition(0x35)},
        {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
        {"<", USBKeyDefinition(0x64)},
        {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
        {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
     }},

#endif
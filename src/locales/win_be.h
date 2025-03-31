#pragma once

// Language: Belgian (Belgium)
#ifdef LOCALE_win_be

    {"win_be",
     {
         // Belgian Special Characters - Lowercase
         {"à", USBKeyDefinition(0x2f)},
         {"é", USBKeyDefinition(0x20)},
         {"è", USBKeyDefinition(0x2e)},
         {"ê", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"ô", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {"û", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {"ç", USBKeyDefinition(0x33)},
         {"ë", USBKeyDefinition(0x34)},
         {"ï", USBKeyDefinition(0x35)},
         {"ü", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
         {"ÿ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
         {"œ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
         {"æ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         
         // Belgian Special Characters - Uppercase
         {"À", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"È", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"Ê", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"Ô", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {"Û", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {"Ç", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"Ë", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
         {"Ï", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
         {"Ü", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
         {"Ÿ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
         {"Œ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
         {"Æ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},

         // Special characters
         {"&", USBKeyDefinition(0x1e)},
         {"\"", USBKeyDefinition(0x20)},
         {"'", USBKeyDefinition(0x21)},
         {"(", USBKeyDefinition(0x22)},
         {"§", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"!", USBKeyDefinition(0x24)},
         {")", USBKeyDefinition(0x27)},
         {"-", USBKeyDefinition(0x2d)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"$", USBKeyDefinition(0x30)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {",", USBKeyDefinition(0x10)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x10)},
         {";", USBKeyDefinition(0x36)},
         {".", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {":", USBKeyDefinition(0x37)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"=", USBKeyDefinition(0x38)},
         {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
         {"<", USBKeyDefinition(0x64)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         
         // AltGr combinations
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1e)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1f)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
         {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x23)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x26)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x27)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2f)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x30)},
         {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x31)},
         {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x64)},
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x38)},
         {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x08)},
         {"µ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x10)},
     }},

#endif
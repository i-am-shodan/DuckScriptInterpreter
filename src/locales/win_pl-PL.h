#pragma once

// language: Polish (Poland)
#ifdef LOCALE_win_pl_PL

    {"win_pl-PL",
     {
         // Polish Special Characters
         {"ą", USBKeyDefinition(0x2f)},
         {"Ą", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {"ć", USBKeyDefinition(0x06)},
         {"Ć", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x06)},
         {"ę", USBKeyDefinition(0x08)},
         {"Ę", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x08)},
         {"ł", USBKeyDefinition(0x0f)},
         {"Ł", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0f)},
         {"ń", USBKeyDefinition(0x11)},
         {"Ń", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x11)},
         {"ó", USBKeyDefinition(0x12)},
         {"Ó", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x12)},
         {"ś", USBKeyDefinition(0x16)},
         {"Ś", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x16)},
         {"ź", USBKeyDefinition(0x1d)},
         {"Ź", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1d)},
         {"ż", USBKeyDefinition(0x1c)},
         {"Ż", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1c)},
         
         // Basic Punctuation
         {",", USBKeyDefinition(0x36)},
         {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {".", USBKeyDefinition(0x37)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"-", USBKeyDefinition(0x38)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         
         // Operators and Symbols
         {"+", USBKeyDefinition(0x30)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"'", USBKeyDefinition(0x31)},
         {"<", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         
         // Accent Keys
         {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x23)},
         {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
         {"°", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x22)},
         
         // Brackets
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x25)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x26)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x27)},
         
         // AltGr Characters
         {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x08)},
         {"¶", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x13)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x14)},
         {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2d)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x64)},
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x30)},
         {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
         {"§", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x16)},
     }},

#endif
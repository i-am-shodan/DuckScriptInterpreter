#pragma once

// language: Czech (Czech Republic)
#ifdef LOCALE_win_cs_CZ

    {"win_cs-CZ",
     {
         // Czech Special Characters - Lowercase
         {"ě", USBKeyDefinition(0x1e)},
         {"š", USBKeyDefinition(0x21)},
         {"č", USBKeyDefinition(0x22)},
         {"ř", USBKeyDefinition(0x23)},
         {"ž", USBKeyDefinition(0x24)},
         {"ý", USBKeyDefinition(0x25)},
         {"á", USBKeyDefinition(0x26)},
         {"í", USBKeyDefinition(0x27)},
         {"é", USBKeyDefinition(0x28)},
         {"ó", USBKeyDefinition(0x29)},
         {"ú", USBKeyDefinition(0x2a)},
         {"ů", USBKeyDefinition(0x2f)},
         {"ň", USBKeyDefinition(0x2b)},
         {"ď", USBKeyDefinition(0x2c)},
         {"ť", USBKeyDefinition(0x2d)},
         
         // Czech Special Characters - Uppercase
         {"Ě", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"Š", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"Č", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"Ř", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"Ž", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"Ý", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {"Á", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {"Í", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x28)},
         {"Ó", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x29)},
         {"Ú", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2a)},
         {"Ů", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {"Ň", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2b)},
         {"Ď", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
         {"Ť", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},

         // Letters with different positions
         {"Y", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1d)},
         {"Z", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1c)},
         {"y", USBKeyDefinition(0x1d)},
         {"z", USBKeyDefinition(0x1c)},
         
         // Symbols requiring modifiers
         {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1b)},
         {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x33)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x06)},
         {"'", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {")", USBKeyDefinition(0x30)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x38)},
         {"+", USBKeyDefinition(0x1e)},
         {",", USBKeyDefinition(0x36)},
         {"-", USBKeyDefinition(0x38)},
         {".", USBKeyDefinition(0x37)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {";", USBKeyDefinition(0x35)},
         {"<", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {"=", USBKeyDefinition(0x2d)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x19)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x09)},
         {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x14)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x0a)},
         {"^", USBKeyDefinition(0x2c)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {"`", USBKeyDefinition(0x2c)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x05)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1a)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x11)},
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1e)},
         
         // Euro symbol
         {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x08)},
     }},

#endif
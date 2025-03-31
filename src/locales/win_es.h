#pragma once

// language: Spanish (Spain)
#ifdef LOCALE_win_es

    {"win_es",
     {
         // Spanish Special Characters - Lowercase
         {"á", USBKeyDefinition(0x2d)},
         {"é", USBKeyDefinition(0x2e)},
         {"í", USBKeyDefinition(0x2f)},
         {"ó", USBKeyDefinition(0x30)},
         {"ú", USBKeyDefinition(0x31)},
         {"ü", USBKeyDefinition(0x32)},
         {"ñ", USBKeyDefinition(0x33)},
         {"ç", USBKeyDefinition(0x34)},

         // Spanish Special Characters - Uppercase
         {"Á", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"Í", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {"Ó", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {"Ú", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {"Ü", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x32)},
         {"Ñ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"Ç", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},

         // Accents and Diacritical Marks
         {"¨", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
         {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},

         // Basic symbols (no modifiers)
         {" ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::None, 0x2c)},
         {"'", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::None, 0x2d)},
         {"¡", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::None, 0x2e)},
         {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::None, 0x30)},
         {",", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::None, 0x36)},
         {".", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::None, 0x37)},
         {"-", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::None, 0x38)},
         {"<", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::None, 0x64)},
         
         // Shifted symbols
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"¿", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         
         // AltGr (Right Alt) symbols
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1e)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1f)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
         {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x08)},
         {"¬", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x23)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2f)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x30)},
         {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x35)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x34)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x31)},
     }},

#endif
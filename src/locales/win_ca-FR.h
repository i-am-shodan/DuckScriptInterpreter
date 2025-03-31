#pragma once

// Language: Catalan (Catalonia)
#ifdef LOCALE_win_ca_FR

    {"win_ca-FR",
     {
         // Catalan Special Characters - Lowercase
         {"à", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x04)},
         {"ç", USBKeyDefinition(0x33)},
         {"è", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x08)},
         {"é", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x08)},
         {"í", USBKeyDefinition(0x0c)},
         {"ï", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x0c)},
         {"ò", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x12)},
         {"ó", USBKeyDefinition(0x12)},
         {"ú", USBKeyDefinition(0x18)},
         {"ü", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x18)},
         {"·", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},

         // Catalan Special Characters - Uppercase
         {"À", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x04)},
         {"Ç", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"È", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x08)},
         {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x08)},
         {"Í", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x0c)},
         {"Ï", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x0d)},
         {"Ò", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x12)},
         {"Ó", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x12)},
         {"Ú", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x18)},
         {"Ü", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x19)},

         // Basic Punctuation
         {",", USBKeyDefinition(0x36)},
         {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {".", USBKeyDefinition(0x37)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
         {"'", USBKeyDefinition(0x2f)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"-", USBKeyDefinition(0x38)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         
         // Mathematical Symbols
         {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"<", USBKeyDefinition(0x64)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         
         // Brackets and Parentheses
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x25)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x26)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x27)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x28)},

         // Other Special Characters
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"º", USBKeyDefinition(0x35)},
         {"ª", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"¿", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2d)},
         {"¡", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1e)},

         // Characters with Right Alt (AltGr)
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
         {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x35)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1e)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x22)},
         {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x20)},
         {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x1e)},
         
         // Currency Symbols
         {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x08)},
         {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"£", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
         {"¢", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x06)},
     }},

#endif
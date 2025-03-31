#pragma once

// language: French (France)
#ifdef LOCALE_win_fr

    {"win_fr",
     {
         // French Special Characters - Lowercase
         {"à", USBKeyDefinition(0x27)},
         {"â", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
         {"ç", USBKeyDefinition(0x33)},
         {"é", USBKeyDefinition(0x20)},
         {"è", USBKeyDefinition(0x24)},
         {"ê", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"ë", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x08)},
         {"î", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x0c)},
         {"ô", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x12)},
         {"ù", USBKeyDefinition(0x32)},
         {"û", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x18)},
         {"œ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x12)},
         {"æ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x04)},

         // French Special Characters - Uppercase
         {"À", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"Â", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
         {"Ç", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"È", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)}, 
         {"Ê", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e, 0x08)},
         {"Ë", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x09)},
         {"Î", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x0d)},
         {"Ô", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x13)},
         {"Ù", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x32)},
         {"Û", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f, 0x19)},
         {"Œ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x13)},
         {"Æ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x05)},

         // Basic Punctuation
         {",", USBKeyDefinition(0x10)},
         {";", USBKeyDefinition(0x36)},
         {":", USBKeyDefinition(0x37)},
         {".", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"'", USBKeyDefinition(0x21)},
         {"\"", USBKeyDefinition(0x20)},
         {"-", USBKeyDefinition(0x23)},
         {"_", USBKeyDefinition(0x25)},
         
         // Mathematical Symbols
         {"=", USBKeyDefinition(0x2e)},
         {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"*", USBKeyDefinition(0x31)},
         {"<", USBKeyDefinition(0x64)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         {"^", USBKeyDefinition(0x2f)},
         
         // Brackets and Parentheses
         {"(", USBKeyDefinition(0x22)},
         {")", USBKeyDefinition(0x2d)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x22)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2d)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2e)},

         // Other Special Characters
         {"&", USBKeyDefinition(0x1e)},
         {"\"", USBKeyDefinition(0x20)},
         {"'", USBKeyDefinition(0x21)},
         {"!", USBKeyDefinition(0x38)},
         {"§", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {"µ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {"°", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},

         // Characters with Right Alt (AltGr)
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1f)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x23)},
         {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
         {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x25)},
         {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x26)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x27)},
         
         // Currency Symbols
         {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x08)},
         {"$", USBKeyDefinition(0x30)},
         {"£", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x30)},
         {"¢", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x06)},
     }},

#endif
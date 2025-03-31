#pragma once

// language: German (Germany)
#ifdef LOCALE_win_de_DE

    {"win_de-DE",
     {
         // German Special Characters
         {"ä", USBKeyDefinition(0x2f)},
         {"Ä", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {"ö", USBKeyDefinition(0x33)},
         {"Ö", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"ü", USBKeyDefinition(0x34)},
         {"Ü", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
         {"ß", USBKeyDefinition(0x2d)},
         
         // German Keyboard Layout Specifics (Y/Z swapped)
         {"y", USBKeyDefinition(0x1d)},
         {"Y", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1d)},
         {"z", USBKeyDefinition(0x1c)},
         {"Z", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1c)},
         
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
         {"#", USBKeyDefinition(0x31)},
         {"'", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {"<", USBKeyDefinition(0x64)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         
         // Accent Keys
         {"^", USBKeyDefinition(0x2c)},
         {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)}, 
         {"°", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)}, 
         
         // Brackets
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x25)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x26)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x27)},
         
         // AltGr Characters
         {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x08)},  
         {"µ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x10)},  
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x14)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x64)},  
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x30)},  
         {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},  
         {"§", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
     }},

#endif

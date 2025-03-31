#pragma once

// language: Hungarian (Hungary)
#ifdef LOCALE_win_hu_HU

    {"win_hu-HU",
     {
        // Hungarian Special Characters - Lowercase
         {"á", USBKeyDefinition(0x1e)},
         {"é", USBKeyDefinition(0x20)},
         {"í", USBKeyDefinition(0x21)},
         {"ó", USBKeyDefinition(0x22)},
         {"ö", USBKeyDefinition(0x23)},
         {"ő", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"ú", USBKeyDefinition(0x24)},
         {"ü", USBKeyDefinition(0x25)},
         {"ű", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         
         // Hungarian Special Characters - Uppercase
         {"Á", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"Í", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"Ó", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"Ö", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"Ő", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"Ú", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"Ü", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {"Ű", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},

         // Swapped Latin Alphabet Keys (Hungarian layout has y/z swapped)
         {"y", USBKeyDefinition(0x1d)},
         {"z", USBKeyDefinition(0x1c)},
         {"Y", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1d)},
         {"Z", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1c)},
         
         // Basic Punctuation
         {"-", USBKeyDefinition(0x38)},
         {"'", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
         {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {",", USBKeyDefinition(0x36)},
         {".", USBKeyDefinition(0x37)},
         {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x36)},
         
         // AltGr (Right Alt) Combinations
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x05)},
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x06)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x09)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x0a)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x11)},
         {"\\", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x14)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x19)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1a)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1b)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1d)},
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1e)},
         {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
         {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
         {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x33)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x38)},
         {"<", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x64)},
     }},

#endif
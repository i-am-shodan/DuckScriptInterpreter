#pragma once

// language: Norwegian (Norway)
#ifdef LOCALE_win_no

    {"win_no",
     {
         // Norwegian special characters
         {"æ", USBKeyDefinition(0x34)},
         {"Æ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
         {"ø", USBKeyDefinition(0x33)},
         {"Ø", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"å", USBKeyDefinition(0x30)},
         {"Å", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},

         // Basic symbols
         {"+", USBKeyDefinition(0x2d)},
         {"\\", USBKeyDefinition(0x2e)},
         {"'", USBKeyDefinition(0x31)},
         {"|", USBKeyDefinition(0x35)},
         {"-", USBKeyDefinition(0x38)},
         {"<", USBKeyDefinition(0x64)},
         {".", USBKeyDefinition(0x37)},
         {",", USBKeyDefinition(0x36)},

         // Shift-modified symbols
         {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"¤", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"`", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},

         // AltGr (Right Alt) combinations
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1f)},
         {"£", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
         {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
         {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x22)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x24)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x25)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x26)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x27)},
         {"µ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x10)},
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x30)},
     }},

#endif
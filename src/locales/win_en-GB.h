#pragma once

// language: English (United Kingdom)
#ifdef LOCALE_win_en_GB

    {"win_en-GB",
     {   
         // Basic characters that differ from US layout
         {"#", USBKeyDefinition(0x31)},                                    
         {"\\", USBKeyDefinition(0x64)},
         {"£", USBKeyDefinition(0x20)},
         
         // Shift combinations
         {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
         {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
         {"<", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         
         // AltGr (Right Alt) combinations
         {"¦", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x64)},
         {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
         {"µ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x10)},
         
         // Regular punctuation
         {"-", USBKeyDefinition(0x2d)},
         {"=", USBKeyDefinition(0x2e)},
         {"[", USBKeyDefinition(0x2f)},
         {"]", USBKeyDefinition(0x30)},
         {";", USBKeyDefinition(0x33)},
         {"'", USBKeyDefinition(0x34)},
         {"`", USBKeyDefinition(0x35)},
         {",", USBKeyDefinition(0x36)},
         {".", USBKeyDefinition(0x37)},
         {"/", USBKeyDefinition(0x38)},
     }},

#endif
#pragma once

#ifdef LOCALE_win_it

    {"win_it",
     {
         {"'", USBKeyDefinition(0x2d)},
         {"+", USBKeyDefinition(0x30)},
         {"\\", USBKeyDefinition(0x35)},
         {"-", USBKeyDefinition(0x38)},
         {"<", USBKeyDefinition(0x64)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1f)},
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {"=", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
         {";", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {">", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         {"[", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x2f)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::ShiftAltGr, 0x2f)},
         {"]", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x30)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::ShiftAltGr, 0x30)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x33)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x34)},
         {"~", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x34)},
     }},

#endif
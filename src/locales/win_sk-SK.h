#pragma once

// language: Slovak (Slovakia)
#ifdef LOCALE_win_sk_SK

    {"win_sk-SK",
     {
         // Slovak Special Characters - Lowercase
         {"á", USBKeyDefinition(0x1e)},
         {"ä", USBKeyDefinition(0x20)},
         {"č", USBKeyDefinition(0x21)},
         {"ď", USBKeyDefinition(0x22)},
         {"é", USBKeyDefinition(0x23)},
         {"ě", USBKeyDefinition(0x24)},
         {"í", USBKeyDefinition(0x25)},
         {"ň", USBKeyDefinition(0x26)},
         {"ó", USBKeyDefinition(0x27)},
         {"ô", USBKeyDefinition(0x28)},
         {"ř", USBKeyDefinition(0x29)},
         {"š", USBKeyDefinition(0x2a)},
         {"ť", USBKeyDefinition(0x2b)},
         {"ú", USBKeyDefinition(0x2c)},
         {"ý", USBKeyDefinition(0x2d)},
         {"ž", USBKeyDefinition(0x2e)},

         // Slovak Special Characters - Uppercase
         {"Á", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"Ä", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"Č", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"Ď", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"Ě", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"Í", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {"Ň", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {"Ó", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         {"Ô", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x28)},
         {"Ř", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x29)},
         {"Š", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2a)},
         {"Ť", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2b)},
         {"Ú", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
         {"Ý", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
         {"Ž", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},

         // Symbols
         {"+", USBKeyDefinition(0x1e)},
         {"=", USBKeyDefinition(0x2d)},
         {";", USBKeyDefinition(0x35)},
         {"-", USBKeyDefinition(0x38)},
         {",", USBKeyDefinition(0x36)},
         {".", USBKeyDefinition(0x37)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x37)},
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
     }},

#endif
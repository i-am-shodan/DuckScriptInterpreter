#pragma once

// language: Portuguese (Brazil)
#ifdef LOCALE_win_pt_BR
    {"win_pt-BR",
     {
         // Special Brazilian Characters - Lowercase
         {"ç", USBKeyDefinition(0x33)},
         {"á", USBKeyDefinition(0x1e)},
         {"é", USBKeyDefinition(0x20)},
         {"í", USBKeyDefinition(0x21)},
         {"ó", USBKeyDefinition(0x22)},
         {"ú", USBKeyDefinition(0x23)},
         {"ã", USBKeyDefinition(0x24)},
         {"õ", USBKeyDefinition(0x25)},
         {"â", USBKeyDefinition(0x2c)},
         {"ê", USBKeyDefinition(0x2e)},
         {"ô", USBKeyDefinition(0x2f)},
         
         // Special Brazilian Characters - Uppercase
         {"Ç", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
         {"Á", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1e)},
         {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"Í", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"Ó", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"Ú", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"Ã", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"Õ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {"Â", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2c)},
         {"Ê", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
         {"Ô", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},

         // Basic Punctuation
         {".", USBKeyDefinition(0x37)},
         {",", USBKeyDefinition(0x36)},
         {";", USBKeyDefinition(0x38)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
         {"'", USBKeyDefinition(0x35)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
         
         // Math Symbols
         {"-", USBKeyDefinition(0x2D)},
         {"=", USBKeyDefinition(0x2E)},
         {"+", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2E)},
         {"*", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x25)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x14)},
         
         // Brackets and Braces
         {"[", USBKeyDefinition(0x30)},
         {"]", USBKeyDefinition(0x31)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {"(", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x26)},
         {")", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x27)},
         
         // Special Symbols
         {"_", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2D)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1a)},
         {"!", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1E)},
         {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x1F)},
         {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x20)},
         {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x21)},
         {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x22)},
         {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x23)},
         {"&", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x24)},
         {"`", USBKeyDefinition(0x2c)},
         {"\\", USBKeyDefinition(0x64)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
     }},
#endif
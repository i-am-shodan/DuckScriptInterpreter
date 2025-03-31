#pragma once

// Language: Spanish (Mexico)
#ifdef LOCALE_win_es_MX

    {"win_es-MX",
     { 
        // Spanish (Mexico) Special Characters - Lowercase
        {"á", USBKeyDefinition(0x2d)},
        {"é", USBKeyDefinition(0x2e)},
        {"í", USBKeyDefinition(0x2f)},
        {"ó", USBKeyDefinition(0x30)},
        {"ú", USBKeyDefinition(0x31)},
        {"ü", USBKeyDefinition(0x32)},
        {"ñ", USBKeyDefinition(0x33)},
        {"ç", USBKeyDefinition(0x34)},
        
        // Spanish (Mexico) Special Characters - Uppercase
        {"Á", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2d)},
        {"É", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
        {"Í", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
        {"Ó", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
        {"Ú", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
        {"Ü", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x32)},
        {"Ñ", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x33)},
        {"Ç", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x34)},
        
        // Spanish Punctuation and Symbols
        {"¡", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2f)},
        {"¿", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x36)},
        {"`", USBKeyDefinition(0x35)},
        {"¨", USBKeyDefinition(0x37)},
        {"^", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x2e)},
        
        // Special Symbols (AltGr combinations)
        {"@", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1f)},
        {"$", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x20)},
        {"%", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x21)},
        {"#", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x22)},
        {"€", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x08)},
        {"°", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x0c)},
        {"¨", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x30)},

     }},

#endif
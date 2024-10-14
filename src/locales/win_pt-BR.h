#pragma once

#ifdef LOCALE_win_pt_BR
    {"win_pt-BR",
     {
         {"^", USBKeyDefinition(0x2c)},
         {"~", USBKeyDefinition(0x2c)},
         {"?", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x1a)},
         {"]", USBKeyDefinition(0x31)},
         {"|", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x64)},
         {"{", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x30)},
         {"`", USBKeyDefinition(0x2c)},
         {"/", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::RightAlt, 0x14)},
         {"[", USBKeyDefinition(0x30)},
         {"'", USBKeyDefinition(0x35)},
         {"\"", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x35)},
         {"\\", USBKeyDefinition(0x64)},
         {"}", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x31)},
         {";", USBKeyDefinition(0x38)},
         {":", USBKeyDefinition(USBKeyDefinition::UsbHidModifiers::LeftShift, 0x38)},
     }},
#endif
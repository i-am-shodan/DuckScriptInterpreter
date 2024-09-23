/*
Copyright (c) 2024 i-am-shodan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>

#include "DuckyParse.h"
#include "Logging.h"

template <typename T>
std::string int_to_hex(T i) {
    std::stringstream stream;
    stream << "0x" << std::setfill('0') << std::setw(sizeof(T) * 2) << std::hex << i;
    return stream.str();
}

std::string testString = "";

std::string readLineFromFile(const std::string& filename, int lineNumber)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return ""; // Return an empty string to indicate failure
    }

    std::string line;
    for (int i = 0; i <= lineNumber; ++i) {
        if (!std::getline(file, line)) {
            //std::cerr << "Error reading line " << lineNumber << " from file: " << filename << std::endl;
            return ""; // Return an empty string to indicate failure
        }
    }

    //std::cerr << "Returning line line " << lineNumber << " from file: " << filename << std::endl;
    return line;
}

std::vector<uint8_t> lastPressedKeys;
uint8_t lastModifier;

void keyboard_press(uint8_t modifiers, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t key6)
{
    if (modifiers & (uint8_t)USBKeyDefinition::UsbHidModifiers::LeftShift)
    {
        testString += "P" + std::to_string(DuckyInterpreter::SHIFT_KEY);
    }
    if (modifiers & (uint8_t)USBKeyDefinition::UsbHidModifiers::LeftGui)
    {
        testString += "P" + std::to_string(0xe3);
    }
    if (modifiers & (uint8_t)USBKeyDefinition::UsbHidModifiers::LeftControl)
    {
        testString +=  "P" + std::to_string(0xe0);
    }
    if (modifiers & (uint8_t)USBKeyDefinition::UsbHidModifiers::LeftAlt)
    {
        testString +=  "P" + std::to_string(0xe2);
    }

    lastModifier = modifiers;

    if (key1 != 0) { lastPressedKeys.emplace_back(key1); testString += "P" + std::to_string(key1); }
    if (key2 != 0) { lastPressedKeys.emplace_back(key2); testString += "P" + std::to_string(key2); }
    if (key3 != 0) { lastPressedKeys.emplace_back(key3); testString += "P" + std::to_string(key3); }
    if (key4 != 0) { lastPressedKeys.emplace_back(key4); testString += "P" + std::to_string(key4); }
    if (key5 != 0) { lastPressedKeys.emplace_back(key5); testString += "P" + std::to_string(key5); }
    if (key6 != 0) { lastPressedKeys.emplace_back(key6); testString += "P" + std::to_string(key6); }
}

void keyboard_release()
{
    for(uint8_t key : lastPressedKeys)
    {
        testString += "R" + std::to_string(key);
    }

    if (lastModifier & (uint8_t)USBKeyDefinition::UsbHidModifiers::LeftShift)
    {
        testString += "R" + std::to_string(DuckyInterpreter::SHIFT_KEY);
    }
    if (lastModifier & (uint8_t)USBKeyDefinition::UsbHidModifiers::LeftGui)
    {
        testString += "R" + std::to_string(0xe3);
    }
    if (lastModifier & (uint8_t)USBKeyDefinition::UsbHidModifiers::LeftControl)
    {
        testString +=  "R" + std::to_string(0xe0);
    }
    if (lastModifier & (uint8_t)USBKeyDefinition::UsbHidModifiers::LeftAlt)
    {
        testString +=  "R" + std::to_string(0xe2);
    }

    lastPressedKeys.clear();
    lastModifier = 0;
}

void changeLEDState(bool on, uint8_t h, uint8_t s, uint8_t l, uint8_t b)
{
    if (on)
    {
        testString += "LEDON";
    }
    else
    {
        testString += "LEDOFF";
    }
}

void waitForButton()
{
    testString += "WAITB";
}

const std::map<DuckyInterpreter::USB_MODE, std::string> USBMAP{
    {DuckyInterpreter::USB_MODE::HID, "HID"},
    {DuckyInterpreter::USB_MODE::STORAGE, "STORAGE"},
    {DuckyInterpreter::USB_MODE::OFF, "OFF"}
};

std::string ToString(DuckyInterpreter::USB_MODE c) {
    auto it = USBMAP.find(c);
    return (it != USBMAP.end()) ? it->second : "HID_STORAGE";
}

void changeUSBMode(const DuckyInterpreter::USB_MODE mode, const uint16_t& vid, const uint16_t& pid, const std::string& man, const std::string& prod, const std::string& serial)
{
    testString += ToString(mode) + int_to_hex(vid) + "_" + int_to_hex(pid) + "_" + man + "_" + prod + "_" + serial;
}

void delay(uint32_t timeInMS)
{
    //char temp[20] = {};
    //itoa(timeInMS, temp, 10);
    std::string temp = std::to_string(timeInMS);
    testString += "D" + temp;
}

void reset()
{
    testString += "RESET";
}

int func1(const std::string& str, std::unordered_map<std::string, std::string> constants, std::unordered_map<std::string, int> variables) {
    testString += "FUNC1";
    return true;
}

int func2(const std::string& str, std::unordered_map<std::string, std::string> constants, std::unordered_map<std::string, int> variables) {
    testString += "FUNC2";
    return 1;
}

int func3(const std::string& str, std::unordered_map<std::string, std::string> constants, std::unordered_map<std::string, int> variables) {
    testString += "FUNC3";
    return 0;
}

static int count = 0;
int trueFiveTimes(const std::string& str, std::unordered_map<std::string, std::string> constants, std::unordered_map<std::string, int> variables) {
    auto ret = count < 5;
    count++;
    return ret;
}

int neverTrue(const std::string& str, std::unordered_map<std::string, std::string> constants, std::unordered_map<std::string, int> variables) {
    return 0;
}

static bool set = false;
int trueOnce(const std::string& str, std::unordered_map<std::string, std::string> constants, std::unordered_map<std::string, int> variables) {
    if (set == false)
    {
        set = true;
        return 1;
    }
    return 0;
}

void runTest(int id, std::string filename, std::string output)
{
    std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> extCommands;
    std::vector<std::function<std::pair<std::string, std::string>()>> consts;
    extCommands["FUNC1()"] = func1;
    extCommands["FUNC2()"] = func2;
    extCommands["FUNC3()"] = func3;
    extCommands["TRUE_FIVE_TIMES()"] = trueFiveTimes;
    extCommands["NEVER_TRUE()"] = neverTrue;
    extCommands["TRUE_ONCE()"] = trueOnce;

    consts.emplace_back([] {
        return std::pair("#DYNAMICVAR1", "a");
    });

    DuckyInterpreter ducky = DuckyInterpreter(
        delay, 
        readLineFromFile, 
        keyboard_press, 
        keyboard_release, 
        changeLEDState, 
        waitForButton, 
        changeUSBMode,
        reset);

    testString = "";
    int lineNum = 0;
    do
    {
        lineNum = ducky.Execute(filename, lineNum, extCommands, consts);
    } while (lineNum != DuckyInterpreter::END_OF_FILE && lineNum != DuckyInterpreter::SCRIPT_ERROR);

    if (lineNum == DuckyInterpreter::END_OF_FILE && testString == output) { printf("[%d] - PASSED\n", id); } else { printf("[%d] - FAILED\n", id); }     
}

int main(void) {

    runTest(1, "examples/basic.txt", "D5000P4R4");
    runTest(2, "examples/basic2.txt", "D3P225P11R11R225P8R8P15R15P15R15P18R18P225P30R30R225P40R40");
    runTest(3, "examples/basic3.txt", "P227P62R62R227P226P61R61R226P224P21R21R224P225P224P40R40R225R224P79R79P77R77");
    runTest(4, "examples/basic4.txt", "P227R227P227P21R21R227P227P21R21R227");
    runTest(5, "examples/constants_are_replaced.txt", "P56R56P4R4P55R55P7R7P22R22P44R44P30R30P31R31P32R32P44R44P225P52R52R225P225P33R33R225P225P30R30R225");
    runTest(6, "examples/system_defined_functions.txt", "FUNC1FUNC2");
    runTest(7, "examples/basic_if.txt", "P4R4P5R5P6R6P7R7P8R8P9R9P10R10P11R11P12R12");
    runTest(8, "examples/if_with_function_call.txt", "FUNC1P4R4FUNC3P5R5");
    runTest(9, "examples/complex_if.txt", "P4R4P4R4");
    runTest(10, "examples/usb.txt", "HID0x05ac_0x021e_HAK5_DUCKY_1337HID0x0000_0x0000_USB Input Device_USB Input Device_111111111111STORAGE0x0000_0x0000_USB Input Device_USB Input Device_111111111111HID_STORAGE0x0000_0x0000_USB Input Device_USB Input Device_111111111111");
    runTest(11, "examples/while_loops.txt", "D1FUNC1FUNC2FUNC1FUNC1FUNC2FUNC1FUNC2FUNC1FUNC2FUNC1FUNC2D2D3");
    runTest(12, "examples/constants_are_replaced_with_runtime_defined_values.txt", "P4R4");
    runTest(13, "examples/if_else.txt", "P4R4P4R4P4R4P4R4P4R4");
    runTest(13, "examples/variables.txt", "P4R4P4R4P4R4");

    //printf("OUTSTR = '%s'\r\n", testString.c_str());
}
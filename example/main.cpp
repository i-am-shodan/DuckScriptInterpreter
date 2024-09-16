#define LOGGING

#include <string>
#include <vector>

#include "DuckyParse.h"
#include "Logging.h"

static void changeUSBMode(const DuckyInterpreter::USB_MODE mode, const uint16_t& vid, const uint16_t& pid, const std::string& man, const std::string& prod, const std::string& serial)
{
    // Add your code to change what USB you are running in
}

static void delay(uint32_t timeInMS)
{
    // Add your code to wait a while
    printf("Waiting %d\n", timeInMS);
}

static void waitForButton()
{
    // Add your code to wait for a button press
}

static void changeLEDState(bool on, uint8_t h, uint8_t s, uint8_t l, uint8_t b)
{
    // Add your code to change the LED colour
}

static void keyboard_press(uint8_t modifiers, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t key6)
{
    // variables key1...key6 are USB keypress values. They are NOT ASCII characters.
    // Below I do a a quick and dirty hack by adding 0x5d. This moves a few characters into the ASCII range so I print it on screen
    // Do not do this!
    std::string text;

    if (key1 != 0) { text += (char) (key1 + 0x5d); }
    if (key2 != 0) { text += (char) (key2 + 0x5d); }
    if (key3 != 0) { text += (char) (key3 + 0x5d); }
    if (key4 != 0) { text += (char) (key4 + 0x5d); }
    if (key5 != 0) { text += (char) (key5 + 0x5d); }
    if (key6 != 0) { text += (char) (key6 + 0x5d); }

    printf("%s", text.c_str());
}

static void keyboard_release()
{
    // Release any pressed keys
}

void reset()
{
}

static std::string readLineFromFile(const std::string& filename, int lineNumber)
{
    std::vector<std::string> script = {
        "REM This is a test script",
        "STRING helloworld",
        "FLASH_WARNING()",
        "DELAY 2000",
        "FIRE_MISSLES"
    };

    if (lineNumber < script.size())
    {
        return script[lineNumber];
    }

    return ""; // A completely empty string indicates EOF 
}

static int fire_missles_custom_function(const std::string& str, std::unordered_map<std::string, std::string> constants, std::unordered_map<std::string, int> variables) {
    printf("Firing missiles!!!!\n");
    return true;
}

static int flash_warning_custom_function(const std::string& str, std::unordered_map<std::string, std::string> constants, std::unordered_map<std::string, int> variables) {
    printf("\nWARNING WARNING WARNING\n");
    return true;
}

int main(void) {

    DuckyInterpreter ducky = DuckyInterpreter(
        delay, 
        readLineFromFile, 
        keyboard_press, 
        keyboard_release, 
        changeLEDState, 
        waitForButton, 
        changeUSBMode,
        reset);

    std::unordered_map<std::string, std::function<int(std::string, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>)>> extCommands;
    extCommands["FIRE_MISSLES"] = fire_missles_custom_function;
    extCommands["FLASH_WARNING()"] = flash_warning_custom_function;

    int lineNum = 0;
    do
    {
        lineNum = ducky.Execute("put your read filename here", lineNum, extCommands);
    } while (lineNum != DuckyInterpreter::END_OF_FILE && lineNum != DuckyInterpreter::SCRIPT_ERROR);

    if (lineNum == DuckyInterpreter::SCRIPT_ERROR)
    {
        printf("A script error occured!\n");
    }

    return 0;
}
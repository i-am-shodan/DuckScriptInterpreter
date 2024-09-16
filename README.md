# DuckScriptInterpreter

DuckScriptInterpreter is a C++ interpreter for files written in a Ducky like language. It is intended for use as a library in embedded systems (e.g ESP32). As such the implementation of specific actions, such as turning LEDs on or pressing keys, needs to be provided by the caller. The interpreter is highly extendable, allowing users to define their own DuckyScript commands.

## Features
- Parses and executes Ducky-like script files.
- Designed for embedded systems.
- Easily extendable with user-defined functionality.
- Supports control flow constructs, repetition, functions, and extensions.

## Installation
To include DuckScriptInterpreter in your project, clone the repository and include the necessary files in your build system.

```sh
git clone https://github.com/i-am-shodan/DuckScriptInterpreter
cd DuckScriptInterpreter/example
chmod run.sh
./run.sh
```

## Usage
Include the DuckScriptInterpreter library in your project and implement the required hardware-specific functions.

### Supported Functionality
* DELAY
* STRING
* STRINGLN
* System keypresses (GUI, LSHIFT etc)
* WAIT_FOR_BUTTON_PRESS
* LED functions including LED_ON, LED_OFF, LED_R ,LEDG
* REM
* IF
* WHILE
* DEFINE
* ATTACKMODE

### Planned Functionality but not yet implemented
* INJECT_MOD WINDOWS
* BUTTON_DEF
* DISABLE_BUTTON
* ENABLE_BUTTON
* VAR
* ELSE
* RANDOM
* HOLD RELEASE
* RESTART_PAYLOAD
* STOP_PAYLOAD
* RESET
* JITTER
* WAIT_FOR_CAPS_ON
* SAVE_HOST_KEYBOARD_LOCK_STATE

Unit tests are provided in the `tests/` directory. A simple example that can be run on a desktop machine is provided in the `example/` directory. This example demonstrates basic usage of the DuckScriptInterpreter library.

# License
This project is licensed under the MIT License. See the LICENSE file for details.

# Legal

For clarity this project is neither endorsed or supported by Hak5.
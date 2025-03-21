#!/bin/bash

rm my_program > /dev/null 2>&1
rm test_main.o > /dev/null 2>&1
rm DuckyParse.o > /dev/null 2>&1
g++ -std=gnu++2a -c ../../src/DuckyParse.cpp -DDUCKY_LOG_INTERNAL -DLOCALE_win_en_GB
g++ -std=gnu++2a -c test_main.cpp -o test_main.o -I../../src/ -DDUCKY_LOG_INTERNAL -DLOCALE_win_en_GB
g++ -std=gnu++2a test_main.o DuckyParse.o -o my_program -DDUCKY_LOG_INTERNAL -DLOCALE_win_en_GB
./my_program

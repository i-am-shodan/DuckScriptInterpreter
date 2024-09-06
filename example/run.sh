#!/bin/bash

g++ -std=gnu++2a -c ../src/DuckyParse.cpp -DLOGGING
g++ -std=gnu++2a -c main.cpp -o main.o -I../src/
g++ -std=gnu++2a main.o DuckyParse.o -o example

rm example.o > /dev/null 2>&1
rm main.o > /dev/null 2>&1
rm DuckyParse.o > /dev/null 2>&1

./example
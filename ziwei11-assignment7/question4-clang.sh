#!/bin/bash
clang -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 $* -o question4 question4.c && ./question4


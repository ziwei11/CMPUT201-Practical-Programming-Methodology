#!/bin/bash
clang -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 $* -o question3 question3.c && ./question3


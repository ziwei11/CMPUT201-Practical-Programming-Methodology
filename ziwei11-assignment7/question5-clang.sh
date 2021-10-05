#!/bin/bash
clang -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 $* -o question5 question5.c && ./question5


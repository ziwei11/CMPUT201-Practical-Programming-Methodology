#!/bin/bash
clang-tidy --checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp question7.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 $* -o question7 question7.c
oclint --disable-rule=UselessParentheses question7.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 $* -o question7 question7.c

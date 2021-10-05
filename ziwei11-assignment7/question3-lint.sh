#!/bin/bash
clang-tidy --checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp question3.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question3 question3.c
oclint --disable-rule=UselessParentheses question3.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question3 question3.c

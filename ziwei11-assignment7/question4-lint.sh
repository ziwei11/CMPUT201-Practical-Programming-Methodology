#!/bin/bash
clang-tidy --checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp question4.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question4 question4.c
oclint --disable-rule=UselessParentheses question4.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question4 question4.c

#!/bin/bash
clang-tidy --checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp question5.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question5 question5.c
oclint --disable-rule=UselessParentheses question5.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question5 question5.c

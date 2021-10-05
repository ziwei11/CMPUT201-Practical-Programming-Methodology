#!/bin/bash
clang-tidy --checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp question6.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 $* -o question6 question6.c
oclint --disable-rule=UselessParentheses question6.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 $* -o question6 question6.c

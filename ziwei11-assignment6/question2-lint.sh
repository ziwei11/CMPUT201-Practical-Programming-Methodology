#!/bin/bash
clang-tidy --checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp question2.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question2 question2.c
oclint --disable-rule=UselessParentheses question2.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question2 question2.c

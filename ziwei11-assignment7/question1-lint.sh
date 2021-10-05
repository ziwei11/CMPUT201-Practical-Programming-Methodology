#!/bin/bash
clang-tidy --checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp question1.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question1 question1.c
oclint --disable-rule=UselessParentheses question1.c -- -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o question1 question1.c

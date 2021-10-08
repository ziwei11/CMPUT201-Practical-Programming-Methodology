#  CMPUT201W20 Final Exam Question 5 (Makefile)
#   
#  NAME: Vicky Zhao
#  CCID: ziwei11
#  STUDENT NUMBER: 1593071
# 
#  Finish this Makefile to get all the tests working.
#  See final.md for details!

GCC=gcc
CC=$(GCC)
ARCH?=-m64
CLANG=clang
EXTRA ?= 
CFLAGS=-std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 $(ARCH) $(EXTRA)
LDLIBS+=
LDFLAGS=$(ARCH)
CHECKS=--checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp \
	--warnings-as-errors=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp
LINTR=--disable-rule=UselessParentheses -max-priority-1=0 -max-priority-2=0  -max-priority-3=0 
CLANGTIDY=clang-tidy
OCLINT=oclint
VFLAGS=--leak-check=full --track-origins=yes
QUESTIONS=question1 question2 question3 question4 
TESTS=question1_test question2_test question3_test question4_test 
OBJECTS=
# 

default: tests

.PHONY: default tests valgrinds lints clean

lint-%.c: %.c
	$(CLANGTIDY) $(CHECKS) \
		$< -- \
		$(CFLAGS) -o $<
	$(OCLINT) $(LINTR) $< \
		-- $(CFLAGS) -o $<

lints: lint-myfloat.c lint-myfloat_ops.c lint-myfloat_conv.c purefloat_ops.c


# 

valgrind-question%_test: question%_test
	valgrind $(VFLAGS) ./$<

valgrinds: valgrind-question1_test valgrind-question2_test valgrind-question3_test valgrind-question4_test

run-question%_test: question%_test
	./$<

tests: run-question1_test run-question2_test run-question3_test run-question4_test

clean:
	rm -f $(TESTS)
	# 

# pass the tests on 32bit arch
x86tests:
	make ARCH=-m32 clean tests

# pass the tests with clang
clangtests:
	make GCC=clang clean tests


# if you can pass this you are probably done the exam
everything: tests lints valgrinds x86tests clangtests


myfloat.o: myfloat.c myfloat.h
	$(CC) $(CFLAGS) -c myfloat.c


question1_test.o: question1_test.c myfloat.h test.h
	$(CC) $(CFLAGS) -c question1_test.c


question1_test: question1_test.o myfloat.o 
	$(CC) $(CFLAGS) myfloat.o question1_test.o -o question1_test




myfloat_ops.o: myfloat_ops.h myfloat_ops.c myfloat.h
	$(CC) $(CFLAGS) -c myfloat_ops.c


question2_test.o: question2_test.c myfloat_ops.h test.h
	$(CC) $(CFLAGS) -c question2_test.c


question2_test: myfloat.o myfloat_ops.o question2_test.o
	$(CC) $(CFLAGS) myfloat.o myfloat_ops.o question2_test.o -o question2_test




myfloat_conv.o: myfloat.h myfloat_conv.h myfloat_conv.c
	$(CC) $(CFLAGS) -c myfloat_conv.c


question3_test.o: question3_test.c myfloat_conv.h test.h
	$(CC) $(CFLAGS) -c question3_test.c


question3_test: myfloat.o myfloat_conv.o question3_test.o
	$(CC) $(CFLAGS) myfloat.o myfloat_conv.o question3_test.o -o question3_test 




purefloat_ops.o: myfloat_ops.h purefloat_ops.c myfloat.h
	$(CC) $(CFLAGS) -c purefloat_ops.c


question4_test.o: question4_test.c
	$(CC) $(CFLAGS) -c question4_test.c


question4_test: purefloat_ops.o myfloat.o question4_test.o test.h
	$(CC) $(CFLAGS) purefloat_ops.o question4_test.o myfloat.o -o question4_test 






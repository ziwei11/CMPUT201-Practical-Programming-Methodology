CC=gcc
GCC=gcc
CLANG=clang
CFLAGS=-std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3
LDFLAGS=$(CFLAGS)
CHECKS=--checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp
LINTR=--disable-rule=UselessParentheses
CLANGTIDY=clang-tidy
OCLINT=oclint
Q1ADIFF=q1a-test1-diff q1a-test2-diff q1a-test3-diff q1a-test4-diff q1a-test5-diff q1a-test6-diff q1a-test7-diff q1a-test8-diff
Q1BFAIL=q1b-test1-fail q1b-test2-fail
VFLAGS=--leak-check=full --track-origins=yes

//.PHONY: q1a run-parameters-test lint-parameters lint-parameters-test run-question1 valgrind-question1 lint-%.c tests 

# you need to compile parameters.o and parameters-test.o here
parameters.o: parameters.c parameters.h
	$(CC) $(CFLAGS) -c parameters.c


parameters-test.o: parameters-test.c parameters.h
	$(CC) $(CFLAGS) -c parameters-test.c


# you need to compile ppd.o and ppd-test.o here
ppd.o: ppd.c parameters.h ppd.h
	$(CC) $(CFLAGS) -c ppd.c


ppd-test.o: ppd-test.c parameters.h ppd.h
	$(CC) $(CFLAGS) -c ppd-test.c


lint-question1: question1.c combo.o parameters.o
	$(CLANGTIDY) $(CHECKS) \
		$< -- \
		$(CFLAGS) -c $^ $(LDFLAGS)	
	$(OCLINT) $(LINTR) parameters-test.c \
		-- $(CFLAGS) -c $^ $(LDFLAGS)

lint-%.c: %.c
	$(CLANGTIDY) $(CHECKS) \
		$< -- \
		$(CFLAGS) -o $<
	$(OCLINT) $(LINTR) $< \
		-- $(CFLAGS) -o $<


run-question1: question1
	./question1


valgrind-question1: question1
	valgrind --leak-check=full --track-origins=yes ./question1


# you need to compile combo.o from combo.c and combo.h
# if combo.h is modified combo.o must be recompiled
combo.o: combo.c parameters.h combo.h
	$(CC) $(CFLAGS) -c combo.c


combo-test.o: combo-test.c parameters.h combo.h
	$(CC) $(CFLAGS) -c combo-test.c


# you need to build:
# - parameters-test
parameters-test: parameters-test.o parameters.o
	$(CC) $(CFLAGS) parameters-test.o parameters.o -o parameters-test


# - combo-test
combo-test: combo-test.o combo.o parameters.o
	$(CC) $(CFLAGS) combo-test.o combo.o parameters.o -o combo-test


# - ppd-test
ppd-test: ppd-test.o ppd.o parameters.o
	$(CC) $(CFLAGS) ppd-test.o ppd.o parameters.o -o ppd-test


# - question1
# you need to compile question1.c as question1 properly here
checkinput.o: checkinput.c checkinput.h
	$(CC) $(CFLAGS) -c checkinput.c


question1: question1.o combo.o parameters.o ppd.o checkinput.o
	$(CC) $(CFLAGS) question1.o combo.o parameters.o ppd.o checkinput.o -o question1


question1.o: question1.c checkinput.h parameters.h ppd.h combo.h
	gcc  -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 \
	-c question1.c


valgrind-%: %
	valgrind --leak-check=full --track-origins=yes ./$<

valgrind-q1a-test1: q1a-test1-input.txt question1
	valgrind $(VFLAGS) ./question1 < q1a-test1-input.txt

valgrind-q1a-test2: q1a-test2-input.txt question1
	valgrind $(VFLAGS) ./question1 < q1a-test2-input.txt

valgrind-q1a-test3: q1a-test3-input.txt question1
	valgrind $(VFLAGS) ./question1 < q1a-test3-input.txt

valgrind-q1a-test4: q1a-test4-input.txt question1
	valgrind $(VFLAGS) ./question1 < q1a-test4-input.txt

valgrind-q1a-test: q1a-test5-input.txt question1
	valgrind $(VFLAGS) ./question1 < q1a-test5-input.txt

%-output.txt: %-input.txt question1
	./question1 < $< > $@

%-fail: %-input.txt question1
	./question1 < $< > $*-output.txt  ; test $$? -eq 1

%-diff: %-output.txt
	diff $< $*-expected-output.txt

run-%-test: %-test
	./$<


qtests: $(Q1ADIFF) $(Q1BFAIL)

tests:  run-ppd-test run-parameters-test run-combo-test qtests

lints: lint-checkinput.c  lint-combo-test.c  lint-combo.c  lint-parameters-test.c  lint-parameters.c  lint-ppd-test.c  lint-ppd.c  lint-question1.c  

clean:
	rm -f *.o question1 combo-test ppd-test parameters-test

# Midterm 3 make file
# Version 0.9.7
# make tests # runs the tests and stops on 1st failure
# make lints # lints all the questionX.c files
# make eval # runs all tests and all lints
# make score # runs all tests and all lints but shows score
# make dncs # checks if there are any missing DNC lines
# make valgrind-questionX # runs valgrind on questionX (question1-4)
# make run-questionX # runs questionX (question1-4)
# make clean # deletes all the compiled objects

CC ?= gcc
GCC=gcc
CLANG=clang
# You can provide extra defines with make EXTRA=-DWHATEVER
# e.g. EXTRA=-fsanitize=address
EXTRA ?=
# Relatively pedantic
CFLAGS=-std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 $(EXTRA)
# Link with math
LDLIBS+=-lm
CHECKS=--checks=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp \
	--warnings-as-errors=*,-cert-err34-c,-cert-msc30-c,-cert-msc50-cpp
LINTR=--disable-rule=UselessParentheses -max-priority-1=0 -max-priority-2=0  -max-priority-3=0 
CLANGTIDY=clang-tidy
OCLINT=oclint
VFLAGS=--leak-check=full --track-origins=yes
SOURCE=question1.c question2.c question3.c question4.c
OBJECTS=question1 question2 question3 question4
QUESTIONS=question1 question2 question3 question4

# run tests
tests: run-question1 run-question2 run-question3 run-question4

lint-%.c: %.c
	$(CLANGTIDY) $(CHECKS) \
		$< -- \
		$(CFLAGS) -o $<
	$(OCLINT) $(LINTR) $< \
		-- $(CFLAGS) -o $<


# run each question
run-question1: question1
	./$<

run-question2: question2
	./$<

run-question3: question3
	./$<

run-question4: question4
	./$<

# removes objects
clean:
	rm -f $(OBJECTS)

# eval each test regardless of failure
eval:	eval.sh $(OBJECTS)
	bash eval.sh

# just show the scoring
score: eval.sh $(OBJECTS)
	bash eval.sh 2> score.err | grep \"question

# run all the linters
lints: lint-question1.c lint-question2.c lint-question3.c lint-question4.c



# this checks if the DNCs match or not
dnc-%.c: %.c 
	grep DNC $< | diff -b $<.dnc -

DNCS=dnc-question1.c  dnc-question4.c dnc-question3.c  dnc-question2.c

# you must pass this -- it indicates that you didn't disturb our 
# // DNC marked lines

dncs: $(DNCS)

# make valgrind-question1 to valgrind-question1
valgrind-%: %
	valgrind --leak-check=full --track-origins=yes ./$<

# CMPUT201 Assignment 1: Basic C and Bash

* By: Vicky Zhao
* CCID: ziwei11
* Student Number: 1593071

# Sources

Tell us what online resources you used and who you collaborated with:

* __COLLABORATOR_1__
* __StackOverflow_Link__

Reminder: You may not use code from anyone else! Online resources and collaborators are for concepts only.

# Goals

* Demonstrate knowledge of compiling, printf, scanf, fgets, making a shell script, using linux via SSH or VM, making directories and tarballs.

# Part 0: Make a directory called __YOUR_CCID__-assignment1

Dr. Hindle's directory will be called hindle1-assignment1

Hazel's directory will be called hazelcam-assignment1

Now make the rest of the files in that directory

# Part 1: Small C program

Make a C program called assignment1.c that once compiled as
./assignment1 and run interactively query the user and produce the
following output:

```text
Hello World!
I was written by __YOUR_NAME_HERE__
Bridgekeeper: What...is your name?
__YOUR_NAME_HERE__
Bridgekeeper: Ahh your name is __YOUR_NAME_HERE__
Bridgekeeper: What...is your quest?
__YOUR_QUEST_OR_PURPOSE_HERE__
Bridgekeeper: Ahh your purpose is __YOUR_QUEST_OR_PURPOSE_HERE__
Bridgekeeper: What...is your favorite colour?
__YOUR_FAVOURITE_COLOR_HERE__
Bridgekeeper: Ahh your favorite colour is __YOUR_FAVOURITE_COLOR_HERE__
Bridgekeeper: Right, off you go.
```

Use printf (or puts) and scanf (or fgets) to print and read strings. Strings can be 1024 characters long.

Here's Dr. Hindle's interaction:

```text
Hello World!
I was written by Abram Hindle
Bridgekeeper: What...is your name?
abram
Bridgekeeper: Ahh your name is abram
Bridgekeeper: What...is your quest?
to explain assignment 1 to the students
Bridgekeeper: Ahh your purpose is to explain assignment 1 to the students
Bridgekeeper: What...is your favorite colour?
Blue! NO! YELLOOOOOOOOOOOOOOOOWWW!!!!
Bridgekeeper: Ahh your favorite colour is Blue! NO! YELLOOOOOOOOOOOOOOOOWWW!!!!
Bridgekeeper: Right, off you go.
```

Part of this script is derived from Monty Python and the Holy Grail (1975)
directed by Terry Gilliam and Terry Jones.

The program must be of appropriate quality with:
* [ ] proper indentation
* [ ] no warnings
* [ ] must compile 
    * [ ] use `gcc -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 -o assignment1 assignment1.c`

Note: __IDENTIFIERS__ with underscores are meant to be replaced by you and your user input

# Part 2: Small Shell Script

Make a 1 line (excluding the comments and header) shell script that
will compile and run your C program. Make sure the program
successfully compiles the program and then runs it. If the program
doesn't compile it should not run the executable.

The shell program should use 1 operator to achieve this and it should
all fit on the same line. You can assume the shell script is run in
the directory that contains both the source code and the executable.

# Part 2.5: Test it!

Run the test.sh script. It should produce no output

# Part 3: Tar it up!

Make a tar ball of your assignment. name is __YOUR__CCID__-assignment1.tar

the tar ball should contain:
```
__YOUR_CCID__-assignment1/ # the directory
__YOUR_CCID__-assignment1/README.md # this README
__YOUR_CCID__-assignment1/assignment1.c # C program
__YOUR_CCID__-assignment1/assignment1 # executable
__YOUR_CCID__-assignment1/assignment1.sh # shell script
```

Dr. Hindle's assignment1.tar will contain 
```
hindle1-assignment1/ # the directory
hindle1-assignment1/README.md # this README
hindle1-assignment1/assignment1.c # C program
hindle1-assignment1/assignment1 # executable
hindle1-assignment1/assignment1.sh # shell script
```

# Submit it

Upload to eclass!

# Marking

This is a 4 mark assignment.

- Lose all marks if not a tar (a `.tar` file that can be unpacked using `tar -xf`)
- Lose all marks if files not named correctly and inside a correctly named directory (folder)
- Lose 1 mark if `test.sh` doesn't run producing a return 0 and 0 output (program input/output is incorrect)
- Lose 1 mark if quality of C program is inadequate
- Lose 1 mark if compilation produces warnings
- Lose 1 mark if assignment1.sh does not meet the requirements above
- Lose 2 marks if README.md does not contain required information

# LICENSE:

This software is NOT free software. Any derivatives and relevant shared files are under the following license:

Copyright 2020 Abram Hindle, Hazel Campbell

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, and submit for grading and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
* You may not publish, distribute, sublicense, and/or sell copies of the Software.
* You may not share derivatives with anyone except UAlberta staff.
* You may not pay anyone to implement this assignment and relevant code.
* Paid tutors who work on this code owe the Department of Computing Science at the University of Alberta $10000 CAD per derivative.
* By publishing this code publicly said publisher owes the Department of Computing Science at the University of Alberta $10000 CAD.
* You must not engage in plagiarism 

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


# Faiz Mustansar
# CIS*2520 F23 Week 1 Lab

Welcome to CIS2520/Data Structures!

In this course we will explore various data structure strategies using the C programming language, and give you a chance to develop your skills as a C programmer.

## Lab Objective:

The purpose of this lab is to let you get familiar with the tools we will use in this course.  Specifically, in this lab we will examine using:

* `gitlab`: a *repository management* tool that uses [`git(1)`](https://man7.org/linux/man-pages/man1/git.1.html)
* `cc(1)`: the C compiler, which on our Linux machines is [`gcc(1)`](https://man7.org/linux/man-pages/man1/gcc.1.html)
* `make`: our project management tool. The command [`make(1)`](https://man7.org/linux/man-pages/man1/make.1.html) reads a file called "`makefile`" and uses rules within it to build our projects
* **C memory management strategies**: particularly data allocated on the *stack* and the *heap* and the use of **pointers** and **addresses** to describe where we want data to go
* and most critically, **our brains**: our most important tool.  Thinking through how code works, and how it **should** work is essentially to understanding program design and solving problem -- especially *conceptual* and *design* level problems. 

# Lab Activities

## Part 1: Gitlab

This part should only take you a moment or two.  We simply want to take you through the steps of **modifying** a file and **checking the changes in** to your gitlab repository.

Here are the steps:

1) **Modify a file**: add your name at the top of this README file
	* *Why do this?* This action creates a modification to a file.  For labs and assignments in this course you will be submitting your modifications for grading.

2) **Get `git` to pay attention**: At the **command line** on the
	`linux.socs.uoguelph.ca` machine you are using, run 

	`git add README.md`

	* This will add the modified file to the list of files to which you want `git` to pay attention

	* Note that you `add` a file regardless whether you have modified an existing file or created a new file.  The command `add` adds the file to the *list of files to commit*, regardless of whether it is new.


3) **Get `git` to record the changes**: At the **command line**, now run

	`git commit -m "Updated README"`

	* The `-m` option allows you to supply a message on the command line, which describes the changes.  A more in-depth discussion of how to supply good `git` messages will be given in the coming weeks.

	* Files that have been `commit`ted are checked in to the *local* git repo in your working directory.  They are **NOT** in the `gitlab` repo yet.

	* You can use several `commit` operations to record messages for different files you have modified if you wish.

4) **Tell `git` to update gitlab with the changes**: Now at the command
	line, run this command:

	`git push`

	* This should result in messages somewhat like this:

	```
		Enumerating objects: 5, done.
		Counting objects: 100% (5/5), done.
		Delta compression using up to 8 threads
		Compressing objects: 100% (3/3), done.
		Writing objects: 100% (3/3), 335 bytes | 335.00 KiB/s, done.
		Total 3 (delta 2), reused 0 (delta 0), pack-reused 0
		To https://gitlab.socs.uoguelph.ca/ahamil01/2520w23-l01.git
		   b631dae..442b24a  main -> main
	```

	* Specifically, you should see on the `Writing objects:` line that
	you got to 100% and that the process is `done`.  If there is an error,
	please ask a TA for help.

	* This `push` operation takes all the changes that you have `commit`ted and updates the gitlab repo with these.  They will then be available to anyone with whom you share this repo -- in the case of this course, this will be the teaching staff.

	* It is important that you are comfortable doing these `commit` and `push` operations because this is how you will be submitting your assignments and labs.  Code that you have `push`ed can be viewed by the TAs which may also be useful when asking for help.


## Part 2: C programming

You have been given a C program that has a memory error.  It is a pretty
common memory error, so the intention of this portion of the lab is
to help you recognize when this kind of error is happening, and more
importantly recognize what to do about it.

* To see the error, we first must build and run the program.

* The program is **supposed** to parse a file of numbered lines,
	separating the number from the data using the delimiter '`:`',
	and load them into a table

* In reality, there is a memory (pointer) error.  **Your job is to
	find and fix this error.**

### Building the program

* We do this using `make`.  Simply type `make` at the command line.
* You should see this output:

	```
	$ make
	cc -g   -c -o avParser.o avParser.c
	cc -g   -c -o mainline.o mainline.c
	cc -g -o lab1 avParser.o mainline.o
	```

	* We see the `cc` command (which on Linux is an alias for [`gcc(1)`](https://man7.org/linux/man-pages/man1/gcc.1.html)) being run three times.

	* The first two times we are compiling the files `avParser.c` and `mainline.c` to produce object files with machine instructions instead of C source code.

	* The third file combines these two object files together to make an executable program file.

* Run the [`ls(1)`](https://man7.org/linux/man-pages/man1/ls.1.html) command which will show you the following listing

	```
	$ ls
	README.md               foo                     makefile
	dataReader.c            lab1                    test-using-valgrind
	dataReader.h            mainline.c              tinydata.txt
	dataReader.o            mainline.o              twentyentries.txt
	```

	* You can see that there are `.c` files, a `.h` header file, and `.o` object files along with the program executable file `lab1`.

	* The `lab1` file is *meant* to print out all the key/value pairs in 

* We can run the `lab1` file by using the following command:

	```
	./lab1 tinydata.txt
	```

### Recognizing the problem

There is a **very common memory error** in this program.  If you think about that kind of errors people commonly make, you should be able to easily fix the program.

* The program is **supposed** to print this output:

	```
	DBG: "read" read line:
		1 : apple is Malus
	DBG: "read" - key and value are '1/ apple is Malus'
	DBG: in "load" have content '1/ apple is Malus'
	DBG: "read" read line:
		2 : banana is Musa     
	DBG: "read" - key and value are '2/ banana is Musa'
	DBG: in "load" have content '2/ banana is Musa'
	DBG: "read" read line:
		3 : cherry is Prunus avium  
	DBG: "read" - key and value are '3/ cherry is Prunus avium'
	DBG: in "load" have content '3/ cherry is Prunus avium'
	Table of 4 entries
		 1 -> ' apple is Malus'
		 2 -> ' banana is Musa'
		 3 -> ' cherry is Prunus avium'
	```

* What it **actually** prints is this:

	```
	DBG: in "read" read line:
		1 : apple is Malus
	DBG: in "read" - 'clean' value is 'apple is Malus'
	DBG: in "read" - key/value are '1/apple is Malus'
	DBG: in "load" have content '1/À^B'
	DBG: in "read" read line:
		2 : banana is Musa
	DBG: in "read" - 'clean' value is 'banana is Musa'
	DBG: in "read" - key/value are '2/banana is Musa'
	DBG: in "load" have content '2/À^B'
	DBG: in "read" read line:
		3 : cherry is Prunus avium
	DBG: in "read" - 'clean' value is 'cherry is Prunus avium'
	DBG: in "read" - key/value are '3/cherry is Prunus avium'
	DBG: in "load" have content '3/À^B'
	Table of 3 entries
		 1 -> 'À^B'
		 2 -> 'À^B'
		 3 -> 'À^B'
	<<<<
	```


* Note that the "Table of 4 entries" that is printed out at the end is corrupted, as is the data printed out in the debug (`DBG`) statements marked `"load"`.

* Note also that the debug (`DBG`) statements in "`read`" all show *sensible* data values.  The data was fine at "read" but corrupted by the time we got to "load".

* What do you think is happening here?  The task in this lab is to think about what is likely causing this kind of corruption and fix the problem.

* The "`read`" function is in `dataReader.c` and is called "`drReadDataLine()`".  The "`load`" function is in `mainline.c` and is called "`loadDataTable()`".  Think about the fact that the "load" function **calls** the "read" function.

* There is a script to run `valgrind(1)` to check for memory errors

# CLUES:

* **Think about** what can be causing this
* Data is being loaded, but not properly available to the **parent function**
* The `valgrind` program reports that there are "uninitialised value(s)" that are being examined -- what does that mean?  **This is a very significant clue**

## STRONG HINT

* on lines 85-92 of `dataReader.c` we have pointers that clearly point at the right value, but this value is not appearing in the `valuebuffer` variable in `loadDataTable()` at line 35 of `mainline.c`
* What ***SHOULD*** be happening in the call to `loadDataTable()` to allow the value to appear?  What ***IS*** happening?  Are these the same?

# Lab submission

1) First, verify that your code works properly
2) **Be sure to both** `commit` and `push` the results to gitlab for grading.
	* A `commit` checks in your changes locally
	* A `push` actually copies the changes into the gitlab repository where the TAs can see it
3) Answer the questions in the Courselink Quiz called "Lab 1: gitlab and memory debugging"


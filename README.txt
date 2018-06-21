
This is the README file of “List” abstract structure developed by
Galust Betkhemyan and Olya Yeritspokhyan.

CONTENTS
        1. AUTHOR
        2. INTRODUCTION
        3. PREREQUISITES
        4. BUILD
        5. DIRECTORY STRUCTURE
        6. USAGE
        7. DOCUMENTATION
        

1. AUTHOR
Galust Betkhemyan, Olya Yeritspokhyan.
E-mail: olya.yeritspokhyan@gmail.com
		galustbetkhemyan@gmail.com

Project Maintainer
	Galust Betkhemyan, Olya Yeritspokhyan.
	olya.yeritspokhyan@gmail.com
	galustbetkhemyan@gmail.com
	
2. INTRODUCTION
The project gives implementations of 
1. List
2. Stack
3. Queue
List or sequence is an abstract data type that represents a countable number of ordered values, where the same value may occur more than once. An instance of a list is a computer representation of the mathematical concept of a finite sequence.

Queue is a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the first element added to the queue will be the first one to be removed. This is equivalent to the requirement that once a new element is added, all elements that were added before have to be removed before the new element can be removed. get_front() and get_back() operations are also entered, returning the value of the front/back element without dequeuing it.

Stack is an abstract data type that serves as a collection of elements, with two principal operations:
1.push, which adds an element to the collection, and
 2.pop, which removes the most recently added element that was not yet removed.
The order in which elements come off a stack gives rise to its alternative name, LIFO (last in, first out). Additionally, a peek operation gives access to the top without modifying the stack.

3. PREREQUISITES
The following third party tools should be installed before the
compilation.

Tools:
g++
doxygen

4. BUILD
See the following commands in the project root directory.
Build the project
	make
	
Delete secondary files
	make clean
	
Run test
	make test

5. DIRECTORY STRUCTURE
- List – the top directory
	- src – should contain the source code of the project
	- makefile – the top makefile for building the project
	- docs -  for containing documentations
		/doxygen_config should contain file for doxygen configuration file

After building, the following directories should be created:
	- deps – should contain dependency files
	- obj – should contain oject files
	- bin – should contain executable file
	
	
6. USAGE
	As the name implies, lists can be used to store a list of elements. However, unlike in traditional arrays, lists can expand and shrink, and are stored dynamically in memory.

List In computing, lists are easier to implement than sets. A finite set in the mathematical sense can be realized as a list with additional restrictions; that is, duplicate elements are disallowed and order is irrelevant. Sorting the list speeds up determining if a given item is already in the set, but in order to ensure the order, it requires more time to add new entry to the list. In efficient implementations, however, sets are implemented using self-balancing binary search trees or hash tables, rather than a list.

Stack - Calculators employing reverse Polish notation use a stack structure to hold values. Expressions can be represented in prefix, postfix or infix notations and conversion from one form to another may be accomplished using a stack. Many compilers use a stack for parsing the syntax of expressions, program blocks etc. before translating into low level code. Most programming languages are context-free languages, allowing them to be parsed with stack based machines.

Queue - Applications of a Queue. In general, queues are often used as "waiting lines". Here are a few examples of where queues would be used: In operating systems, for controlling access to shared system resources such as printers, files, communication lines, disks and tapes.

7. DOCUMENTATION
"make docs" command generates doxygen documentation.

Doxygen also generates documentation from C/C++ code comments.

To see the generated documentation use ./docs/doxygen/html/index.html.

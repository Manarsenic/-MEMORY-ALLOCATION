# -MEMORY-ALLOCATION
A C program to track dynamic memory allocation, detect leaks, and display usage reports using named variables.
Memory management is a core aspect of systems-level programming in
C. Unlike modern languages with automatic garbage collection, C
requires developers to manually allocate and deallocate memory. This
can often lead to memory leaks, segmentation faults, or performance
issues if not handled correctly. The objective of this project is to develop
a command-line tool that actively tracks memory allocations and
deallocations, alerts the user to potential memory leaks, and offers a
clean summary of memory activity. It acts as both a diagnostic tool and a
learning aid for those working with dynamic memory in C.


1. Startup:
○ Displays a welcome message and presents a user-friendly menu.
2. Memory Allocation:
○ Accepts a variable name and size from the user.
○ Allocates memory using malloc() and stores all metadata
(pointer, size, name).
3. Memory Deallocation:
○ Takes input for the variable name to be freed.
○ Validates and frees the memory, ensuring it hasn’t already been
deallocated.
4. Summary Generation:
○ Calculates and displays the total memory allocated, total freed,
and remaining unfreed memory blocks.
5. Exit Handling:
○ On exiting the application, a final memory report is printed,
warning the user of any leaks.


This application does not rely on external data files. All necessary inputs are
provided directly by the user during execution. Also the code focuses on
using the concepts of structure as well as pointer and not relying on built-in
libraries .
● Variable name (string input)
● Memory size in bytes (integer input)
● Having different functions for each case like allocation freeing memory
or checking the memory occupied by current variable created as well as
creating memory blocks for each variable
These inputs are stored in memory during the session and used for all
track and report.

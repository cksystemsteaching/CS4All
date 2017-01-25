Workflow
--------

* Step 0: get a [github](https://github.com) account unless you already have one
* Step 1: join the `#sws2016` and `#cs4all-bot` [slack channels](https://cksystemsteaching.slack.com/signup) and use your github username as slack username
* Step 2: form a team of 2-3 members and give your team a name
* Step 3: one person per team forks the [CS4All](https://github.com/cksystemsteaching/CS4All/fork) repository
* Step 4: add the other team members to __your__ fork as collaborators
* Step 5: each team member clones that fork
* Step 6: check out the [selfie](https://github.com/cksystemsteaching/CS4All/tree/selfie) branch
* Step 7: add a new file called TEAM to this branch
* Step 8: list the name of your team as well as your names in the TEAM file
* Step 9: implement solutions of assignments in this branch as well (see below)
* Step 10: commit regularly and push your changes to your fork
* Step 11: to submit solutions send pull requests from your fork via github.com to the [selfie](https://github.com/cksystemsteaching/CS4All/tree/selfie) branch

General Requirements
--------------------

All homework solutions:

* must be implemented in C\* in the selfie.c file,
* must compile without warnings with starc and execute with mipster on [travis](https://travis-ci.org/cksystemsteaching/CS4All),
* must not break any existing selfie functionality, and
* must be ready for presentation on your machine in class.


[Introduction slides](https://myfiles.sbg.ac.at/index.php/s/gEGFSoIrMdee6rA)

---------------------

Assignment 0: Your Team!
------------------------

__Deadline__: October 10, 8pm (hard, no extensions)

Suppose your team name is *TheRunnables*. Change selfie such that it prints "This is TheRunnables Selfie" in a separate line on the console before doing anything else. All other functionality should be unaffected.

-----------
[Lecture 1](https://myfiles.sbg.ac.at/index.php/s/oTwDS4UoSijdEEc)
-----------



Assignment 1: Loading, scheduling, switching, execution
-------------------------------------------------------

Implement basic concurrent execution of _n_ processes in mipster. _n >= 2_ 

* understand how mipster [interprets and executes binary instructions]. Tipp: add your own comments to the code
* mipster maintains a local state for a process (running executable), e.g., pc, registers, memory
* understand the purpose of each variable and data structure
* duplicate the process state n times
* running mipster like: _./selfie -m 32 yourbinary_ should generate _n_ instances of _yourbinary_ in a single instance of mipster
* implement [preemptive multitasking](https://en.wikipedia.org/wiki/Preemption_(computing)), i.e., switching between the _n_ instances of _yourbinary_ is determined by mipster 
* switch processes every m instructions. _1 <= m <= number of instructions in yourbinary_
* implement [round-robin scheduling](https://en.wikipedia.org/wiki/Round-robin_scheduling)
* add some output in _yourbinary_ to demonstrate context switching
* __Deadline__: October 24, 8pm (hard, no extensions)

-----------
[Lecture 2](https://myfiles.sbg.ac.at/index.php/s/DOuC6keTPyEAHcw)
-----------

Assignment 2: Memory segmentation, yield system call
----------------------------------------------------

This assignment deals with cooperative multitasking of _n_ processes in mipster using a single instance of physical memory.

* again, duplicate the process state _n_ times
* but, do not duplicate the whole main memory
* instead, split the main memory into segments by implementing a segment table in mipster
* each process has an entry in the segment table for the segment start address and segment size
* design the segment table for constant time access
* translate the addresses of read and write operations to memory

* implement [cooperative multitasking](https://en.wikipedia.org/wiki/Computer_multitasking) through a yield system call, i.e., a user process calling [sched_yield()](http://linux.die.net/man/2/sched_yield) will cause the OS to re-schedule
* implement a simple user program that demonstrates yielding, e.g, yield each time after printing a counter to the console
* __Deadline__: Nov 7, 8pm

-----------

[Lecture 3](https://myfiles.sbg.ac.at/index.php/s/sDpx7HPjbGitXwA)
-----------

[Lecture 4](https://myfiles.sbg.ac.at/index.php/s/j7xW8qDRTxnd7pO)
-----------

[Cover slides for class no. 5](https://myfiles.sbg.ac.at/index.php/s/yGZIpDCe5iccUK7)
-----------

Assignment 3: Shared memory
-------------------------------------------------------

* Run multiple processes like in assignment 1, but this time alongside an OS process - the OS part of selfie. 

The command line (for two user processes) should look like
./selfie -l selfie.m -k 4 -l myprog.m -c 2 -u 1 

All interrupts, traps or exceptions must be handled by the OS process instead of the emulator. This is indicated by  using option -k. When an exception occurs from a user process (run with parameter -u) and the OS is not there to handle it, print an error message and exit. The OS should trigger only the EXIT exception. 

* Read about the POSIX shared memory API.

* Implement basic POSIX-like shared memory support in selfie, consisting of the following system calls:

    int shm_open(int name)   
// Creates or opens a new shared memory object and returns a descriptor (OS identifier) for it.   
// In case of error, it returns -1.   

	int shm_size(int id, int shSize)   
// Sets or returns the size (in bytes) of the shm object with identifier id.   
// If the object had size zero, it sets the size to shSize and returns shSize.   
// If the object had some previously set size actSize, then it ignores shSize and simply returns actSize.   

	int* shm_map(int* addr, int id)    
// Maps the virtual address addr to the start of the shared memory identified by id.   
// If addr is zero, then memory is allocated first, of the size equal to the shared memory size.    
// Returns virtual address actually used for mapping, 0 for error.   

	int shm_close(int id)     
// Decouples the calling process from the shared memory object with descriptor id.   
// Previously mapped memory is now private to the process.   
// After all processes have closed their access to a shared memory object, the OS should free the resources associated  with the object.   

* Demonstrate the usage of shared memory between at least 2 user processes.
* __Deadline__: Nov 28, 8pm (hard, no extensions)

-----------

[Lecture 6](https://myfiles.sbg.ac.at/index.php/s/tOfYlWfhcm8HSQc)
-----------

[Lecture 7](https://myfiles.sbg.ac.at/index.php/s/LnIhy0XBYG9S6iO)
-----------

Assignment 4: Threads and locks
-------------------------------------------------------
* Implement basic multi-threading support: create threads instead of processes
* Implement a user program that demonstrates the fact that threads share the same address space
* Implement a single global lock through syscalls, e.g., a lock() and unlock() call.
* Implement a user program that demonstrates mutual exclusion, e.g, show that one process inside the critical section makes progress, processes not taking the lock make progress, and processes waiting for the lock do not make progress. Hint: you can implement the [getpid](http://linux.die.net/man/2/getpid) system call to identify processes.
* Experiment with and demonstrate different interleavings: using locks, no locks, different time slices
* __Deadline__: Dec 12, 8pm (hard, no extensions)

-----------

[Lecture 8](https://myfiles.sbg.ac.at/index.php/s/2kxDQ4EdMfLDR8F)
-----------

Assignment 5: Synchronization 
-------------------------------------------------------

* Implement in selfie a mechanism that allows multi-readers-single-writer access, where:
 - Multiple tasks want to access a shared data element (e.g., an array) in reading or writing
 - Tasks that only read from the data element are allowed to do so simultaneously
 - If a task wants to write, it must first get exclusive access – no other task may access the data element in reading or writing
* Demonstrate this with a user program
* __Deadline__: Dec 19, 8pm (hard, no extensions)

-----------

Assignment 6: Free-space memory management 
-------------------------------------------------------

* Read and understand [Chapter 17 from the OSTEP book](http://pages.cs.wisc.edu/~remzi/OSTEP/vm-freespace.pdf). Feel free to follow any references therein, especially the survey \[W+95\]. Be prepared to answer questions from that chapter in class!
* Implement in selfie a basic strategy for free space memory management (Section 17.3 in the book). 
* Demonstrate the implemented policy with a user program.
* __Deadline__: Jan 16, 2017, 8pm (hard, no extensions)

-----------

[Lecture 9](https://myfiles.sbg.ac.at/index.php/s/NK1ibsUYJGzALkF)
-----------

Assignment 7: Deadlock 
-------------------------------------------------------

* Extend selfie to provide multiple locks as resources
* Demonstrate deadlock with the user program shown in class (see slides)
* Implement the Banker's algorithm in selfie for locks
* Show how deadlock is avoided in the example program
* __Deadline__: Jan 23, 8pm (hard, no extensions)

-----------

[Lecture 10](https://myfiles.sbg.ac.at/index.php/s/yuYVqQ96hA2khPe)
-----------

Assignment 8: Concurrent data structures 
-------------------------------------------------------

* Implement the [Michael-Scott queue](https://www.research.ibm.com/people/m/michael/podc-1996.pdf). For that, you need to implement a Compare and Swap instruction (CAS), as discussed in previous lectures (see also the [Wikipedia article] (https://en.wikipedia.org/wiki/Compare-and-swap)).
* Demonstrate your data structure with a meaningful test program, e.g., a Producer-Consumer instance, or the test program from Assignment 7.
* __Deadline__: Jan 30, 8pm (hard, no extensions)

-----------

[Lecture 11](https://myfiles.sbg.ac.at/index.php/s/vcmcyI7hSuQGu7k)
-----------

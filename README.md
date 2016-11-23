Workflow
--------

* Step 0: get a [github](https://github.com) account unless you already have one
* Step 1: join the `#se2016` and `#cs4all-bot` [slack channels](https://cksystemsteaching.slack.com/signup) and use your github username as slack username
* Step 2: form a team of 2-3 members and give your team a name
* Step 3: each team member visits the invitation page shared in slack to get access to the team repository.
* Step 4: each team member clones this repositoy
* Step 5: add a new file called TEAM to this branch
* Step 6: list the name of your team as well as your names in the TEAM file
* Step 7: implement solutions of assignments in this branch as well (see below)
* Step 8: commit regularly and push your changes the repository

General Requirements
--------------------

All homework solutions:

* must be implemented in C\* in the selfie.c file,
* must compile without warnings with starc and execute with mipster on [travis](https://travis-ci.org/cksystemsteaching/CS4All),
* must not break any existing selfie functionality, and
* must be ready for presentation on your machine in class.
* must include a short `.md` or `.txt` file that explains what was done, why it was done that way, and any problems encountered.

Assignment 0: Your Team!
------------------------

__Deadline__: October 12, 10am (hard, no extensions)

Suppose your team name is *TheRunnables*. Change selfie such that it prints "This is TheRunnables Selfie" in a separate line on the console before doing anything else. All other functionality should be unaffected.

Assignment 1: Revisiting Compilers
----------------------------------

__Deadline__: October 18, 9am (hard, no extensions)

Implement either the prefix or the postfix increment (`++`) in selfie.
(Bonus: Do both, and maybe throw in `--` for good measure.)
Extend `grammar.md` and modify the scanner and parser/codegenerator of starc accordingly.
Test your implementation on syntactically correct as well as syntactically incorrect C\* programs.

In C/C++ the expression `++i + ++i` is undefined. Why???
Can you find a program and compiler flags (for eg. `gcc` or `clang`), such that the compiled program behaves differently than the same program compiled with your implementation.

Assignment 2: Addresses
----------------------------------
__Deadline__: November 8, 9am (hard, no extensions)

Implement the address operator (`&`) and function pointers in selfie.
You do *not* need to implement function pointer types (i.e. in this aspect compatibility with regular `C` is not required), but doing so will get you bonus points.

What can you do with your new powers? Find interesting ways to show off the new functionality. Be wild! (But document the showcase code.)

Assignment 3: Time sharing
----------------------------------
__Deadline__: November 15, 9am

Implement cooperative *and* preemptive multitasking in mipster.
Put all relevant emulator state into an appropriate data structure such as a linked list.
Calling `./selfie -l binary.m -m 32 5` should run 5 copies of `binary.m` concurrently.
Implement two new syscalls:
* `void yield()`: relinquish the CPU and immediately reschedule
* `int id()`: return the id of the currrent process

Again, what can you do with your new powers? Write some examples that showcase
multitasking (be sure to add output). For most non-trivial examples you will
need some form of IPC - but you are in luck: it is already there for you. Find
it and use it!


Assignment 4: Dynamic relocation
----------------------------------
__Deadline__: November 22, 9am

Implement a basic form of virtual memory: pure base & bounds without segmentation or
swapping, but *with* memory protection.

Remove the process duplication from Assignment 3 and implement a `fork()` syscall instead.
Calling `./selfie -l binary.m -m 2 5` should start a single process of `binary.m` in a 2MB virtual address space
and allow for up to 5 processes (each with 2MB address spaces) to run concurrently on a single and contiguous physical memory.
Be sure reclaim memory from exited processes so that arbitrarily many processes can be created during a single run of the emulator.

As always, write examples that exercise all the new functionality and finally document the what, the why and any problems encountered.

Use the repositories from Assignment 3.


Assignment 5: Synchronization
----------------------------------
__Deadline__: November 30, 9am

Play through the [deadlock empire](https://deadlockempire.github.io).

Implement (spin)locks and condition variables in selfie.
(Notice the plural here, the number of locks and condition variables should only be constrained by the memory.
Use shared memory/threads for bonus points.)

Use these primitives to implement semaphores as a library completely outside of selfie.

As always, write examples that exercise all the new functionality and finally document the what, the why and any problems encountered.

Again, reuse the repositories from Assignment 3.

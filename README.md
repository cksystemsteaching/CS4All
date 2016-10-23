Workflow
--------

* Step 0: get a [github](https://github.com) account unless you already have one
* Step 1: join the `#se2016` and `#cs4all-bot` [slack channels](https://cksystemsteaching.slack.com/signup) and use your github username as slack username
* Step 2: form a team of 2-3 members and give your team a name
* Step 3: one person per team forks the [CS4All](https://github.com/cksystemsteaching/CS4All/fork) repository
* Step 4: add the other team members to __your__ fork as collaborators
* Step 5: each team member clones that fork
* Step 6: check out the [selfie-se](https://github.com/cksystemsteaching/CS4All/tree/selfie-se) branch
* Step 7: add a new file called TEAM to this branch
* Step 8: list the name of your team as well as your names in the TEAM file
* Step 9: implement solutions of assignments in this branch as well (see below)
* Step 10: commit regularly and push your changes to your fork
* Step 11: to submit solutions send pull requests from your fork via github.com to the [selfie-se](https://github.com/cksystemsteaching/CS4All/tree/selfie-se) branch

General Requirements
--------------------

All homework solutions:

* must be implemented in C\* in the selfie.c file,
* must compile without warnings with starc and execute with mipster on [travis](https://travis-ci.org/cksystemsteaching/CS4All),
* must not break any existing selfie functionality, and
* must be ready for presentation on your machine in class.

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
You do *not* need to implement function pointer types (i.e. in this aspect compatibility with regular `C` is not required).

What can you do with your new powers? Find interesting ways to show off the new functionality. Be wild! (But document the showcase code.)

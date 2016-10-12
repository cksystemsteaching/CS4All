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


[Introduction slides](https://myfiles.sbg.ac.at/index.php/s/2cLKfyv30T3RwUj)
---------------------

Assignment 0: Your Team!
------------------------

__Deadline__: October 10, 8pm (hard, no extensions)

Suppose your team name is *TheRunnables*. Change selfie such that it prints "This is TheRunnables Selfie" in a separate line on the console before doing anything else. All other functionality should be unaffected.


Lecture 1 (pdf)
---------------



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
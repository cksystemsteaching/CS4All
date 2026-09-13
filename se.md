## Systems Engineering

This is an introductory class on systems engineering for bachelor students in computer science. The goal of the class is to introduce basic principles of operating systems for students to understand processor and memory virtualization. Seeing and actually understanding virtualization is the overarching theme of the class, in three sentences: isolation is the semantic problem of systems; virtualization buys performance by introducing self-reference; what a kernel cannot decide, it bounds.

After taking the class, students are able to understand the difference between processes and threads as well as emulation and virtualization, what virtual memory is and how it works, what concurrency is, as opposed to parallelism, how processes and threads synchronize efficiently, and how a memory-safety property of systems code is stated and checked with a model checker.

## Syllabus

Week 1 is the talk [What is Selfie?](https://selfie.cs.uni-salzburg.at/talk/). The lectures follow one axis, from the small to the vast to the countable to the uncountable, in six stations: I Size, II Notation, III Meaning, IV Cost, V Machines, VI Intelligence. Each lecture is an HTML deck with a PDF rendering next to it, and ends with a piece of music and, in the introductory class, two things to read. The decks are at [selfie.cs.uni-salzburg.at/classes/se](https://selfie.cs.uni-salzburg.at/classes/se/).

| week | station | lecture | assignments |
|---|---|---|---|
| 1 | spine | [What is Selfie?](https://selfie.cs.uni-salzburg.at/classes/se/01-what-is-selfie/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/01-what-is-selfie/01-what-is-selfie.pdf)) | `print-your-name` |
| 2 | II | [The Machine, Again](https://selfie.cs.uni-salzburg.at/classes/se/02-the-machine-again/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/02-the-machine-again/02-the-machine-again.pdf)) | `assembler-parser` |
| 3 | III | [Emulation](https://selfie.cs.uni-salzburg.at/classes/se/03-emulation/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/03-emulation/03-emulation.pdf)) | `self-assembler` |
| 4 | III | [Virtual Memory](https://selfie.cs.uni-salzburg.at/classes/se/04-virtual-memory/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/04-virtual-memory/04-virtual-memory.pdf)) |  |
| 5 | III | [Time-Sharing](https://selfie.cs.uni-salzburg.at/classes/se/05-time-sharing/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/05-time-sharing/05-time-sharing.pdf)) | `processes` |
| 6 | III | [Self-Hosting](https://selfie.cs.uni-salzburg.at/classes/se/06-self-hosting/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/06-self-hosting/06-self-hosting.pdf)) | `fork-wait` |
| 7 | III | [Processes](https://selfie.cs.uni-salzburg.at/classes/se/07-processes/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/07-processes/07-processes.pdf)) | `fork-wait-exit` |
| 8 | III | [Concurrency](https://selfie.cs.uni-salzburg.at/classes/se/08-concurrency/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/08-concurrency/08-concurrency.pdf)) | `lock`, `threads` |
| 9 | III | [Runtime Systems](https://selfie.cs.uni-salzburg.at/classes/se/09-runtime-systems/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/09-runtime-systems/09-runtime-systems.pdf)) | `threadsafe-malloc` |
| 10 | IV | [Verifying Systems Code](https://selfie.cs.uni-salzburg.at/classes/se/10-verifying-systems-code/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/10-verifying-systems-code/10-verifying-systems-code.pdf)) | `treiber-stack`, `rotor-bounds` |
| 11 | IV | [Cost](https://selfie.cs.uni-salzburg.at/classes/se/11-cost/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/11-cost/11-cost.pdf)) |  |
| 12 | III | [Universality for Systems](https://selfie.cs.uni-salzburg.at/classes/se/12-universality/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/12-universality/12-universality.pdf)) |  |
| 13 | V | [Agents as Processes](https://selfie.cs.uni-salzburg.at/classes/se/13-agents-as-processes/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/13-agents-as-processes/13-agents-as-processes.pdf)) |  |
| 14 | VI | [What is a System?](https://selfie.cs.uni-salzburg.at/classes/se/14-what-is-a-system/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/se/14-what-is-a-system/14-what-is-a-system.pdf)) |  |

## Software

The class works by explaining the basic principles behind [selfie](https://github.com/cksystemsteaching/selfie), a software system written in a tiny subset of C called C\* that implements a self-compiling compiler targeting a tiny subset of RISC-V machine code called RISC-U, a self-executing RISC-U emulator, and a self-hosting RISC-U hypervisor. Selfie also comes with rotor and bitme, a model generator and a bounded model checker that turn a RISC-U binary into a formula and ask a SAT or SMT solver whether any input reaches a bad state within a bound.

## Assignments

Selfie features an [autograder](https://github.com/cksystemsteaching/selfie/tree/main/grader) for the [systems assignments](https://github.com/cksystemsteaching/selfie/blob/main/assignments/systems-assignments.md), one or two per week as listed above, ending with `rotor-bounds`: state a memory-safety property for a sequential routine of your own systems code, generate its model, and let bitme find the input that violates it, or the bound up to which none does.

## References

The textbook is [What is Intelligence? Discovering Unproven Truth](https://github.com/cksystemsteaching/selfie/blob/main/book/README.md); the Computing chapter is this class, and the Meaning and Cost chapters are its theory.

## Organization

The class is organized as part of a series of [Computer Science for All](index.md) classes.

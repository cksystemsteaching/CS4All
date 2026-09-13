## Introduction to Computer Science

This is an introductory class on computer science for broad audiences such as bachelor students in computer science, students majoring in other fields but interested in computer science, high-school students, and anybody with a background in basic math and the desire to understand the absolute basics of computer science.

The class follows the book [What is Intelligence? Discovering Unproven Truth](https://github.com/cksystemsteaching/selfie/blob/main/book/README.md) at talk resolution: proof against truth, along one axis from the small to the vast to the countable to the uncountable, with Cantor, Gödel, Turing and Rice met along the way and selfie run live in every session. The purpose is a deep understanding of basic computer science principles, deep enough to position generative AI, and whatever comes next, properly.

After taking the class, students are able to answer not just basic computer science questions but also questions about themselves such as which courses to take next and which books to follow up with, ideally realizing if they are interested in computer science more than expected, or even less than before.

## Syllabus

Week 1 is the talk [What is Intelligence?](https://selfie.cs.uni-salzburg.at/intelligence/). The lectures follow one axis, from the small to the vast to the countable to the uncountable, in six stations: I Size, II Notation, III Meaning, IV Cost, V Machines, VI Intelligence. Each lecture is an HTML deck with a PDF rendering next to it, and ends with a piece of music and, in the introductory class, two things to read. The decks are at [selfie.cs.uni-salzburg.at/classes/ics](https://selfie.cs.uni-salzburg.at/classes/ics/).

| week | station | lecture |
|---|---|---|
| 1 | — | [What is Intelligence? The talk, then the class](https://selfie.cs.uni-salzburg.at/classes/ics/01-what-is-intelligence/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/01-what-is-intelligence/01-what-is-intelligence.pdf)) |
| 2 | I | [Size](https://selfie.cs.uni-salzburg.at/classes/ics/02-size/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/02-size/02-size.pdf)) |
| 3 | I | [Everything is Bits](https://selfie.cs.uni-salzburg.at/classes/ics/03-everything-is-bits/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/03-everything-is-bits/03-everything-is-bits.pdf)) |
| 4 | II | [Notation](https://selfie.cs.uni-salzburg.at/classes/ics/04-notation/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/04-notation/04-notation.pdf)) |
| 5 | II | [Countability](https://selfie.cs.uni-salzburg.at/classes/ics/05-countability/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/05-countability/05-countability.pdf)) |
| 6 | II | [The Machine](https://selfie.cs.uni-salzburg.at/classes/ics/06-the-machine/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/06-the-machine/06-the-machine.pdf)) |
| 7 | III | [Uncountability](https://selfie.cs.uni-salzburg.at/classes/ics/07-uncountability/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/07-uncountability/07-uncountability.pdf)) |
| 8 | III | [Self-Reference I](https://selfie.cs.uni-salzburg.at/classes/ics/08-self-reference-i/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/08-self-reference-i/08-self-reference-i.pdf)) |
| 9 | III | [Self-Reference II](https://selfie.cs.uni-salzburg.at/classes/ics/09-self-reference-ii/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/09-self-reference-ii/09-self-reference-ii.pdf)) |
| 10 | III | [Systems](https://selfie.cs.uni-salzburg.at/classes/ics/10-systems/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/10-systems/10-systems.pdf)) |
| 11 | IV | [Cost](https://selfie.cs.uni-salzburg.at/classes/ics/11-cost/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/11-cost/11-cost.pdf)) |
| 12 | IV | [Formal Methods](https://selfie.cs.uni-salzburg.at/classes/ics/12-formal-methods/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/12-formal-methods/12-formal-methods.pdf)) |
| 13 | V | [Machines](https://selfie.cs.uni-salzburg.at/classes/ics/13-machines/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/13-machines/13-machines.pdf)) |
| 14 | VI | [So, What is Intelligence?](https://selfie.cs.uni-salzburg.at/classes/ics/14-what-is-intelligence/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/ics/14-what-is-intelligence/14-what-is-intelligence.pdf)) |

## Software

The class works by explaining the basic principles behind [selfie](https://github.com/cksystemsteaching/selfie), a software system written in a tiny subset of C called C\* that implements a self-compiling compiler targeting a tiny subset of RISC-V machine code called RISC-U, a self-executing RISC-U emulator, and a self-hosting RISC-U hypervisor. Selfie also comes with rotor and bitme, a model generator and a bounded model checker that turn a RISC-U binary into a formula and ask a SAT or SMT solver whether any input reaches a bad state within a bound.

## Exercises and Assessment

The class has no graded assignments. Each lecture ends with a list of recommended exercises, mirrored in [introductory-assignments.md](https://github.com/cksystemsteaching/selfie/blob/main/assignments/introductory-assignments.md), and the exam draws on these exercises and on nothing else: place a number on the axis, build a diagonal, say what a self-check proves, sort text from behaviour, name the outside check. Students who want more can do the first assignments of the compiler and systems classes with selfie's [autograder](https://github.com/cksystemsteaching/selfie/tree/main/grader).

## References

The textbook is [What is Intelligence? Discovering Unproven Truth](https://github.com/cksystemsteaching/selfie/blob/main/book/README.md), whose chapters are the weeks of the class; it includes recommended readings for every part. The previous edition, [Elementary Computer Science: From Bits and Bytes to the Universality of Computing](https://github.com/ckirsch/book), remains available.

## Organization

The class is organized as part of a series of [Computer Science for All](index.md) classes.

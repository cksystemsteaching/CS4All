## Compiler Construction

This is an introductory class on compiler construction for bachelor students in computer science. The goal of the class is to introduce basic principles of compilers for students to understand the design and implementation of programming languages. Seeing and actually understanding self-compilation is the overarching theme of the class, and the sentence the class earns is this: a compiler is a proof system for syntax and a constructor of semantics, and every semantic question it seems to answer is a chosen approximation.

After taking the class, students are able to understand the difference between syntax and semantics of a programming language, how syntax is specified and efficiently checked, how semantics is efficiently implemented through code generation, how a compiler that compiles itself is bootstrapped, and how a program becomes a formula that a solver can check within a bound.

## Syllabus

Week 1 is the talk [What is Selfie?](https://selfie.cs.uni-salzburg.at/talk/). The lectures follow one axis, from the small to the vast to the countable to the uncountable, in six stations: I Size, II Notation, III Meaning, IV Cost, V Machines, VI Intelligence. Each lecture is an HTML deck with a PDF rendering next to it, and ends with a piece of music and, in the introductory class, two things to read. The decks are at [selfie.cs.uni-salzburg.at/classes/cc](https://selfie.cs.uni-salzburg.at/classes/cc/).

| week | station | lecture | assignments |
|---|---|---|---|
| 1 | spine | [What is Selfie?](https://selfie.cs.uni-salzburg.at/classes/cc/01-what-is-selfie/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/01-what-is-selfie/01-what-is-selfie.pdf)) | `print-your-name` |
| 2 | I, II | [The Scanner](https://selfie.cs.uni-salzburg.at/classes/cc/02-the-scanner/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/02-the-scanner/02-the-scanner.pdf)) | `hex-literal` |
| 3 | II | [The Parser](https://selfie.cs.uni-salzburg.at/classes/cc/03-the-parser/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/03-the-parser/03-the-parser.pdf)) |  |
| 4 | III | [Symbols and Types](https://selfie.cs.uni-salzburg.at/classes/cc/04-symbols-and-types/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/04-symbols-and-types/04-symbols-and-types.pdf)) | `bitwise-shift-compilation` |
| 5 | II | [Expressions](https://selfie.cs.uni-salzburg.at/classes/cc/05-expressions/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/05-expressions/05-expressions.pdf)) | `bitwise-shift-execution` |
| 6 | III | [Statements](https://selfie.cs.uni-salzburg.at/classes/cc/06-statements/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/06-statements/06-statements.pdf)) | `bitwise-and-or-not`, `logical-and-or-not` |
| 7 | III | [Procedures](https://selfie.cs.uni-salzburg.at/classes/cc/07-procedures/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/07-procedures/07-procedures.pdf)) | `for-loop`, `lazy-evaluation` |
| 8 | III | [Self-Compilation](https://selfie.cs.uni-salzburg.at/classes/cc/08-self-compilation/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/08-self-compilation/08-self-compilation.pdf)) | `array-access` |
| 9 | III | [Optimisation and Rice](https://selfie.cs.uni-salzburg.at/classes/cc/09-optimisation/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/09-optimisation/09-optimisation.pdf)) | `array-allocation` |
| 10 | IV | [Semantics as a Formula](https://selfie.cs.uni-salzburg.at/classes/cc/10-semantics-as-a-formula/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/10-semantics-as-a-formula/10-semantics-as-a-formula.pdf)) | `array-multidimensional` |
| 11 | IV | [SAT](https://selfie.cs.uni-salzburg.at/classes/cc/11-sat/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/11-sat/11-sat.pdf)) | `struct-declaration` |
| 12 | IV | [Bounded Model Checking](https://selfie.cs.uni-salzburg.at/classes/cc/12-bounded-model-checking/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/12-bounded-model-checking/12-bounded-model-checking.pdf)) | `struct-execution`, `rotor-check` |
| 13 | V | [Generated Code](https://selfie.cs.uni-salzburg.at/classes/cc/13-generated-code/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/13-generated-code/13-generated-code.pdf)) |  |
| 14 | VI | [What is a Compiler?](https://selfie.cs.uni-salzburg.at/classes/cc/14-what-is-a-compiler/) ([pdf](https://selfie.cs.uni-salzburg.at/classes/cc/14-what-is-a-compiler/14-what-is-a-compiler.pdf)) |  |

## Software

The class works by explaining the basic principles behind [selfie](https://github.com/cksystemsteaching/selfie), a software system written in a tiny subset of C called C\* that implements a self-compiling compiler targeting a tiny subset of RISC-V machine code called RISC-U, a self-executing RISC-U emulator, and a self-hosting RISC-U hypervisor. Selfie also comes with rotor and bitme, a model generator and a bounded model checker that turn a RISC-U binary into a formula and ask a SAT or SMT solver whether any input reaches a bad state within a bound.

## Assignments

Selfie features an [autograder](https://github.com/cksystemsteaching/selfie/tree/main/grader) for the [compiler assignments](https://github.com/cksystemsteaching/selfie/blob/main/assignments/compiler-assignments.md), one or two per week as listed above, ending with `rotor-check`: generate the model of a program that exercises your own language extension and let bitme find the input that reaches a bad state, or the bound up to which none does.

## References

The textbook is [What is Intelligence? Discovering Unproven Truth](https://github.com/cksystemsteaching/selfie/blob/main/book/README.md); the Programming and Cost chapters are this class, and the Meaning chapter is its theory.

## Organization

The class is organized as part of a series of [Computer Science for All](index.md) classes.

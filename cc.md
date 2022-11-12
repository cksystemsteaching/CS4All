## Compiler Construction

This is an introductory class on compiler construction for bachelor students in computer science. The goal of the class is to introduce basic principles of compilers for students to understand the design and implementation of programming languages. Seeing and actually understanding self-compilation is the overarching theme of the class.

After taking the class, students are able to understand the difference between syntax and semantics of a programming language, how syntax is specified and efficiently checked, how semantics is efficiently implemented through code generation, and finally how a compiler that compiles itself is bootstrapped.

## Syllabus

1. [Selfie](https://github.com/cksystemsteaching/selfie)
2. Language
    1. Programming Language
    2. Machine Code
    3. Formal Grammar
3. Machine
    1. Model
    2. Processor
    3. Memory
    4. Input/Output
    5. Instructions
    6. Emulation
4. Compiler
    1. Scanning
    2. Parsing
    3. Code Generation
    4. Operators
    5. Arrays
    6. Structs
    7. Loops
    8. Conditionals
    9. Procedures
    10. Linking
    11. Bootstrapping

## Software

The class essentially works by explaining the basic principles behind [selfie](https://github.com/cksystemsteaching/selfie) which is a software system written in a tiny subset of C called C\* that implements a self-compiling compiler targeting a tiny subset of RISC-V machine code called RISC-U, a self-executing RISC-U emulator, and a self-hosting RISC-U hypervisor.

## Assignments

Selfie features an [autograder](https://github.com/cksystemsteaching/selfie/tree/main/grader) for a variety of technical [assignments](https://github.com/cksystemsteaching/selfie/tree/main/assignments).
Relevant here are the [compiler assignments](https://github.com/cksystemsteaching/selfie/blob/main/assignments/compiler-assignments.md).

## References

There is a draft of a textbook on [Elementary Computer Science](https://github.com/ckirsch/book) that is currently being developed for the class. The draft includes references to the literature relevant here.
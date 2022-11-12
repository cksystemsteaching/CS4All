## Systems Engineering

This is an introductory class on systems engineering for bachelor students in computer science. The goal of the class is to introduce basic principles of operating systems for students to understand processor and memory virtualization. Seeing and actually understanding virtualization is the overarching theme of the class.

After taking the class, students are able to understand the difference between processes and threads as well as emulation and virtualization, what virtual memory is and how it works, what concurrency is, as opposed to parallelism, and how processes and threads synchronize efficiently to overcome concurrency for communication.

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
4. Virtualization
    1. Processes
    2. Virtual Memory
    3. Scheduling
    4. Synchronization
    5. Threads
    6. Concurrency

## Software

The class essentially works by explaining the basic principles behind [selfie](https://github.com/cksystemsteaching/selfie) which is a software system written in a tiny subset of C called C\* that implements a self-compiling compiler targeting a tiny subset of RISC-V machine code called RISC-U, a self-executing RISC-U emulator, and a self-hosting RISC-U hypervisor.

## Assignments

Selfie features an [autograder](https://github.com/cksystemsteaching/selfie/tree/main/grader) for a variety of technical [assignments](https://github.com/cksystemsteaching/selfie/tree/main/assignments).
Relevant here are the [systems assignments](https://github.com/cksystemsteaching/selfie/blob/main/assignments/systems-assignments.md).

## References

There is a draft of a textbook on [Elementary Computer Science](https://github.com/ckirsch/book) that is currently being developed for the class. The draft includes references to the literature relevant here.
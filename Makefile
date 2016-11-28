# Compiler flags
CFLAGS := -w -m32 -D'main(a,b)=main(a,char**argv)'

# Compile selfie.c into selfie executable
selfie: selfie.c
	$(CC) $(CFLAGS) $< -o $@

# Consider these targets as targets, not files
.PHONY : test clean

# Test self-compilation, self-execution, and self-hosting
test: selfie
	./selfie -c selfie.c -o selfie1.m -s selfie1.s -m 2 -c selfie.c -o selfie2.m -s selfie2.s
	diff -q selfie1.m selfie2.m
	diff -q selfie1.s selfie2.s
	./selfie -c selfie.c -o selfie.m -m 1 -l selfie.m -m 1
	./selfie -c selfie.c -o selfie3.m -s selfie3.s -y 2 -l selfie3.m -y 2 -l selfie3.m -y 2 -c selfie.c -o selfie4.m -s selfie4.s
	diff -q selfie3.m selfie4.m
	diff -q selfie3.s selfie4.s
	diff -q selfie1.m selfie3.m
	diff -q selfie1.s selfie3.s
	./selfie -c selfie.c -o selfie5.m -s selfie5.s -min 3 -l selfie5.m -y 2 -l selfie5.m -y 2 -c selfie.c -o selfie6.m -s selfie6.s
	diff -q selfie5.m selfie6.m
	diff -q selfie5.s selfie6.s
	diff -q selfie3.m selfie5.m
	diff -q selfie3.s selfie5.s
	./selfie -c -mob 1


##########################
###### E I F L E S #######
##########################

clean:
	rm -rf *.m
	rm -rf *.s
	rm -rf selfie

clean-win:
	del *.m
	del *.s
	del selfie.exe

# Assignment 1: Loading, scheduling, switching, execution  #
A1:
	make clean
	make
	./selfie -c test_program.c selfie.c -o test_program.m 
	./selfie -timeslice 7777 -numprocesses 5 -l test_program.m -m 32

# Assignment 2: Memory segmentation, yield system call #
A2:
	make clean
	make
	./selfie -c test_program.c selfie.c -o test_program.m 
	./selfie -l test_program.m -m 32

# Assignment 3: Shared memory #
A3-no-exit:
	make clean
	make
	./selfie -c selfie.c -o selfie.m # create selfie mipster binary
	./selfie -c test_program.c selfie.c -o test_program.m # create test program
	./selfie -l selfie.m -numprocesses 1 -u 1 -l test_program.m -k 4 # command from assignment 3 (modified to run properly)

A3-no-exit-win:
	make clean-win
	make
	selfie.exe -c selfie.c -o selfie.m # create selfie mipster binary
	selfie.exe -c test_program.c selfie.c -o test_program.m # create test program
	selfie.exe -l selfie.m -numprocesses 1 -u 1 -l test_program.m -k 4 # command from assignment 3 (modified to run properly)

A3-exit:
	make clean
	make
	./selfie -c selfie.c -o selfie.m # create selfie mipster binary
	./selfie -c test_program.c selfie.c -o test_program.m # create test program
	#./selfie -l test_program.m -numprocesses 1 -u 1 -m 4 # do not compile with selfie's compiler -> will trigger exit because the hypster will not exist to handle it
	./selfie -l test_program.m -numprocesses 1 -u 1 -k 4

A3-exit-win:
	make clean-win
	make
	selfie.exe -c selfie.c -o selfie.m # create selfie mipster binary
	selfie.exe -c test_program.c selfie.c -o test_program.m # create test program
	selfie.exe -l test_program.m -numprocesses 1 -u 1 -m 4

A3-posix:
	make clean
	make
	./selfie -c demo_A3-posix.c selfie.c -o demo_A3-posix.m 
	./selfie -timeslice 77777 -numprocesses 5 -l demo_A3-posix.m -m 32

A3-posix-win:
	make clean-win
	make
	selfie.exe -c demo_A3-posix.c selfie.c -o demo_A3-posix.m 
	selfie.exe -timeslice 77777 -numprocesses 5 -l demo_A3-posix.m -m 32
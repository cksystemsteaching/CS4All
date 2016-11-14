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

# Clean up
clean:
	rm -rf *.m
	rm -rf *.s
	rm -rf selfie

winClean:
	del *.m
	del *.s
	del selfie

# Assignment 1 runnable on Linux
assignment1:
	make clean
	make
	./selfie -c test_program.c selfie.c -o test_program.m 
	./selfie -timeslice 7777 -numprocesses 5 -l test_program.m -m 32

# Assignment 1 runnable on Windows
winAssignment1:
	make winClean
	make
	selfie.exe -c test_program.c selfie.c -o test_program.m 
	selfie.exe -timeslice 7777 -numprocesses 5 -l test_program.m -m 32

# Assignment 2 runnable on Linux
assignment2:
	make clean
	make
	./selfie -c test_program.c selfie.c -o test_program.m 
	./selfie -l test_program.m -m 32
	

# Assignment 2 runnable on Windows
winAssignment2:
	make winClean
	make
	selfie.exe -c test_program.c selfie.c -o test_program.m 
	selfie.exe -l test_program.m -m 32
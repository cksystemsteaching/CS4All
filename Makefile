# Compiler flags
CFLAGS := -w -m32 -D'main(a,b)=main(a,char**argv)'

# Compile selfie.c into selfie executable
selfie: selfie.c
	$(CC) $(CFLAGS) $< -o $@

# Consider these targets as targets, not files
.PHONY : test assignment1 clean

# Test self-compilation, self-execution, and self-hosting
test: selfie
	./selfie -c selfie.c -o selfie1.m -s selfie1.s -m 8 -c selfie.c -o selfie2.m -s selfie2.s
	diff -q selfie1.m selfie2.m
	diff -q selfie1.s selfie2.s
	./selfie -c selfie.c -o selfie.m -m 4 -l selfie.m -m 4
	./selfie -c selfie.c -o selfie3.m -s selfie3.s -y 8 -l selfie3.m -y 8 -l selfie3.m -y 8 -c selfie.c -o selfie4.m -s selfie4.s
	diff -q selfie3.m selfie4.m
	diff -q selfie3.s selfie4.s
	diff -q selfie1.m selfie3.m
	diff -q selfie1.s selfie3.s
	./selfie -c selfie.c -o selfie5.m -s selfie5.s -min 12 -l selfie5.m -y 8 -l selfie5.m -y 8 -c selfie.c -o selfie6.m -s selfie6.s
	diff -q selfie5.m selfie6.m
	diff -q selfie5.s selfie6.s
	diff -q selfie3.m selfie5.m
	diff -q selfie3.s selfie5.s
	./selfie -c -mob 4


assignment1:
	./selfie -c testfiles/printexample.c selfie.c -conc 3 -freq 1 -m 4

assignment2:
	./selfie -c testfiles/yieldexample.c selfie.c -conc 3 -freq 1000000000 -m 4

	


# Clean up
clean:
	rm -rf *.m
	rm -rf *.s
	rm -rf selfie

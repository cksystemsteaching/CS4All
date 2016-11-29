	# Compiler flags
CFLAGS := -w -m32 -D'main(a,b)=main(a,char**argv)'

CC := gcc

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
	./selfie -c selfie.c -o selfie.m -m 2 -l selfie.m -m 2
	./selfie -c selfie.c -o selfie3.m -s selfie3.s -y 10 -l selfie3.m -y 10 -l selfie3.m -y 10 -c selfie.c -o selfie4.m -s selfie4.s
	diff -q selfie3.m selfie4.m
	diff -q selfie3.s selfie4.s
	diff -q selfie1.m selfie3.m
	diff -q selfie1.s selfie3.s
	./selfie -c selfie.c -o selfie5.m -s selfie5.s -min 30 -l selfie5.m -y 15 -l selfie5.m -y 6 -c selfie.c -o selfie6.m -s selfie6.s
	diff -q selfie5.m selfie6.m
	diff -q selfie5.s selfie6.s
	diff -q selfie3.m selfie5.m
	diff -q selfie3.s selfie5.s
	./selfie -c -mob 1

testA: selfie
	./selfie -c selfie.c -o selfie1.m -s selfie1.s -m 2 -c selfie.c -o selfie2.m -s selfie2.s
	diff -q selfie1.m selfie2.m
	diff -q selfie1.s selfie2.s

testB: selfie
	./selfie -c selfie.c -o selfie.m -m 2 -l selfie.m -m 2
	./selfie -c selfie.c -o selfie3.m -s selfie3.s -y 30 -l selfie3.m -y 15 -l selfie3.m -y 6 -c selfie.c -o selfie4.m -s selfie4.s
	diff -q selfie3.m selfie4.m
	diff -q selfie3.s selfie4.s
	diff -q selfie1.m selfie3.m
	diff -q selfie1.s selfie3.s

testC: selfie
	./selfie -c selfie.c -o selfie5.m -s selfie5.s -min 3 -l selfie5.m -y 2 -l selfie5.m -y 2 -c selfie.c -o selfie6.m -s selfie6.s
	diff -q selfie5.m selfie6.m
	diff -q selfie5.s selfie6.s
	diff -q selfie3.m selfie5.m
	diff -q selfie3.s selfie5.s

assign3: selfie
	./selfie -c selfie.c -o selfie.m -m 2
	./selfie -l selfie.m -c assign3test.c -o assign3test.m -m 2
	./selfie -l selfie.m -k 4 -l assign3test.m -t 10 -n 3 -u 1
	./selfie -l selfie.m -k 4 -l selfie.m -y -l assign3test.m -t 10 -n 3 -u 1
	./selfie -l assign3test.m -t 10 -n 3 -u 1
	
assign2: selfie
	./selfie -c assign2test.c -o assign2test.m -n 4 -m 32 -l assign2test.m -m 4


shmoTest: selfie
	./selfie -c shmo.c -o shmo.m -n 4 -m 32 -l shmo.m -m 4

#waaas
cleanWin: 
	del *.m & del *.s & del selfie.exe
	
# Clean up
clean:
	rm -rf *.m
	rm -rf *.s
	rm -rf selfie

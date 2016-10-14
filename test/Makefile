# Compiler flags
CFLAGS := -w -m32 -D'main(a,b)=main(a,char**argv)'

test_pre_increment:
	../selfie -c pre_increment/preinc1.c
	../selfie -c pre_increment/preinc1.c -d 1 | grep -E 'exit code 4'
	../selfie -c pre_increment/preinc2.c
	../selfie -c pre_increment/preinc2.c -d 1 | grep -E 'exit code 10'
	../selfie -c pre_increment/preinc3.c
	../selfie -c pre_increment/preinc3.c -d 1 | grep -E 'exit code 6'

clean:
	rm -rf *.s
	rm -rf *.m

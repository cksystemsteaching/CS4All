# Compiler flags
CFLAGS := -w -m32 -D'main(a,b)=main(a,char**argv)'

test_pre_increment: pre_increment/*.c
	../selfie -c $<
	../selfie -c $< -d 1 | grep -E 'exit code 4'
	../selfie -c $<
	../selfie -c $< -d 1 | grep -E 'exit code 10'

clean:
	rm -rf *.s
	rm -rf *.m

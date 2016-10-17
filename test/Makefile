# Compiler flags
CFLAGS := -w -m32 -D'main(a,b)=main(a,char**argv)'

test_pre_increment:
	../selfie -c pre_increment/preinc1.c
	../selfie -c pre_increment/preinc1.c -d 1 | grep -E 'exit code 4'
	../selfie -c pre_increment/preinc2.c
	../selfie -c pre_increment/preinc2.c -d 1 | grep -E 'exit code 10'
	../selfie -c pre_increment/preinc3.c
	../selfie -c pre_increment/preinc3.c -d 1 | grep -E 'exit code 6'
	../selfie -c pre_increment/postinc1.c
	../selfie -c pre_increment/postinc1.c -d 1 | grep -E 'exit code 7'
	../selfie -c pre_increment/postinc2.c
	../selfie -c pre_increment/postinc2.c -d 1 | grep -E 'exit code 9'
	../selfie -c pre_increment/postinc3.c
	../selfie -c pre_increment/postinc3.c -d 1 | grep -E 'exit code 5'
	../selfie -c pre_increment/postinc4.c
	../selfie -c pre_increment/postinc4.c -d 1 | grep -E 'exit code 18'
	../selfie -c pre_increment/predec1.c
	../selfie -c pre_increment/predec1.c -d 1 | grep -E 'exit code 2'
	../selfie -c pre_increment/postdec1.c
	../selfie -c pre_increment/postdec1.c -d 1 | grep -E 'exit code 3'
	../selfie -c pre_increment/preinc_statement_1.c
	../selfie -c pre_increment/preinc_statement_1.c -d 1 | grep -E 'exit code 5556'
	../selfie -c pre_increment/predec_statement_1.c
	../selfie -c pre_increment/predec_statement_1.c -d 1 | grep -E 'exit code 5554'
	../selfie -c pre_increment/postinc_statement_1.c
	../selfie -c pre_increment/postinc_statement_1.c -d 1 | grep -E 'exit code 5556'
	../selfie -c pre_increment/postdec_statement_1.c
	../selfie -c pre_increment/postdec_statement_1.c -d 1 | grep -E 'exit code 5554'
	../selfie -c pre_increment/preinc_deref_assignment_1.c
	../selfie -c pre_increment/preinc_deref_assignment_1.c -d 1 | grep -E 'exit code 7655'
	../selfie -c pre_increment/postinc_deref_assignment_1.c
	../selfie -c pre_increment/postinc_deref_assignment_1.c -d 1 | grep -E 'exit code 21'
	../selfie -c pre_increment/postdec_deref_assignment_1.c
	../selfie -c pre_increment/postdec_deref_assignment_1.c -d 1 | grep -E 'exit code 19'
	../selfie -c pre_increment/preinc_deref_statement_1.c
	../selfie -c pre_increment/preinc_deref_statement_1.c -d 1 | grep -E 'exit code 7655'
	../selfie -c pre_increment/postinc_deref_statement_1.c
	../selfie -c pre_increment/postinc_deref_statement_1.c -d 1 | grep -E 'exit code 2346'
	../selfie -c pre_increment/preinc_pointer_1.c
	../selfie -c pre_increment/preinc_pointer_1.c -d 1 | grep -E 'exit code 2345'
	../selfie -c pre_increment/postinc_pointer_1.c
	../selfie -c pre_increment/postinc_pointer_1.c -d 1 | grep -E 'exit code 2345'

clean:
	rm -rf *.s
	rm -rf *.m

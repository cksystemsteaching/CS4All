# selfie "grader"

## setup

```bash
$ git clone -b selfie-master https://github.com/cybernd/CC-Summer-2016.git CC-Summer-2016-cybernd
$ cd CC-Summer-2016-cybernd/verify
$ chmod u+x verify.sh
```

## run tests

Parameter: path to your selfie repository

```bash
CC-Summer-2016-cybernd/verify$ ./verify.sh ../../CC-Summer-2016
```

## add your own tests

All `verify/folder/*.c` files are automatically detected.

* enabled: [ true | false ]
  * true: test is enabled
  * false: test is diabled 
* expected: 42
  * the main return value is compared to expected integer
* assemblyOk: 42
  * the .s assembly file needs to contain 42
* assemblyNg: 66
  * the .s assembly should not contain 66
* msg: the statement in front of "// msg" will be treated as test message. (Multiple msg will be appended)

## configuration

Add file `verify.config` to your repository.
* folder/file.c [ enabled | disabled | exit ]
  * enabled: Force test file to be enabled.
  * disabled: Force test file to be disabled.
  * exit: Exit verify.sh at start of test file.
* folder: [ enabled | disabled | exit ]
  * enabled: Force test folder to be enabled.
  * disabled: Force test folder to be disabled.
  * skip: Skip test folder.
  * exit: Exit verify.sh at start of test folder.
* ALL: [ enabled | disabled | skip ]
  * enabled: All tests are enabled.
  * disabled: All tests are disabled.
  * skip: All tests are disabled + gray message is skipped.
* GCC_CHECK: [ disabled | enabled ]
  * enabled: Verify if test would compile with gcc. Adds a red [!gcc[x]] in front of msg in case of fatal error.
  * only: like enabled, but disables testing with selfie (allows compact check of multiple new test cases)
    "!": did not compile
    "[x]": x = actual return value (did not match expected)   
  * disabled: [default] skip verification to speed up script runtime
* DEBUG_CMD: [ disabled | enabled ]
  * enabled: print commands for debug reason
  * disabled: -

### configuration example

Run one specific test with gcc verification enabled:

```
ALL: skip
GCC_CHECK: enabled
a5-array/1writeLocal.c: enabled
```

Run one tests for one assignment (folder):
```
ALL: skip
a4-folding: enabled
```

Disable unsupported tests (constant-folding for exp is optional):
```
a4-folding/14expEquality.c
a4-folding/14expGt.c
a4-folding/14expLt.c
a4-folding/14expGeq.c
a4-folding/14expLeq.c
a4-folding/14expNotEqual.c
```

## todo

* improve 4declareLocalAddress.c because > 0x40 can not detect heap usage (because stack is > heap).
* student had idea to verify a6 using *(*(l+1)+2) = 42; Add an optional test including a proper memory layout explanation.
* Rename "verify" to "grader" or "autograder" as soon as this script is qualified to become an autograder.

#!/bin/bash

for i in test-a1/test_*.c; do
    echo $i:
    ./selfie -c $i testlib.c -m 1 | grep -iE 'OK|error in test'
done

for i in test-a2/test_*.c; do
    echo $i:
    ./selfie -c $i testlib.c -m 1 | grep -iE 'OK|error in test'
done

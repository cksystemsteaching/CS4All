#!/bin/bash

for i in test_*.c; do
    echo $i:
    ../selfie -c $i testlib.c -m 1 | grep OK
done

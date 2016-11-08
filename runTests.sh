#!/bin/bash

for i in test-a2/test_*.c; do
    echo $i:
    ./selfie -c $i testlib.c -m 1 | grep -iE 'WRONG|OK|error in test-a2|warning in test-a2|exit code -1|palloc out of physical memory'  | GREP_COLOR='1;32' grep -P 'OK|$' --color=always | GREP_COLOR='33' grep -P 'warning|$' --color=always | GREP_COLOR='1;31' grep -P 'WRONG|$' --color=always | GREP_COLOR='31' grep -P 'palloc out of physical memory|error|exit code -1|$' --color=always
done


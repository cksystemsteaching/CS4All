#!/bin/bash

# prototype
# just use "ERR_" in selfie.c
# this script will replace all ERR_ codes with unique errors

filename=../selfie.c

index=1

for linenr in `grep -n \"ERR_ ${filename} | awk -F":" '{print$1}'`
do
        sed -e "${linenr} s/ERR_[[:digit:]]*/ERR_$index/" -i ${filename}

        index=$((${index} + 1))
done

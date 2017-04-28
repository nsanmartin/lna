#!/bin/bash

len1=$1
len2=$2

par=$RANDOM

n=$(( $RANDOM * $RANDOM * $RANDOM ))

for i in $(seq 1 $len1)
do
    n=${n}" "$(( $RANDOM * $RANDOM * $RANDOM ))
done

echo $n . $(( $RANDOM * $RANDOM * $RANDOM ))

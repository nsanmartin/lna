#!/bin/bash

len1=$1
len2=$2

par=$RANDOM

signo=$(( $RANDOM % 2 == 0 ? 1 : -1 ))

[[ $signo -eq 1 ]] && n="" || n="-"

n=${signo}
n=${n}$(( $RANDOM * $RANDOM * $RANDOM ))

for i in $(seq 1 $len1)
do
    n=${n}" "$(( $RANDOM * $RANDOM * $RANDOM ))
done

echo $n

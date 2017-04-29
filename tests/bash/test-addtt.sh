#!/bin/bash



i=$(($RANDOM % 21))
j=$(($RANDOM % 21))

n=$(head /dev/urandom | tr -cd '0-9' | head -c $i)
m=$(head /dev/urandom | tr -cd '0-9' | head -c $j)

if [[ ! (-z $n || -z $m) ]]
then
    printf "$n $m. "
   ../addtt-cmp $n $m
fi

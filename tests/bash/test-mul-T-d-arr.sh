#!/bin/bash

ArrLen1=$(( $RANDOM % 9999 ))
ArrLen2=$(( $RANDOM % 9999 ))

n=$(./rand-arr.sh $ArrLen1 )

../muldt.exe $n
   

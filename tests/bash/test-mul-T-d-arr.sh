#!/bin/bash

ArrLen1=$(( $RANDOM % 99999 ))

printf "array_len: ${ArrLen1}. "
n=$(./rand-arr.sh $ArrLen1 )
../muldt  $n
   

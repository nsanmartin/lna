#!/bin/bash

ArrLen1=$(( $RANDOM % 9999 ))
ArrLen2=$(( $RANDOM % 9999 ))

n=$(./rand-arr.sh $ArrLen1 )
m=$(./rand-arr.sh $ArrLen2 )

py=$(./add-ar.py $n . $m )
lna=$(./add-ar.exe $n . $m )

if [[ "$py" == "$lna" ]]
then
    echo ok
else
    echo SUMANDO ${n}
    echo ----
    echo MAS ${m}
    while true; do echo error !!!; done
fi

   

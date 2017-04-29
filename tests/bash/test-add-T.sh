#!/bin/bash

counter=1

function iguales {
    if [[ "$1" == "$2" ]]
    then
        echo $((counter++)) ok
        
    else
        echo SUMANDO ${1}  MAS ${2}
        echo error !!!
        return 1
    fi
}

n=$(( $RANDOM * $RANDOM * $RANDOM ))
m=$(( $RANDOM * $RANDOM * $RANDOM ))

lna=$( ../add-TT $n $m)
gmp=$( ../gmp/add-gmp $n $m )

iguales ${lna} ${gmp}

for i in {1..199}
do
    for j in {1..199}
    do
        n=$(head /dev/urandom | tr -cd '0-9' | head -c $i)
        m=$(head /dev/urandom | tr -cd '0-9' | head -c $j)
        
        # lna=$( ../add-TT $n $m)
        # gmp=$( ../gmp/add-gmp $n $m )

#        iguales ${lna} ${gmp}
    done
done

    


s1=$RANDOM
s2=$RANDOM

n=$(cat /dev/urandom | tr -cd 0-9 | head -c $s1)
m=$(cat /dev/urandom | tr -cd 0-9 | head -c $s2)


lna=$( time (./test-add.out $n $m  > /dev/null ) 2>&1) 
gmp=$( time (./add-gmp.out $n $m > /dev/null ) 2>&1)

echo lna: $lna
echo gmp: $gmp

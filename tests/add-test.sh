
s1=$RANDOM
s2=$RANDOM

n=$(cat /dev/urandom | tr -cd 0-9 | head -c $s1)
m=$(cat /dev/urandom | tr -cd 0-9 | head -c $s2)


lna=$(./test-add.out $n $m)
gmp=$(./add-gmp.out $n $m)

if [ "$lna" == "$gmp" ]
then
    echo    test ok
    
else
    echo error!!!
    echo "s1: "$s1 "   s2: " $s2
    echo $lna > test
    echo >> test
    echo ======================================================== >> test
    echo $gmp >> test
    echo ======================================================== 
    echo
fi

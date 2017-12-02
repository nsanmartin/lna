s1=$RANDOM
s2=$RANDOM

if [ "$s2" -gt "$s1" ]
then
    tmp=$s1
    s1=$s2
    s2=$tmp
fi

if [ "$s2" -eq "$s1" ]
then
    $(( s2-- ))
fi

n=$(cat /dev/urandom | tr -cd 0-9 | head -c $s1)
m=$(cat /dev/urandom | tr -cd 0-9 | head -c $s2)

c=$(./sub $n $m)
py=$(./restar.py $n $m)

if [ "$c" == "$py" ]
then
    echo    test ok
else
    echo error!!!
    echo "s1: "$s1 "   s2: " $s2
    echo $c
    echo
    echo ======================================================== 
    echo $py
    echo ======================================================== 
    echo
fi

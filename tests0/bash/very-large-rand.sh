i=$(($RANDOM % 99999))
size=$(($RANDOM * ($RANDOM % $i) ))
#echo $size
cat /dev/urandom | tr -cd '0-9' | head -c $size

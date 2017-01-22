while true
do
    if [ $? -ne 0 ] ; then break
    fi
   . add-test.sh
   echo $((i++))
done 

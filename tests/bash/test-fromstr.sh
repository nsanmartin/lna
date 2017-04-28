for i in {1..1255}
do
    ../from-str.exe $( head /dev/urandom | tr -cd 0-9 | head -c "$i" )
done

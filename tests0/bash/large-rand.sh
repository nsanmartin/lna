


large-rand () {
    printf $((RANDOM%9+1))
    cat /dev/urandom | tr -cd '0-9' | head -c $RANDOM
}

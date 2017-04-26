#!/bin/bash

signo=$(( $RANDOM % 2 == 0 ? 1 : -1 ))

[[ $signo -eq 1 ]] && n="" || n="-"

n=${signo}
n=${n}$(( $RANDOM * $RANDOM * $RANDOM ))

ECHO $n

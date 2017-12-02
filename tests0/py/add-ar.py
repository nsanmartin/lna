#!/usr/bin/python

import sys
from subprocess import call

def foo(l, n, m):
    isn = True
    for x in l:
        if x == '.':
            isn = False
            continue
        if isn:
            n.append(x)
        else:
            m.append(x)

def l2num(lista):
    longitud = long (len(lista))
    res = 0
    for x in lista:
        if long(x) < 0:
            num = 2 ** 64  + long(x)
        else:
            num = long(x)
        res = res + ((2 ** 64) ** (longitud - 1)) * num
        longitud = longitud - 1
    return res
                           

def main(argv):
    try:
        nums = argv[1:]
    except getopt.GetoptError as err:
        print(str(err))  # will print something like "option -a not recognized"
        sys.exit(2)

    n = []
    m = []
    foo (nums, n, m)
    # n = l2num(n)
    # m = l2num(m)
 
    print("0x%x" % (l2num(n) + l2num(m)))
    ##    cmd = "../a.out " + " ".join(str(x) for x in nums)
    ##call(cmd, shell=True)
    
if __name__ == "__main__":
    if ( len(sys.argv) < 4 ):
        print("Usage: preg NUM [NUM ...] , NUM [NUM ...]")
        sys.exit(0)

    main(sys.argv)
          



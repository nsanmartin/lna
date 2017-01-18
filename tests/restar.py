#!/usr/bin/python

import sys

def main(argv):
    try:
        l1 = long(argv[1])
        l2 = long(argv[2])
    except getopt.GetoptError as err:
        # print help information and exit:
        print(str(err))  # will print something like "option -a not recognized"
        ##usage()
        sys.exit(2)
    output = None
    verbose = False

    resta = l1 - l2
    print("0x%x" % resta)
    
if __name__ == "__main__":
    if ( len(sys.argv) != 3 ):
        print("Usage: restar NUM1 NUM2")
        sys.exit(0)

    main(sys.argv)

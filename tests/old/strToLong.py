#!/usr/bin/python

import sys

def main(argv):
    try:
        l1 = long(argv[1])
    except getopt.GetoptError as err:
        # print help information and exit:
        print(str(err))  # will print something like "option -a not recognized"
        ##usage()
        sys.exit(2)
    output = None
    verbose = False

    print("0x%x" % l1)
    
if __name__ == "__main__":
    main(sys.argv)

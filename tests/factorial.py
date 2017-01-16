from math import factorial
import sys

def main(argv):
    if len (argv) != 2:
        print("Usage: fatorial NUMBER\n")
        return 0
    num = int (argv [1])
    print (hex (factorial (num) ) )
    return 0

if __name__ == "__main__":
    main(sys.argv)




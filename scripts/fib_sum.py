#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     13/05/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

def toint(s): return int(s)
def tofloat(s): return float(s)

def get_int():
    s=raw_input()
    return int(s)

def main():
        t=get_int()

        a=1
        b=1
        sum=2
        for i in range(2,t):
            c=b+a
            a=b
            b=c
            sum+=c
        print sum

        pass

if __name__ == '__main__':
    main()

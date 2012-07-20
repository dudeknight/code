#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     05/03/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

import string

def toint(s): return int(s)
def tofloat(s): return float(s)

def get_int():
    s=raw_input()
    return int(s)
def get_line_int():
    s=raw_input()
    arr=string.split(s)
    arr=map(toint,arr)
    return arr


def main():
    t=get_int()
    while t:
        arr=get_line_int()
        if(arr[0]==1 and arr[1]==1 and arr[2]==1):
            print 1

        elif(2*arr[1]==arr[0]+arr[2]):
            print arr[2]+arr[1]-arr[0]
        else:
            print arr[2]*arr[1]/arr[0]

        t=-1
    pass

if __name__ == '__main__':
    main()

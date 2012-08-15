#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     03/08/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------

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
def get_line_float():
    s=raw_input()
    arr=string.split(s)
    arr=map(tofloat,arr)
    return arr

def main():
    t = get_int()
    while t:
        arr = get_int()
        arr = get_line_int()
        res = 0
        for i in arr:
            if (i > 4):
                res = 0;
                break;
            if (i > 2):
                res += i - 2
        if (res % 2 == 0):
            print 'BOB'
        else :
            print 'ALICE'
        t -= 1
    pass

if __name__ == '__main__':
    main()

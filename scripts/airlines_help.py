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

def correct(x):
    p = []
    for i in range(15):
        p.append(x % 2)
        x /= 2
    for i in range(14):
        if (p[i] == 1 and p[i + 1] == 1):
            return False
    print p
    return True

def main():
    res = 0
    for i in range(1<<15):
        if correct(i):
            res += 1
    print res
    pass

if __name__ == '__main__':
    main()

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
    n = get_int()
    a = get_line_int()
    a = sorted(a)
    b = False
    res = 0
    for i in range(n - 1):
        if b:
           b = False
        else :
            if (a[i + 1] - a[i] == 1):
                res += 2
                b = True
    res += (400000 * (n / 2) * ((n + 1) / 2))
    print res
    pass


if __name__ == '__main__':
    main()

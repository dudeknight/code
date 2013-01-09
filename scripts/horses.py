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
        n = get_int()
        arr = get_line_int()
        arr = sorted(arr)
        d = arr[1] - arr[0]
        for i in range(1, n - 1):
            d = min(arr[i + 1] - arr[i], d)
        print d
        t -= 1
    pass

if __name__ == '__main__':
    main()

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

def toint(s): return long(s)
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
    a = []
    b = []
    a1 = []
    b1 = []
    for i in range(n):
        arr = get_line_int()
        a.append(arr[0])
        b.append(arr[1])
        a1.append(arr[0] + arr[1])
        b1.append(arr[1] - arr[0])
    a1 = sorted(a1)
    b1 = sorted(b1)
    res = 0.0
    temp = 0
    x1 = a1[n / 2]
    y1 = b1[n / 2]
    x = (x1 - y1) / 2.0
    y = (x1 + y1) / 2.0
    for i in range(n):
        res += max(abs(a[i] - x), abs(b[i] - y))
    res = long(res)
    print res
    pass

if __name__ == '__main__':
    main()

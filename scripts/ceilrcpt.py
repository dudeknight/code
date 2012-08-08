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
        res = 0
        cur = 1
        cnt = 1
        while n != 0:
            if (n%2 == 1):
                res += cur
            if (cnt >= 12):
                cur *= 2
            n /= 2
            cnt += 1
        print res
        t -= 1
    pass

if __name__ == '__main__':
    main()

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

mod = 1000000007


def fast_exp(n, p):
    res = 1
    while p:
        if (p % 2):
            res = res * n
            res %= mod
        n = n * n
        n %= mod
        p >>= 1
    return res

def main():
    t = get_int();
    while t:
        n = get_int()
        res = 0
        if (n % 2 == 0):
            res = 2*(fast_exp(2, n / 2 + 1) - 1) - fast_exp(2, n / 2)
        else :
            res = 2*(fast_exp(2, n / 2 + 1) - 1)
        res %= mod
        print res
        t -= 1
    pass

if __name__ == '__main__':
    main()

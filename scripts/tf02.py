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
    s = raw_input()
    return int(s)
def get_line_int():
    s = raw_input()
    arr = s.rstrip('[\n\r]').split(' ')
    arr = map(toint,arr)
    return arr
def get_line_float():
    s = raw_input()
    arr = s.rstrip('[\n\r]').split(' ')
    arr = map(tofloat,arr)
    return arr

def main():
    arr = get_line_int()
    n = arr[0]
    m = arr[1]
    mod = 1009
    a = [1] * 1020
    arr = get_line_int()
    res = 0
    y = m / mod
    y %= mod
    x = m % mod
    for i in range(n + 1):
        cnt = 0
        for j in range(mod):
            cnt += a[j]
            cnt %= mod
        res += (y * cnt * arr[n - i])
        res %= mod
        cnt = 0
        for j in range((x + 1) % mod):
            cnt += a[j]
            cnt %= mod
        res += (cnt * arr[n - i])
        res %= mod
        for j in range(mod):
            a[j] *= j;
            a[j] %= mod
    print res
    pass

if __name__ == '__main__':
    main()

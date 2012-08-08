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
        arr = get_line_int()
        n = arr[0]
        p = arr[1]
        #print n, p
        res = 0
        key = 1
        temp = 0
        temp1 = 0
        while n:
            temp = n % p + 1
            temp1 = p - temp
            n /= p
            res += n * temp1 * key
            key *= (temp)
            if key == 0:
                break
        print res
        t -= 1
    pass

if __name__ == '__main__':
    main()

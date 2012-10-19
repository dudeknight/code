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

n = 0

def rec_funcn(a, x, y):
    if (y == n):
        if (x == 0):
            print a
        return;
    else :
        rec_funcn(a + '{', x + 1, y + 1)
        if (x > 0):
            rec_funcn(a + '}', x - 1, y + 1)
    return;

def main():
    global n
    n = get_int()
    rec_funcn('', 0, 0)
    pass

if __name__ == '__main__':
    main()

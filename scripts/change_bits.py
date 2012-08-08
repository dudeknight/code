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
    arr =get_line_int()
    n = arr[0]
    q = arr[1]
    k = int(math.sqrt(n))
    k += 1
    a = [0] * k
    b = [0] * k
    c = [0] * k
    s = raw_input()
    for i in range(n):
        
    s = raw_input()
    for i in range(n):

    for i in range(n):
        
    while q:

        q -= 1
    pass

if __name__ == '__main__':
    main()

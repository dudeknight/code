#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     03/11/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

import string
import math

def toint(s): return int(s)

def get_int():
    s=raw_input()
    return int(s)
def get_line_int():
    s=raw_input()
    arr=string.split(s)
    arr=map(toint,arr)
    return arr
def get_float():
    s=raw_input()
    return float(s)


def main():
    s=raw_input()
    while s!='.':
        arr=string.split(s)
        arr[1]=int(arr[1])
        s=''
        n=len(arr[0])
        for i in range(arr[1]):
            s+=arr[0]
        for i in range(n):
            print s
            s=s[1:]+s[0:1]
        s=raw_input()
    pass

if __name__ == '__main__':
    main()

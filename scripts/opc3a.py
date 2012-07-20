#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     13/05/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------


import string

def toint(s): return int(s)
def tofloat(s): return float(s)

def get_int():
    s=raw_input()
    return int(s)


def main():
    a=[0]*1000001
    mod=1000000007
    a[0]=1
    a[1]=2
    a[2]=2
    for i in range(3,1000001):
        a[i]=a[i-1]*a[i-2]
        a[i]%=mod
    t=get_int()
    while t:
        n=get_int()
        print a[n]
        t-=1

    pass

if __name__ == '__main__':
    main()

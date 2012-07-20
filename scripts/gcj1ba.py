#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     05/05/2012
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
    t=get_int()
    cnt=1
    while t:
        arr=get_line_int()
        n=arr[0]
        y=0.0

        for i in range(n):
            y+=float(arr[1+i])
        print 'Case #'+str(cnt)+':',
        for i in range(n):
            res=100.0*(2.0*y-n*arr[i+1])/(n*y)
            if(res<0): res=0
            print '%.6f'%res,
        cnt+=1
        print ''

        t-=1
    pass

if __name__ == '__main__':
    main()

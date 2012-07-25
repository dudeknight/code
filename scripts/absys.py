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
        s = raw_input()
        s = raw_input()
        arr = string.split(s)
        #print arr
        if (string.find(arr[0],'machula') != -1):
            print int(arr[4]) - int(arr[2]),'+',arr[2],'=',arr[4]
        elif (string.find(arr[2],'machula') != -1):
            print arr[0],'+',int(arr[4]) - int(arr[0]),'=',arr[4]
        else:
            print arr[0],'+',arr[2],'=',int(arr[0])+int(arr[2])            
        t -= 1
    pass

if __name__ == '__main__':
    main()

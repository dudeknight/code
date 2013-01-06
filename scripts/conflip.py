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
    t = get_int()
    while t:
        g = get_int()
        while g:
            arr = get_line_int()
            n = arr[1]
            if (n % 2 == 0):
                print n / 2
            else :
                if (arr[0] == arr[2]):
                    print n / 2
                else :
                    print (n + 1) / 2
            g -= 1
        t -= 1
    pass

if __name__ == '__main__':
    main()

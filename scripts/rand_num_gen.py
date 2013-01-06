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
from fractions import Fraction

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
        arr = get_line_int()
        if (arr[0] + arr[1] <= arr[2]) :
            print '1/1'
        else :
            tol = arr[2] - arr[1]
            if (tol < 0):
                tol = 0
            tol_part = Fraction(tol, arr[0] * arr[1])

            low_lim = tol
            high_lim = min(arr[0], arr[2])
            rem_part = Fraction(2 * arr[2] * (high_lim - low_lim) - ((high_lim * high_lim) - (low_lim * low_lim)), 2 * arr[0] * arr[1])
            f_total = rem_part + tol_part

            if (f_total == 1):
                print '1/1'
            elif (f_total == 0):
                print '0/1'
            else:
                print f_total

        t -= 1
    pass

if __name__ == '__main__':
    main()

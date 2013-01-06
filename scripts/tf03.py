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
import bisect

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
    maxs = 10000000
    mod = 10000
    a  = [0] * (maxs + 1)
    a[0] = 1;
    dp = [0] * maxs
    dp[0] = 1;
    cur_max = 1;
    for i in range(1, maxs + 1):
        x = (i + 1) * (i + 1)
        x %= mod
        y = bisect.bisect_left(dp, x, 0, cur_max)
        if (y == cur_max):
            dp[cur_max] = x;
            cur_max += 1
            if (cur_max == 1044):
                print i
                break
        elif (dp[y] > x):
            dp[y] = x
        a[i] = cur_max
    print cur_max
    pass

if __name__ == '__main__':
    main()

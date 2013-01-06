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
    cnt = 1
    s = set()
    s.add((1, 2))
    print s
    modi = 142857
    for i in range(2, 1042857):
        cnt = cnt * i
        cnt = cnt % modi
        t = (cnt, (i + 1) % modi)
        print i
        if t in s:
            print 'hey found',i
            print t
            break
        else:
            s.add(t)

    pass

if __name__ == '__main__':
    main()

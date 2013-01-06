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
    a = ['0'] * 5010
    b = ['0'] * 5010
    c = ['0'] * 5010
    lt = [0] * 5010
    rt = [0] * 5010
    st = [0] * 5010
    t = get_int()
    while t:
        n = get_int()
        d = dict()
        cur = 0
        for i in range(n):
            lt[i] = -1
            rt[i] = -1
        tot = 0
        for i in range(n - 1):
            s = raw_input()
            stx = s.rstrip('\n').split(' ')
            a[i] = stx[0]; b[i] = stx[1]; c[i] = stx[2]
            tot += int(stx[2][:-1])
            if a[i] in d:
                lt[d[a[i]]] = i
            else :
                d[a[i]] = cur
                lt[cur] = i
                cur += 1
            if b[i] in d:
                rt[d[b[i]]] = i
            else :
                d[b[i]] = cur
                rt[cur] = i
                cur += 1
        for i in range(n):
            if (lt[i] == -1):
                cur = i
                break
        st[0] = cur
        for i in range(1, n - 1):
            cur = lt[d[b[cur]]]
            st[i] = cur
        for i in range(n - 1):
            print a[st[i]], b[st[i]], c[st[i]]
        print str(tot) + '$'
        t -= 1
    pass

if __name__ == '__main__':
    main()

#!/usr/bin/env python

import string

from sets import Set

def toint(s): return int(s)

def get_int():
    s=raw_input()
    return int(s)
def get_line_int():
    s=raw_input()
    arr=string.split(s)
    arr=map(toint,arr)
    return arr


def main():
    s=Set()
    d=dict()
    t=get_int()
    n=t
    while t:
        arr=get_line_int()
        s.add(arr[0])
        for i in range(arr[1]):
            s.add(arr[2+i])
        t-=1
    print len(s)-n
    pass


if __name__ == '__main__':
    main()

#!/usr/bin/env python

import string

def toint(s): return int(s)

def get_int():
    s=raw_input()
    return int(s)

def get_line_int():
    s=raw_input()
    arr=string.split(s)
    arr=map(toint,arr)
    return arr

def size(s): return len(s)

def main():
    while 1:
        try:
            s=raw_input()
            if(s=='1'): print '1'
            elif(s=='0'): print '0'
            else:   print 2*(long(s)-1)
        except(EOFError):
            break
    pass

if __name__ == '__main__':
    main()



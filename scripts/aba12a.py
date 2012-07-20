#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     02/12/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
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
    t=get_int()
    while t:
        res=get_line_int()
        t-=1
        print res[1]
    pass

if __name__ == '__main__':
    main()



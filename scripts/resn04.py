#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     03/11/2012
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


def main():
    t=get_int()
    while t:
        n=get_int()
        arr=get_line_int()
        res=0
        for i in range(n):
            res+=arr[i]/(i+1)
        if(res&1):
            print 'ALICE'
        else:
            print 'BOB'
        t-=1
    pass

if __name__ == '__main__':
    main()

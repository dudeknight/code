#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     05/03/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------



def toint(s): return int(s)
def tofloat(s): return float(s)

def get_int():
    s=raw_input()
    return int(s)

def main():
    t=get_int()
    while t:
        j=raw_input()
        s=raw_input()

        a=[0]*256
        for i in j:
            a[ord(i)]=1
        res=0
        for i in s:
            res+=a[ord(i)]
        print res
        t-=1
    pass

if __name__ == '__main__':
    main()

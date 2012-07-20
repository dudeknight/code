#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     13/05/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import string
import math
def toint(s): return int(s)
def tofloat(s): return float(s)

def get_int():
    s=raw_input()
    return int(s)

def main():
    t=get_int()
    while t:
        n=get_int()
        if(n==3):
            print 3
        else:
            x=math.ceil(math.log(n,2))+1
            print int(x)
        t-=1
    pass

if __name__ == '__main__':
    main()

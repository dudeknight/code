#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     23/04/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------

rst=[231552,234756,596873,648219,726312,981237,988331,1277361,1283379]
rng=100000

def get_int():
    s=raw_input()
    return int(s)

def main():
    x=[0]*1000001
    for i in range(rng):
        a=get_int()
        x[a]=1
    res=[0]*9
    for j in range(9):
        for i in range(1,rng*10+1):
            if(x[i] and rst[j]-i<=rng*10 and rst[j]-i>=0 and x[rst[j]-i]):
                res[j]=1
                break
    print str(res)
    pass

if __name__ == '__main__':
    main()

#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     02/03/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python
import string

#for i in range(2,1000):



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
    while(t):
        n=get_line_int()
        print n[0]*(2*n[1]+(n[0]-1)*n[2])/2
        t-=1
    pass

if __name__ == '__main__':
    main()

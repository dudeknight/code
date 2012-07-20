#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     25/03/2012
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
    arr=get_line_int()
    while(arr[0]!=-1):
        if(arr[0]*37==arr[1]*1000):
            print 'Y'
        else:
            print 'N'
        arr=get_line_int()
    pass

if __name__ == '__main__':
    main()

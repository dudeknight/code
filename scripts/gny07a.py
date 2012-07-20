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
import math

def toint(s): return int(s)

def get_int():
    s=raw_input()
    return int(s)
def get_line_int():
    s=raw_input()
    arr=string.split(s)
    arr=map(toint,arr)
    return arr
def get_float():
    s=raw_input()
    return float(s)


def main():
    t=get_int()
    x=1
    while t:
        s=raw_input()
        arr=string.split(s)
        i=int(arr[0])-1
        temp=''
        if(i==0):
            temp=arr[1][1:]
        elif(i==len(arr[1])-1):
            temp=arr[1][0:len(arr[1])-1]
        else:
            temp=arr[1][0:i]+arr[1][i+1:]
        print x,temp
        x+=1
        t-=1
    pass

if __name__ == '__main__':
    main()

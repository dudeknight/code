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
        arr[0]=float(arr[0])
        temp=''
        if(arr[1]=='kg'):
            temp1=arr[0]*2.2046
            temp='%.4f'%temp1+' lb'
        elif(arr[1]=='lb'):
            temp1=arr[0]*0.4536
            temp='%.4f'%temp1+' kg'
        elif(arr[1]=='l'):
            temp1=arr[0]*0.2642
            temp='%.4f'%temp1+' g'
        elif(arr[1]=='g'):
            temp1=arr[0]*3.7854
            temp='%.4f'%temp1+' l'
        print x,temp
        x+=1
        t-=1
    pass

if __name__ == '__main__':
    main()

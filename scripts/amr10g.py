#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     02/04/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

import string

def toint(s): return int(s)

arr=[]
INF=1000000000
def get_int():
    s=raw_input()
    return int(s)
def get_line_int():
    global arr
    s=raw_input()
    arr=string.split(s)
    arr=map(toint,arr)

def main():
    global arr
    t=get_int()
    while(t):
        get_line_int()
        n=arr[0]
        k=arr[1]
        get_line_int()
        arr=sorted(arr)
        mini=INF
        for i in range(n-k+1):
            mini=min(mini,arr[i+k-1]-arr[i])
            if mini==0: break
        print mini
        t-=1
    pass

if __name__ == '__main__':
    main()

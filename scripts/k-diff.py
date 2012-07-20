#!/usr/bin/env python

#pta with hidden layer and single ouput
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

def main():
    arr=get_line_int()
    n=arr[0]
    k=arr[1]
    arr=get_line_int()
    arr=sorted(arr)
    i=0
    j=1
    res=0
    while j<n:
        diff=arr[j]-arr[i]
        if diff<k:
            j+=1
        elif diff>k:
            i+=1
        else:
            res+=1
            i+=1
            j+=1
    print res
    pass

if __name__ == '__main__':
    main()

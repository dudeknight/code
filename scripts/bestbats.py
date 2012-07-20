#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     22/04/2012
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


def main():
    t=get_int()
    while t:
        arr=get_line_int()
        arr=sorted(arr)
        k=get_int()
        maxi=arr[11-k]
        cnt=0;
        for i in range(k):
            if(arr[11-k+i]==maxi):
                cnt+=1
        cnt2=0
        for i in range(11):
            if(arr[i]==maxi):
                cnt2+=1
        print math.factorial(cnt2)/(math.factorial(cnt)*math.factorial(cnt2-cnt))
        t-=1
    pass

if __name__ == '__main__':
    main()

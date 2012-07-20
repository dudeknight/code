#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     07-02-2012
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

pg=[0]*500
dp=[[0]*500]*500
dp_bt=dp
n=0
k=0


def solve():
    global pg,n,k,dp,dp_bt

    dp[n-1][k-1]=pg[n-1]
    dp_bt[n-1][k-1]=1

    for i in range(n-2,-1,-1):
        for j in range(k-1,k-n-1+i,-1):
            dp[i][j]=1

def main():
    global pg,n,k
    t=get_int()
    while t:
        arr=get_line_int()
        n=arr[0]
        k=arr[1]
        pg=get_line_int()
        solve()
        t-=1
    pass

if __name__ == '__main__':
    main()

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
    n=get_int()
    t=1
    while n:
        val=get_line_int()
        dp=[[10000000,val[1],val[1]+val[2]],[0,0,0]]
        for i in range(1,n):
            val=get_line_int()
            dp[(i&1)^0][0]=val[0]+min(dp[(i&1)^1][0],dp[(i&1)^1][1])
            dp[(i&1)^0][1]=val[1]+min(min(dp[(i&1)^0][0],dp[(i&1)^1][1]),dp[(i&1)^1][2])
            dp[(i&1)^0][2]=val[2]+min(min(dp[(i&1)^0][1],dp[(i&1)^1][1]),dp[(i&1)^1][2])
        print str(t)+'.'+str(dp[(n&1)^1][1])
        t+=1
        n=get_int()
    pass

if __name__ == '__main__':
    main()

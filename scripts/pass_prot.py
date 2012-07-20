#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     29/04/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------


import string

def toint(s): return int(s)
def tofloat(s): return float(s)

def get_int():
    s=raw_input()
    return int(s)
def get_line_int():
    s=raw_input()
    arr=string.split(s)
    arr=map(toint,arr)
    return arr
def get_line_float():
    s=raw_input()
    arr=string.split(s)
    arr=map(tofloat,arr)
    return arr


def main():
    t=get_int()
    cnt=1
    while t:
        arr=get_line_int()
        a=arr[0]
        b=arr[1]
        prob=get_line_float()
        prob.append(0)
        fwdprob=[]
        bckprob=[]
        fwdprob.append(1)
        bckprob.append(1)
        for i in range(1,a+1):
            fwdprob.append(prob[i-1]*fwdprob[i-1])
            bckprob.append(bckprob[i-1]*prob[a-i])
        bckprob.reverse()
        bckprob.append(1)
        x=0
        res=0
        res2=0
        print prob
        print fwdprob
        print bckprob
        while x*2<(a+1):
            p=fwdprob[a-x]*bckprob[a-x+1]*(1-prob[a-x])
            res+=p
            print x,p
            res2+=2*x*p
            x+=1
        res2+=b-a+1
        res2+=(1-res)*(a+1)


        print 'Case #'+str(cnt)+':',res2
        cnt+=1
        t-=1
    pass

if __name__ == '__main__':
    main()

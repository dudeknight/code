#!/usr/bin/env python

from math import ceil

def get_int():
    s=raw_input()
    return int(s)

a=[]
b=[0]*3
def main():
    t=get_int()
    while t:
        s=raw_input()
        if(s=='1/4'):
            b[0]+=1
        elif(s=='1/2'):
            b[1]+=1
        else:
            b[2]+=1
        t-=1
    res=1
    print b
    res+=min(b[2],b[0])
    tmp=min(b[2],b[0])
    b[2]=b[2]-tmp
    b[0]=b[0]-tmp
    res+=b[0]/4
    b[0]=b[0]%4
    res+=b[1]/2
    b[1]%=2
    tmp=min(b[1],b[0]/2)
    res+=tmp
    b[1]-=tmp
    b[0]-=2*tmp
    res+=ceil(b[0]/4.0)+ceil(b[1]/2.0)+b[2]

    print int(res)-1
    pass

if __name__ == '__main__':
    main()

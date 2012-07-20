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
    t=get_int()
    while(t):
        n=get_int()
        arr=get_line_int()
        arr=sorted(arr)
        c1=0
        c2=1
        temp=1
        for i in range (1,n):
            if(arr[i]==arr[i-1]): temp+=1
            else:
                if c2<temp :
                    c2=temp
                    c1=i-1
                    temp=1
        if(c2<temp):
            c2=temp
            c1=n-1
        print arr[c1],c2
        t-=1
    pass

if __name__ == '__main__':
    main()

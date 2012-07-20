#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     03/09/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

def get_int():
    s=raw_input()
    return int(s)

r={'ab':'c','bc':'a','ca':'b','ba':'c','cb':'a','ac':'b'}

def func(x):
    n=len(x)
    if n==1:
        return 1
    if(n==2):
        if(x[0]==x[1]):
            return 2
        else:
            return 1
    cur=n
    for i in range(n-1):
        if(x[i]!=x[i+1]):
            temp=r[x[i:i+2]]+x[i+2:]
            temp=x[0:i]+temp
            temp=func(temp)
            if(temp<cur):
                cur=temp
    return cur


def main():
    t=get_int()
    while t:
        s=raw_input()
        print func(s)
        t-=1
    pass

if __name__ == '__main__':
    main()

#!/usr/bin/env python

def get_int():
    s=raw_input()
    return int(s)

a=[0]*1000000
a[2]=1
for i in range(3,1000000):
    a[i]=a[i-2]+(i*(i-1)/2)

def f(n):
    return (n*(n+1)*(2*n+1)+3*n*(n+1))/12

def main():
    t=get_int()
    while t:
        n=get_int()
        print a[n]+f(n)
        t-=1
    pass

if __name__ == '__main__':
    main()

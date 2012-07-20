#!/usr/bin/env python

def get_int():
    s=raw_input()
    return int(s)

a=[]
n=0
def merge(i,j,k):
    global a
    x=i
    y=j
    b=[]
    while(x<j and y<k):
        if(a[x]<a[y]):
            b.append(a[x])
            x+=1
        else:
            b.append(a[y])
            y+=1
    if(x<j):
        while(x<j):
            b.append(a[x])
            x+=1
    if(y<k):
        while(y<k):
            b.append(a[y])
            y+=1
    a[i:k]=b

def count(i,j,k):
    res=0
    global a
    x=i
    y=j
    #print i,' ',j,' ',k
    while(x<j and y<k):
        #print x,' ',y
        if(a[x]<=a[y]):
            res+=(y-j)
            x+=1
        else:
            y+=1
    if(x<j):
        while(x<j):
            res+=(k-j)
            x+=1

    return res

def func():
    res=0
    m=1
    global n
    global a
    while(m<n):
        i=0
        while(i<n-m):
            res+=count(i,i+m,min(i+2*m,n))
            merge(i,i+m,min(i+2*m,n))
            i+=2*m
        m*=2
    return res

def main():
    global a
    global n
    t=get_int()
    #s=raw_input()
    while(t>0):
        n=get_int()
        a=[]
        for id in range(n):
            a.append(get_int())
        print func()
        #s=raw_input()
        t-=1
    pass

if __name__ == '__main__':
    main()

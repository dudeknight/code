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

arr=get_line_int()
n=arr[0]
k=arr[1]

val=[]
for i in range(n):
    val.append(get_int())

a=[0]*(k+1)
b=[0]*(k+1)
for i in range(1,k+1):
    a[i]=val[n-1]
print a
for i in range(n-2,-1,-1):
    b[0]=a[k]
    for j in range(1,k+1):
        b[j]=max(a[k],a[j-1]+val[i])
    for j in range(k+1):
        a[j]=b[j]
    print a
#print a
print a[k]


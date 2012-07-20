#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     02/03/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python
import string
from  math import sqrt
a=[]

seive=[0]*100000

for i in range(2,1001):
   if seive[i]==0 :
        a.append(i)
        for j in range(2,(1001/i)+1):
            seive[j*i]=1

#for i in range(2,1000):



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
        m=int(sqrt(n))
        res=1
        for i in a:
            if i > m : break
            k=i
            temp=0
            while n%k==0:
                temp+=1
                k*=i
            res=max(temp,res)
        print res
        t-=1
    pass

if __name__ == '__main__':
    main()

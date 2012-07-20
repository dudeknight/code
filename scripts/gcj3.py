#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     14/04/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env pytimport string

import math
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
    cnt=1
    flg=[0]*2000001

    dr=dict()

    for i in range(1,2000000):
          if(not flg[i]):
                d=set()
                d.add(i)
                n=int(math.log10(i))
                n+=1
                x=10
                y=int(pow(10,n-1))
                for j in range(n-1):
                    tmp=i%x
                    tmp=tmp*y
                    tmp+=(i/x)
                    if(tmp>=1 and tmp<=2000000):
                        d.add(tmp)
                        flg[tmp]=1

                    y/=10
                    x*=10
                for j in d:
                    dr[j]=d
    print 'done'
    while t:
        st=get_line_int()
        a=st[0]
        b=st[1]
        for i in range(a,b+1):
            flg[i]=0;
        dt=0
        for i in range(a,b+1):

            if(not flg[i]):
                d=set()
                d.add(i)
                n=int(math.log10(i))
                n+=1
                x=10
                y=int(pow(10,n-1))
                for j in range(n-1):
                    tmp=i%x
                    tmp=tmp*y
                    tmp+=(i/x)
                    if(tmp>=a and tmp<=b):
                        d.add(tmp)
                        flg[tmp]=1

                    y/=10
                    x*=10

                k=len(d)
                dt+=(k*(k-1))/2
        print 'Case #'+str(cnt)+':',dt
        cnt+=1
        t-=1
    pass


    pass

if __name__ == '__main__':
    main()

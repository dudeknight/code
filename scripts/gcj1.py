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


src=['ejp mysljylc kd kxveddknmc re jsicpdrysi','rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd','de kr kd eoya kw aej tysr re ujdr lkgc jv']
dst=['our language is impossible to understand','there are twenty six factorial possibilities','so it is okay if you want to just give up']

d=dict()

def main():
    for i in range(3):
        p=src[i]
        q=dst[i]
        for k in range(len(p)):
            d[p[k]]=q[k]
    b=[0]*28
    d['q']='z'
    for i in d:
        if i==' ': continue;
        b[ord(d[i])-ord('a')]=1
    for i in range(26):
        if(b[i]==0):
            d['z']=chr(i+ord('a'))

    b=[0]*28
    for i in d:
        if i==' ': continue;
        b[ord(d[i])-ord('a')]+=1
        if(b[ord(d[i])-ord('a')]>1):
            print 'error'
            break;
    #print len(d)

    t=get_int()
    cnt=1
    while t:
        st=raw_input()

        st=string.rstrip(st)
        dt=''
        print 'Case #'+str(cnt)+':',
        for i in st:

            dt+=d[i]
        print 'Case #'+str(cnt)+':',dt
        cnt+=1
        t-=1
    #


    pass

if __name__ == '__main__':
    main()

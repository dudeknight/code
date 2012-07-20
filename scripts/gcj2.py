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

def main():
    #generate all the possible possbilites
    dws=[0]*32
    ds=[0]*32
    for i in range(11):
        for j in range(11):
            for k in range(11):
                if(max(max(i,j),k)-min(min(i,j),k)<2):
                    dws[i+j+k]=max(dws[i+j+k],max(max(i,j),k))
                    pass
                if(max(max(i,j),k)-min(min(i,j),k)==2):
                    ds[i+j+k]=max(ds[i+j+k],max(max(i,j),k))
                    pass
    #print dws
    #print ds
    t=get_int()
    cnt=1
    while t:
        st=get_line_int()
        dt=0;
        n=st[0]
        s=st[1]
        p=st[2]
        scount=0
        for i in range(n):
            if(dws[st[i+3]]>=p):
                dt+=1
            elif(ds[st[i+3]]>=p and s>0):
                dt+=1
                s-=1
        print 'Case #'+str(cnt)+':',dt
        cnt+=1
        t-=1
    pass

if __name__ == '__main__':
    main()

#!/usr/bin/env python

import string

def toint(s): return int(s)

def get_int():
    s=raw_input()
    return int(s)


def main():
    t=get_int()
    a=[0]*26
    while t:
        s=raw_input()
        for i in range(26):
            a[i]=0
        maxi=0
        for j in s:
            if(j!=' '):
                a[ord(j)-ord('A')]+=1
        for i in range(26):
            maxi=max(maxi,a[i])
        flag=False
        c=0
        for i in range(26):
            if(a[i]==maxi):
                c=i
                if(not flag):
                    flag=True
                else:
                    flag=False
                    break
        if(not flag):
            print 'NOT POSSIBLE'
        else:
            cpr=(c-4+26)%26
            res=''
            for i in s:
                if(i==' '):
                    res+=i
                else:
                    res+=chr(ord('A')+((ord(i)-ord('A')-cpr)%26))
            print cpr,res
        t-=1
    pass

if __name__ == '__main__':
    main()

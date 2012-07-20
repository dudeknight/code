#!/usr/bin/env python

import string

def get_int():
    s=raw_input()
    return int(s)


def main():
    t=get_int()
    id=1
    while t:
        a=[]
        b=[]
        for i in range(10):
            s=raw_input()
            arr=string.split(s)
            a.append(arr[0])
            b.append(int(arr[1]))
        maxi=0
        for i in range(10):
           maxi=max(maxi,b[i])
        print 'Case #'+str(id)+':'
        for i in range(10):
            if(b[i]==maxi):
                print a[i]
        t-=1
        id+=1
    pass

if __name__ == '__main__':
    main()

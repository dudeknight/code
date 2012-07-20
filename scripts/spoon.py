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
    t=get_int()
    while t:
        arr=get_line_int()
        r=arr[0]
        c=arr[1]
        a=[]
        for i in range(r):
            a.append(raw_input().lower())
        flag=False
        for i in range(r):
            for j in range(c-4):
                if a[i][j]=='s' and a[i][j+1]=='p' and a[i][j+2]=='o' and a[i][j+3]=='o' and  a[i][j+4]=='n':
                    flag=True
                    break
            if flag: break
        if flag:
            print 'There is a spoon!'
            t-=1
            continue
        for j in range(c):
            for i in range(r-4):
                if a[i][j]=='s' and a[i+1][j]=='p' and a[i+2][j]=='o' and a[i+3][j]=='o' and  a[i+4][j]=='n':
                    flag=True
                    break
            if flag: break
        if flag:
            print 'There is a spoon!'
            t-=1
            continue
        print 'There is indeed no spoon!'
        t-=1
    pass

if __name__ == '__main__':
    main()

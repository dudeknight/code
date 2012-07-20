#!/usr/bin/env python

def get_int():
    s=raw_input()
    return int(s)

def main():
    n=get_int()
    while n!=-1:
        a=[]
        sum=0
        for i in range(n):
            a.append(get_int())
            sum+=a[i]
        flag=True
        if(sum%n!=0): flag=False
        x=sum/n
        sum=0
        a=sorted(a)
        for i in range(n):
            sum+=abs(a[i]-x)
        if flag: print sum/2
        else : print '-1'
        n=get_int()
    pass

if __name__ == '__main__':
    main()

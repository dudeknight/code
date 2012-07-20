#!/usr/bin/env python
def get_int():
    s=raw_input()
    return int(s)


def main():
    n=get_int()
    a=[]
    while n:
        a.append(0)
        for i in range(n):
            a.append(get_int())
        a=sorted(a)
        flag=True
        if(1422-a[n]>100):flag=False
        for i in range(1,n+2):
            if(a[i]-a[i-1] > 200):
                flag=False
                break
        if flag:print 'POSSIBLE'
        else :print 'IMPOSSIBLE'
        a=[]
        n=get_int()
        pass

if __name__ == '__main__':
    main()

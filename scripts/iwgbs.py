#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     17/02/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

def get_int():
    s=raw_input()
    return int(s)

def main():
    t=get_int()
    a=[]
    for i in range(t):
        a.append([0]*2)
    a[t-1][0]=1
    a[t-1][1]=1
    for i in range(t-2,-1,-1):
        a[i][0]=a[i+1][1]
        a[i][1]=a[i+1][0]+a[i+1][1]
    print a[0][0]+a[0][1]
    pass

if __name__ == '__main__':
    main()

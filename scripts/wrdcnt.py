#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     02/12/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

import string

def get_int():
    s=raw_input()
    return int(s)

def size(s): return len(s)

def main():
    t=get_int()
    while t:
        s=raw_input()
        arr=string.split(s)
        arr=map(size,arr)
        #print arr
        res=0
        res_temp=1
        cur_size=arr[0]
        for i in range(1,len(arr)):
            if(arr[i]==cur_size): res_temp+=1
            else:
                res=max(res,res_temp)
                cur_size=arr[i]
                res_temp=1
        res=max(res,res_temp)
        t-=1
        print res
    pass

if __name__ == '__main__':
    main()

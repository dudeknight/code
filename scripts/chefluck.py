#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     05/03/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import math
import re



def get_int():
    s=raw_input()
    return int(s)

def main():
    #form the list of numbers less than 10^9

    resid=2
    lst=[4,7]
    for i in range(2,10):
        x=len(lst)
        for i in range(x-resid,x):
            lst.append(lst[i]*10+4)
        for i in range(x-resid,x):
            lst.append(lst[i]*10+7)
    lst=sorted(lst)
    set_lst=set(lst)
    # the program for the question
    lst=[0,8,16,24,4,12,20]
    t=get_int()
    while t:
        n=get_int()
        res=(n-lst[n%7])
        if(res<0):
            print -1
        else:
            print res
        t-=1

    pass

if __name__ == '__main__':
    main()

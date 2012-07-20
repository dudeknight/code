#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     25/03/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

import string

def toint(s): return int(s)

def get_int():
    s=raw_input()
    return int(s)

def main():
    t=get_int()
    while t:
        arr=[]
        for i in range(t):
            s=raw_input()
            arr.append(s)

        raw_input()
        t=get_int()
    pass

if __name__ == '__main__':
    main()

#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     04/09/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------


import re

def main():
    s=raw_input()
    while 1:
        arr=re.split('\W+',s)
        res=0
        for w in arr:
            if(w!=''):
                res+=1
        print res
        try:
            s=raw_input()
        except EOFError:
            break
    pass

if __name__ == '__main__':
    main()

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

def main():
    s=raw_input()
    arr=string.split(s)
    while(not (arr[0]=='0' and arr[1]=='0' and arr[2]=='0')):
        arr=map(toint,arr)
        if(2*arr[1]==arr[0]+arr[2]):
            print 'AP',arr[2]+arr[1]-arr[0]
        else:
            print 'GP',arr[2]*arr[1]/arr[0]
        s=raw_input()
        arr=string.split(s)
    pass

if __name__ == '__main__':
    main()

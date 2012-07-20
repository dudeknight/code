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

def toint(s): return int(s)

def get_int():
    s=raw_input()
    return int(s)
def get_line_int():
    s=raw_input()
    arr=string.split(s)
    arr=map(toint,arr)
    return arr
def get_float():
    s=raw_input()
    return float(s)
def get_string():
    return raw_input()

def main():
    arr=get_line_int()
    while arr[0]:
        arr=sorted(arr)
        if arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2]:
            print 'right'
        else:
            print 'wrong'
        arr=get_line_int()
    pass

if __name__ == '__main__':
    main()

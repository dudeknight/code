#!/usr/bin/env python
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     03/08/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import string

def toint(s): return int(s)
def tofloat(s): return float(s)

def get_int():
    s=raw_input()
    return int(s)
def get_line_int():
    s=raw_input()
    arr=string.split(s)
    arr=map(toint,arr)
    return arr
def get_line_float():
    s=raw_input()
    arr=string.split(s)
    arr=map(tofloat,arr)
    return arr

def main():
    arr = get_line_int()
    n = arr[0]
    q = arr[1]
    a = 0
    b = 0
    c = 0
    temp = 0
    s = raw_input()
    for i in s:
        a = a * 2 + ord(i) - ord('0')
    s = raw_input()
    for i in s:
        b = b * 2 + ord(i) - ord('0')

    c = a + b
    change_flag = False
    fin_res = ''
    while q:
        s = raw_input()
        arr = string.split(s)
        if (arr[0] == 'get_c'):
            if (change_flag):
                c = a + b
                change_flag = False
            ind = int(arr[1]);
            res = c & (1 << ind)
            if (res != 0):
                res = 1;
            fin_res = fin_res + str(res)
        else:
            ind  = 0;
            if (arr[0] == 'set_b'):
                val = int(arr[2]);
                ind = int(arr[1]);
                res = b & (1 << ind)
                if (res != 0):
                    res = 1
                if (res != val):
                    b = b ^ (1 << ind)
                    change_flag = True;
            else:
                val = int(arr[2]);
                ind = int(arr[1]);
                res = a & (1 << ind)
                if (res != 0):
                    res = 1
                if (res != val):
                    a = a ^ (1 << ind)
                    change_flag = True;
        q -= 1
    print fin_res
    pass

if __name__ == '__main__':
    main()

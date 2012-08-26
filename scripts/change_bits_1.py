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
import math

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
    k = int(math.sqrt(n))
    k += 1
    a = [0] * (n / k + 1)
    b = [0] * (n / k + 1)
    c = [0] * (n / k + 1)
    d = [0] * (k + 1)
    #filling d
    d[0] = 1
    for i in range(1, k):
        d[i] = d[i - 1] << 1;
    # for filling the a
    s = raw_input()
    cnt1 = 0;
    cnt2 = 0;
    res = 0;
    mult = 1;
    change_flag = True;
    for i in range(n):
        if (cnt1 == k):
            a[cnt2] = res;
            res = 0
            cnt2 += 1; cnt1 = 0; mult = 1;
        cnt1 += 1;
        res += (ord(s[n - 1 - i]) - ord('0')) * mult;
        mult *= 2;
    a[cnt2] = res;
    lena = cnt2 + 1;
    min_index = 0;
    # for filling the b
    cnt1 = 0; cnt2 = 0; res = 0; mult = 1;
    s = raw_input()
    for i in range(n):
        if (cnt1 == k):
            b[cnt2] = res;
            res = 0
            cnt2 += 1; cnt1 = 0; mult = 1;
        cnt1 += 1;
        res += (ord(s[n - 1 - i]) - ord('0')) * mult;
        mult *= 2;
    b[cnt2] = res;
    lenb = cnt2 + 1;
    # for filling the c
    imp1 = 1 << (k);
    imp2 = imp1 - 1;
    fin_res = ''
    while q:
        s = raw_input()
        arr = string.split(s)
        if (arr[0] == 'get_c'):
            if (change_flag):
                res = 0;
                for i in range(min_index, lena):
                    c[i] =  a[i] + b[i] + res;
                    if (i < lena - 1):
                        res = c[i] & imp1;
                        if (res != 0):
                            res = 1;
                            c[i] = c[i] & imp2;
                min_index = lena
                change_flag = False
            ind = int(arr[1]);
            res = c[ind / k] & (d[ind % k])
            if (res != 0):
                res = 1;
            fin_res = fin_res + str(res)
        else:
            ind  = 0;
            if (arr[0] == 'set_b'):
                val = int(arr[2]);
                ind = int(arr[1]);
                res = b[ind / k] & (1 << (ind % k))
                if (res != 0):
                    res = 1
                if (res != val):
                    b[ind / k] = b[ind / k] ^ (d[ind % k])
                    min_index = min(min_index, ind / k)
                    change_flag = True;
            else:
                val = int(arr[2]);
                ind = int(arr[1]);
                res = a[ind / k] & (1 << (ind % k))
                if (res != 0):
                    res = 1
                if (res != val):
                    a[ind / k] = a[ind / k] ^ (d[ind % k])
                    min_index = min(min_index, ind / k)
                    change_flag = True;
        q -= 1
    print fin_res
    pass

if __name__ == '__main__':
    main()

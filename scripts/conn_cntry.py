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
from decimal import *

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
    a = []
    dp2 = []
    for i in range(31):
        a.append([0] * 466)
    for i in range(466):
        dp2.append([0] * 466)
    for i in range(466):
        dp2[0][i] = 1;
        dp2[i][0] = 1;
    for i in range(1, 466):
        for j in range(1, 466):
            dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1]
    dp = [1]
    for i in range(1, 466):
        dp.append(dp[i - 1] * i)
    a[1][0] = 1
    a[2][1] = 1
    n = get_int()
    for i in range(3, n):
        for j in range(i - 1, (i * (i - 1)) / 2 + 1):
            t1 = i
            for k in range(1, (i - 1) / 2 + 1):
                for p in range(0, j):
                    a[i][j] += (a[k][p] * a[i - k][j - 1 - p] * t1 * k * (i - k)) * dp2[p][j - 1 - p]
                t1 = (t1 * (i - k)) / (k + 1)
            if (i % 2 == 0):
                temp = 0
                k = i / 2
                for p in range(0, j):
                    temp += (a[k][p] * a[i - k][j - 1 - p] * t1 * k * (i - k)) * dp2[p][j - 1 - p]
                a[i][j] += (temp / 2)
            a[i][j] += (a[i][j - 1] * ((i * (i - 1) / 2) - (j - 1)))
    fin = [0] * 436
    for j in range(n - 1, (n * (n - 1)) / 2 + 1):
        t1 = n
        for k in range(1, (n - 1) / 2 + 1):
            for p in range(k - 1, j):
                fin[j] += (a[k][p] * a[n - k][j - 1 - p] * t1 * k * (n - k)) * dp2[p][j - 1 - p]
            t1 = (t1 * (n - k)) / (k + 1)
        if (n % 2 == 0):
            temp = 0
            k = n / 2
            for p in range(0, j):
                temp += (a[k][p] * a[n - k][j - 1 - p] * t1 * k * (n - k)) * dp2[p][j - 1 - p]
            fin[j] += (temp / 2)
    res = 0
    ed = (n * (n - 1)) / 2
    res_ed = 0;
    res_pb = Decimal('0.0');
    for i in range(n - 1, ed + 1 ):
        if (fin[i] == 0):
            break
        pb = (fin[i] / Decimal(str((dp[ed] / dp[ed - i]) - res_ed))) * (1 - res_pb)
        res += i * pb
        res_pb += pb
        # print res_ed,
        res_ed = (res_ed + fin[i]) * (ed - i)
    res = int(res)
    print res
    pass

if __name__ == '__main__':
    main()

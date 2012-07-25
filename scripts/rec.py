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

mod = 7
a = 1
b = 1

cyc= [-1]*100000
pre_sum = [0]*200000
cur_pow = 1
cur_ind = 1

def find_cyc(x):
    global cyc, pre_sum, cur_pow, cur_ind
    cur_pow = x % mod
    cur_ind = 1
    pre_sum[0] = 1
    for i in range(mod):
        cyc[i] = -1
    while True:
      if (cyc[cur_pow] != -1):
          break
      else:
          cyc[cur_pow] = cur_ind
          pre_sum[cur_ind] = pre_sum[cur_ind - 1] + cur_pow
          pre_sum[cur_ind] %= mod
          cur_pow *= x
          cur_pow %= mod
          cur_ind += 1

def fast_exp_pol(x, n):
    pre_ind = cyc[cur_pow]
    cyc_length = cur_ind - pre_ind
    cyc_sum = (pre_sum[cur_ind - 1] - pre_sum[pre_ind - 1]) % mod
    res = 0
    if (n < pre_ind):
        return pre_sum[n]
    res += pre_sum[pre_ind - 1]
    res += cyc_sum * ((n - pre_ind) / cyc_length)
    res %= mod
    res += (pre_sum[((n - pre_ind) % cyc_length) + pre_ind - 1] - pre_sum[pre_ind - 1]) % mod
    res %= mod
    
    return res

def fast_exp(x, n):
    pre_ind = cyc[cur_pow]
    cyc_length = cur_ind - pre_ind
    if (n < pre_ind):
        return (pre_sum[n] - pre_sum[n - 1]) % mod
    res_ind = ((n - pre_ind) % cyc_length) + pre_ind
    return (pre_sum[res_ind] - pre_sum[res_ind - 1]) % mod

def fast_res_small(x, n):
    res = 0
    cur = 1
    for i in range(n):
        res += cur
        res %= mod
        cur *= x
        cur %= mod
    print (cur + b * res) % mod
def main():
    global mod, a, b
    t = get_int()
    while t:
        arr = get_line_int()
        mod = arr[3]
        b = arr[1] % mod
        a = arr[0] % mod
        asub = (arr[0] - 1) % mod
        n = arr[2]
        if (n == 0):
            print 1 % mod
        if (n < mod):
            fast_res_small(a, n)
        else :
            find_cyc(a)
            print (fast_exp(a, n) + b * fast_exp_pol(a, n)) % mod
        t -= 1
    pass

if __name__ == '__main__':
    main()

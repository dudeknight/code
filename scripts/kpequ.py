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

size  = 5001
psize = 10001

chk = [True] * size
prime_count = 1;
primes = []

def do_seive():
    global prime_count
    m = int(math.sqrt(size)) + 1
    for i in range(2, m):
        if chk[i]:
            for j in range(2 * i * (i - 1) + 1, size, 2 * i - 1):
                chk[j] = False
    primes.append(2)
    for i in range(2, size):
        if chk[i]:
            primes.append((2 * i) - 1)
            prime_count += 1
    pass

def main():
    do_seive()
    n = get_int()
    res = 1
    while n != 0:
        for i in range(prime_count):
            if (primes[i] > n):
                break
            temp = n
            count = 0
            while temp != 0:
                count += temp/primes[i]
                temp /= primes[i]
            res *= (2 * count + 1)
        print res
        res = 1
        n = get_int()
    pass

if __name__ == '__main__':
    main()

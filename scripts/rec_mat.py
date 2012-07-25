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

mod = 1
a = 1
b = 1

mat1 = [[1, 0], [0, 1]]
mat2 = [[1, 0], [0, 1]]
fact = [[1, 0], [0, 1]]
tmp = [[1, 0], [0, 1]]

def init():
    global mat1, fact
    mat1[0][0] = a
    mat1[0][1] = b
    mat1[1][0] = 0
    mat1[1][1] = 1
    for i in range(2):
        for j in range(2):
            fact[i][j] = mat1[i][j]

def equalize(x):
    global mat2, mat1, fact
    if x == 0:
        for i in range(2):
            for j in range(2):
                mat2[i][j] = mat1[i][j]
    elif x == 1:
        for i in range(2):
            for j in range(2):
                mat2[i][j] = fact[i][j]

def multiply():
    global mat1, mat2, tmp
    for i in range(2):
        for j in range(2):
            tmp[i][j] = 0
            for k in range(2):
                x = mat1[i][k] * mat2[k][j]
                tmp[i][j] += x
                tmp[i][j] %= mod
    for i in range(2):
        for j in range(2):
            mat1[i][j] = tmp[i][j]

def fast_exp(p):
    init()
    equalize(1)
    while (p != 1):
        if (p & 1):
            equalize(0)
            multiply()
            equalize(1)
        else:
            equalize(0)
        multiply()
        p >>= 1


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
            print 1
        else :
            fast_exp(n)
            print (mat1[0][0] + mat1[0][1]) % mod
        t -= 1
    pass

if __name__ == '__main__':
    main()

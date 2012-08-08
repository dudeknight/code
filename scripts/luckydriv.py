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

dp = [[],[]]
for i  in range(9):
    dp[0].append(0);
    dp[1].append(0);

mod = 1000000007


def main():
    t = get_int();
    while t:
        s = raw_input()
        for i in range(9):
            dp[0][i] = 0
            dp[1][i] = 0
        sub = 1
        for i in range(len(s)):
            temp = ord(s[i]) - ord('0')
            if (temp == 0):
                sub *= 2
                sub %= mod
            temp %= 9
            for j in range(9):
                dp[i & 1][(temp + j) % 9] += dp[(i &  1) ^ 1][j];
                dp[i & 1][(temp + j) % 9] %= mod;
            dp[i & 1][temp] += 1;
            dp[i & 1][temp] %= mod;
            for j in range(9):
                dp[(i & 1) ^ 1][j] = dp[i & 1][j];
        dp[0][0] -= sub
        dp[0][0] += 1
        dp[0][0] %= mod; dp[0][0] += mod; dp[0][0] %= mod;
        print dp[0][0]
        t -=1
    pass

if __name__ == '__main__':
    main()

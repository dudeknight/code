#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     02/09/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

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
    n = get_int()
    arr = get_line_int()
    maxi = 0
    for i in arr:
        maxi = max(maxi, i)
    inti = int(math.log(maxi, 2))
    buck =[[]]
    for i in arr:
        buck[0].append(i)
    while inti >= 0:
        divi = 1 << inti
        tempt = []
        for i in range(len(buck)):
            tempi = []
            tempj = []
            for j in buck[i]:
                if (j & divi):
                    tempi.append(j)
                else:
                    tempj.append(j)
            buck[i] = tempi
            tempt.append(tempj)
        buck.extend(tempt)
        holes = len(buck[0])
        size = len(buck[0])
        for i in range(1, len(buck)):
            x = len(buck[i])
            if (holes == 0 and x <= size):
                size += x
            elif (holes >= x):
                size += x
                holes -= x
            elif (size >= x):
                holes = 0
                size += x
            else:
                size += x
                holes = x - size
        if (holes == 0):
            print inti
            return 0
        inti -= 1
        pass
    print -1
    pass
if __name__ == '__main__':
    main()

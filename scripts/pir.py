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
def get_float():
    s=raw_input()
    return float(s)
def get_line_float():
    s=raw_input()
    arr=string.split(s)
    arr=map(tofloat,arr)
    return arr
def get_string():
    return raw_input()

def get_val(U,u,V,v,W,w):
    X=(w-U+v)*(U+v+w)
    x=(U-v+w)*(v-w+U)
    Y=(u-V+w)*(V+w+u)
    y=(V-w+u)*(w-u+V)
    Z=(v-W+u)*(W+u+v)
    z=(W-u+v)*(u-v+W)

    a=math.sqrt(x*Y*Z);
    b=math.sqrt(y*Z*X);
    c=math.sqrt(z*X*Y);
    d=math.sqrt(x*y*z);

    vol=math.sqrt((b+c+d-a)*(a+c+d-b)*(a+b+c-d)*(a+b+d-c));
    vol/=192.0*u*v*w
    
    vol='%.4f'%vol
    print vol
    
def main():
    t=get_int()
    while t:
        arr=get_line_float()
        get_val(arr[0],arr[5],arr[1],arr[4],arr[3],arr[2])
        t-=1
    pass

if __name__ == '__main__':
    main()

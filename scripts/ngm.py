#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     17/02/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

def get_int():
    s=raw_input()
    return int(s)

def main():
    t=get_int()
    if t%10:
        print '1'
        print t%10
    else:
        print '2'
    pass

if __name__ == '__main__':
    main()

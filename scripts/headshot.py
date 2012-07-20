#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     25/02/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

def main():
    s=raw_input()
    count_zero=0
    count_follow_zero=0
    for i in range(len(s)):
        if(s[i]=='0'):
            count_zero+=1
        if i and s[i-1]=='0' and s[i]=='0':
            count_follow_zero+=1
    if(s[len(s)-1]=='0' and s[0]=='0'):
        count_follow_zero+=1
    if(count_zero*count_zero>len(s)*count_follow_zero):
        print 'ROTATE'
    elif(count_zero*count_zero==len(s)*count_follow_zero):
        print 'EQUAL'
    else:
        print 'SHOOT'
    pass

if __name__ == '__main__':
    main()

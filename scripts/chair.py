#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     07-02-2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

def get_int():
    s=raw_input()
    return int(s)



def main():
    n=get_int()
    k=get_int()
    if(k==1):
        print n
        return;
    dp=[]
    for i in range(k+1):
        dp.append([0]*(n+1))
    for i in range(n+1):
        dp[1][i]=i;
    for i in range(2,k+1):
        for j in range(2,n+1):
            dp[i][j]=dp[i][j-1]+dp[i-1][j-2]
    print (dp[k][n-1]+dp[k-1][n-3])%1000000003
    pass

if __name__ == '__main__':
    main()

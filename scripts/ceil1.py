#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      dvdreddy
#
# Created:     18/03/2012
# Copyright:   (c) dvdreddy 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

def cel(n):
    d1=0
    d2=0
    d3=0
    while(n!=0):
        if(n%10==8):
            d1+=1
        elif(n%10==3):
            d3+=1
        elif(n%10==5):
            d2+=1
        n/=10
    if(d1>=d2 and d2>=d3):
        return True
    return False
def main():
    c=0
    a=[8,5,3]
    st=[8,5,3]
    while c!=50000:
        for s in st:
            if(ceil(s)):
                print s
                c+=1
            st.append()

    pass

if __name__ == '__main__':
    main()

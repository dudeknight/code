//the template by dvdreddy

#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

#define size 1000001
#define mod  1000000007

ll dp[size];

int main(){
    dp[0]=1;
    dp[1]=2;
    f(i,2,size){
        dp[i]=dp[i-1]*dp[i-2];
        dp[i]%=mod;
    }
    
    int t,n;
    s(t);
    while(t--){
      s(n);
      printf("%lld\n",dp[n]);
      
    }

    
}

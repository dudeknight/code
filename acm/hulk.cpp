// written by lonerdude(dvdreddy)
// all rights reserved
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


int main(){
  int t, n;
  int dp[50];
  s(t);
  while (t--){
    s(n);
    fr (i, n){
      s(dp[i]);
    }
    
    double res = 0;

    res += 2.0;
    f (i, 2, n){
      res += ((double) (n - 1) / (n - i));      
    }
    
    double res2 = 0, res3 = 0;
    fr (i, n){
      res2 += dp[i];
    }
    res2 /= n;    

    f (i, 1, n){
      res3 += dp[i];
    }
    res3 /= (n - 1);

    res = (res - 2)* 2 * res2 +  dp[0] + res3; 

    printf("%f\n", res);

  }


}

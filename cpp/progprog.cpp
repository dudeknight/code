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
#define mod 100000007
ll dp[size];


int main(){
  int t, n;
  ll res, loop_res, temp1, temp2;
  fr (i, size){
    dp[i] = 1;
  }
  dp[1] = 0;
  
  f (i, 2, size){
    temp1 = dp[i];
    for (int j = 2 * i; j < size ; j += i){
      temp2 = dp[j];
      dp[j] += temp1;
      temp1 += temp2;
      temp1 %= mod;
      dp[j] %= mod;
    }
  }
  s(t);
  while (t--){
    s(n); 
    res = dp[n];
    printf("%lld\n", res);
    
  }
  return 0;
}

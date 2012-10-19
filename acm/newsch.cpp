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

ll mod = 1000000007;

ll fast_exp(ll x, ll p){
  ll res = 1;
  while (p){
    if (p & 1){
      res = res * x;
      res %= mod;
    }
    x = x * x;
    x %= mod;
    p >>= 1;
  }
  return res;
}


int main(){
  int t;
  s(t);
  while (t--){
    ll n;
    sll(n);
    if (n == 2){
      printf("12\n");
    } else {
      ll tmp1 = fast_exp((ll) 3, n - 1);
      ll tmp2 = fast_exp((ll) 3, n - 2);
      ll res = ((ll) 4) * ((mod + tmp1 - tmp2) % mod);
      res %= mod;
      printf("%lld\n", res);
    }
  }
  return 0;
}

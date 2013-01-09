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

#define size 900001


ll mod = 1000000007;
ll fact[size];

ll fast_exp(ll x, ll p){
  ll res = 1;
  while (p){
    if (p & 1){
      res *= x;
      res %= mod;
    }  
    x *= x; x %= mod;
    p >>= 1;
  }
  return res;
}


void preproc(){
  fact[0] = 1;
  f (i, 1, size){
    fact[i] = fact[i - 1] * ((ll) i);
    fact[i] %= mod;
  }

}


ll comp (int x, int  y){
  if (x < y) return 0;
  ll res = 1;
  res = res * fact[x]; res %= mod;
  res *= fast_exp(fact[y], mod - 2); res %= mod;
  res *= fast_exp(fact[x - y], mod - 2); res %= mod;
  return res;
}

int main(){
  preproc();

  int t;
  s(t);
  int n, m, a, b;

  while (t--){
    s(n); s(m); s(a); s(b);
    ll res = 0;
    // here  calculating for all the possible points on the horizontal line
    fr (j, n - a){
      // here the -1 is done because the next step has to be vertical to avoid recounting
      ll x = comp(b + j, b) * comp(m - b + n - j - 1, n - j);
      x %= mod; res += x; res %= mod;
    }
    ll x = comp(b + n - a, b) * comp(m - b + a, a);
    x %= mod; res += x; res %= mod;
    printf("%lld\n", res);
  }

  return 0;
}

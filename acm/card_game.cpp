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

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int size = 10001;

ll mod = 1000000007;
ll fact[10001];

void init(){
  fact[0] = 1;
  f (i, 1, size){
    fact[i] = fact[i - 1] * (ll)i;
    fact[i] %= mod;
  }
}

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

ll bcf(ll x, ll p){
  if (p > x){
    return 0;
  } else {
    ll res = fact[x] * fast_exp(fact[p], mod - 2);
    res %= mod;
    res = res * fast_exp(fact[x - p], mod - 2);
    res %= mod;
    return res;
  }
}


int main(){
  init();
  int t;
  si(t); int cs = 1;
  while (t--){
    int n; int k;
    si(n); si(k);
    ll a[n]; ll b[n];
    fr (i, n){
      sll(a[i]); a[i] %= mod;
    }
    sort(a, a + n);
    b[n - 1] = n - 1;
    ll res = 0;
    for (int i = n - 1; i >= 0; i--){
      // cout << i << "d " << endl;
      b[i] = (ll) i;
      res = res + a[i] * bcf(b[i], k - 1);
      res %= mod;
    }
    printf("Case #%d: %lld\n", cs, res);
    cs++;
  }
  return 0;
}

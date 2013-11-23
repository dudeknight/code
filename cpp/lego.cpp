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

ll fast_exp(ll x, int p){
  ll res = 1;
  while (p){
    if (p&1){
      res *= x;
      res %= mod;
    }
    x = x * x;
    x %= mod;
    p >>= 1;
  }
  return res;
}

ll b[1005];
ll a[1005][2];

int main(){
  
  b[0] = 1;
  f (i, 1, 1001){
    b[i] = 0;
    a[i][1] = 0;
    a[i][0] = 0;
    fr (k, 4){
      if (i - (k + 1) >= 0){
	b[i] += b[i - (k + 1)];
	b[i] %= mod;
      }
    }
  }

  int t, n, m;
  s(t);
  while (t--){
    s(n); s(m);
    f (i, 1, m + 1){
      a[i][1] = fast_exp(b[i], n);
    }

    f (i, 1, m + 1){
      a[i][0] = a[i][1];
      f (j, 1, i){
	a[i][0] -= ((a[j][0] * a[i - j][1]) % mod);
	a[i][0] += mod; a[i][0] %= mod;
      }
    }

    printf("%lld\n", a[m][0]);
  }
  
  return 0;
}

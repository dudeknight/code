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


ll mod = 1009;
int main(){
  int n;
  ll m;
  s(n); sll(m);
  
  ll a[1009];

  ll coeff[10000];
 
  fr (i, 1009){
    a[i] = 1;
  }

  fr (i, n + 1){
    sll(coeff[i]);
  }

  ll res = 0;
  int x = (int) (m % mod);
  ll y = m / mod; y %= mod;
  fr (i, n + 1){
    ll cnt = 0;
    fr (j, 1009){
      cnt += a[j];
      cnt %= mod;
    }
    cnt = (cnt * coeff[n - i]) % mod; cnt = (cnt * y) % mod;
    res += cnt; res %= mod; cnt = 0;
    fr (j, x + 1){
      cnt += a[j];
      cnt %= mod;
    }
    cnt = (cnt * coeff[n - i]) % mod;
    res += cnt; res %= mod;
    fr (j, 1009){
      a[j] = a[j] * (ll) j; a[j] %= mod;
    }
  }


  cout << res << endl;
}

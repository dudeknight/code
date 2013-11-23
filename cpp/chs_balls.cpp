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
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int sz = 100000;

ll dp[100000];
int c[100000];
ll val[100000];
ll a, b;
ll res = 0;
int n;
ll neg_max = 999999999999LL;

void proc(){

  ll cur_max1 = 0; int cnt1 = 0;
  ll cur_max2 = neg_max; int cnt2 = 0;
  fr (i, n + 1){
    dp[i] = neg_max;
  }
  dp[0] = 0;
  fr (i, n){
    int x = c[i]; ll v = val[i];
    ll cm1 = dp[x] + a * v; ll cm2;
    if (cnt1 == x){
      cm2 = dp[cnt2] + b * v;
    } else {
      cm2 = dp[cnt1] + b * v;
    }
    /*
    cout << "g " << i << " " << cm1 << " " << cm2 << endl;
    cout << "f ";
    fr (j, n + 1){
      cout << dp[j] << " ";
    }
    cout << endl;*/
    
    cm1 = max(cm2, cm1);    
    if (dp[cnt1] < cm1){
      if (x != cnt1){cnt2 = cnt1; cnt1 = x;}
    } else if (dp[cnt1] == cm1){
      if (x != cnt1) {cnt2 = x;}
    } else if (dp[cnt2] < cm1 && x != cnt1){
      cnt2 = x;
    }
    dp[x] = max(dp[x], cm1);
  }

  res = dp[cnt1];
}

int main(){
  neg_max = (-1LL) * neg_max;
  si(n);
  int q; si(q);
  fr (i, n){
    int x; si(x);
    val[i] = (ll) x;
  }

  fr (i, n){
    si(c[i]);
  }

  while (q--){
    int x, y;
    si(x); si(y);
    a = (ll) x; b = (ll) y;
    proc();
    cout << res << endl;
  }

  return 0;
}

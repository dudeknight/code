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
    p >>= 1
  }
  return res; 
}

ll fact[5010];
ll inv_fact[5010];

void init(){
  fact[0] = 1;
  inv_fact[0] = 1;
  f (i, 1, n){
    fact[i] = fact[i - 1] * ((ll) i);
    fact[i] %= mod;
    inv_fact[i] = fast_exp(fact[i], mod - 2);
  }
}

ll dp[2][5020];

int main(){
  init();
  string st;
  int t;
  s(t);
  while (t--){
    cin >> st;
    int n = st.size();
    int cnt4 = 0, cnt7 = 0;
    
    fr (i, n){
      if (st[i] == '4'){
	cnt4++;
      } else {
	cnt7++;
      }
    }
    
    int cur = 0;
    fr (i, n + 1){
      dp[0][i] = 0;
      dp[1][i] = 0;
    }

    

  }
  return 0;
}

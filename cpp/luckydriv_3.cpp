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

typedef unsigned long long ll;

ll mod = 1000000007;

ll dp[11][4];
char c[100000];
ll sub;
ll pow2, pow6, pow24;

ll fast_exp(ll x, ll n){
  ll res = 1;
  while (n){
    if (n & 1){
      res *= x;
      res %= mod;
    }
    x = x * x;
    x %= mod;
    n >>= 1;
  }
  return res;
}

void pre_comp(){
  pow2 = fast_exp(2, mod - 2);
  pow6 = fast_exp(6, mod - 2);
  pow24 = fast_exp(24, mod - 2);
}

ll sub_val(){
  ll res = sub;
  if (sub > 1){
    res += ((((sub * (sub - 1)) % mod) * pow2) % mod);
  }
 
  if (sub > 2){
    res += ((((((sub * (sub - 1)) % mod) 
	       * (sub - 2)) % mod)
	     * pow6) % mod);
  }
  
  if (sub > 3){
    res += ((((((((sub * (sub - 1)) % mod) 
	       * (sub - 2)) % mod)
	       * (sub - 3)) % mod)
	     * pow24) % mod);
  }
  
  return res % mod;
}

int main(){
  pre_comp();
  int t, n;
  int temp1, temp2;
  ll res = 0;
  s(t);
  while (t--){
    ss(c);
    //cout << c << endl;
    n = strlen(c);
    fr (i, 9){
      fr (j, 4){
	dp[i][j] = 0;
      }
    }
    
    sub = 0;

    fr (i, n){
      temp1 = c[i] - '0';
      if (temp1 == 0){
	sub += 1;
      }
      temp1 %= 9;
      fr (k, 3){
	fr (j, 9){
	  dp[(temp1 + j) % 9][3 - k] += dp[j][3 - k - 1];
	  dp[(temp1 + j) % 9][3 - k] %= mod;	
	}
      }
      dp[temp1][0] += 1;
      dp[temp1][0] %= mod;
    }
    res = dp[0][0] + dp[0][1] + dp[0][2] + dp[0][3];
    res += (mod);
    res -= sub_val(); res %= mod;
    printf("%lld\n", res);
  }
  return 0;
}

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

ll fac[301];
ll invfac[301];


ll fast_exp(ll x, ll p){
  ll res = 1;
  while (p){
    if (p & 1){
      res = res * x;
      res %= mod;
    }
    x = x * x; x %= mod;
    p >>= 1;
  }
  return res;

}


void fill_fact(){
  fac[0] = 1;
  invfac[0] = 1;
  f (i, 1, 301){
    fac[i] = fac[i - 1] * (ll)i;
    fac[i] %= mod;
    invfac[i]  = fast_exp(fac[i], mod - 2);
  }
}

int main(){
  fill_fact();
  ll dp[301][100];
  ll dp2[10][301];
  ll dp3[10][301];

  int st[10];
  int dlim[10];

  int t, n, m;
  s(t);
  while (t--){
    s(n); s(m);
    fr (i, n){
      s(st[i]);
    }

    fr (i, n){
      s(dlim[i]);
    }

    fr (i, n){
      if (dlim[i] != 1){
	fr (k, dlim[i]){
	  dp[0][k] = 0;
	}
	dp[0][st[i] - 1] = 1;
	
	f (j, 1, m + 1){
	  dp[j][0] = dp[j - 1][1];
	  dp[j][dlim[i] - 1] = dp[j - 1][dlim[i] - 2];
	  f (k, 1, dlim[i] - 1){
	    dp[j][k] = dp[j - 1][k - 1] + dp[j - 1][k + 1];
	    dp[j][k] %= mod;
	  }
	}

	fr (j, m + 1){
	  dp2[i][j] = 0;
	  fr (k, dlim[i]){
	    dp2[i][j] += dp[j][k];
	    dp2[i][j] %= mod;
	  }
	  dp2[i][j] *= invfac[j];
	  dp2[i][j] %= mod;
	}
	
      } else {
	fr (j, m + 1){
	  dp2[i][j] = 0;
	}
	dp2[i][0] = 1; 
      }
    }

    fr (i, n){
      fr (j, m + 1){
	dp3[i][j] = 0;
      }
    }
    
    fr (i, m + 1){
      dp3[0][i] = dp2[0][i];
    }

    f (i, 1, n){
      fr (j, m + 1){
	f (k, 0, m - j + 1){
	  dp3[i][k + j] += ((dp3[i - 1][k] * dp2[i][j]) % mod);
	  dp3[i][k + j] %= mod;
	}
      }      
    }

    ll res = (dp3[n - 1][m] * fac[m]) % mod;
    printf("%lld\n", res);

  }
  return 0;
}

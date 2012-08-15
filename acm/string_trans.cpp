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

char c[1010];
int n,k;

ll fact[1001];
ll invfact[1001];

ll dp1[2][1001];
ll dp2[1001];
int dp3[1001];

ll fast_exp(ll x, ll p){
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

ll pre_comp(){
  fact[0] = 1;
  invfact[0] = 1;
  f (i, 1, 1001){
    fact[i] = i * fact[i - 1];
    fact[i] %= mod;
    invfact[i] = fast_exp(fact[i], mod - 2);
  }
}

int main(){
  pre_comp();
  int t;
  s(t);
  ll res = 0;
  int changes = 0, temp1, temp2;
  while (t--){
    s(n); s(k);
    ss(c);
    res = 0;
    fr (i, k + 1){
      res += ((((fact[n] * invfact[i]) % mod) * invfact[n - i]) % mod);
      res %= mod;
    }
    fr (i, n + 1){
      dp1[0][i] = 0; dp1[1][i] = 0;
      dp2[i] = 0;
      dp3[i] = 0;
    }

    f (i, 1, n){
      if (n % i == 0){
	fr (j, k + 1){
	  dp1[0][j] = 0; dp1[1][j] = 0;
	}
	changes = 0;
	temp1 = n / i;
	fr (j, i){
	  temp2 = 0;
	  fr (p, temp1){
	    if (c[p * i + j] == '0'){
	      temp2++;
	    }
	  }
	  changes += min(temp2, temp1 - temp2);
	  dp3[j] =  min(temp2, temp1 - temp2);
	}
	
	if (changes > k){
	  dp2[i] = 0;
	} else {
	  dp1[0][0] = 1;
	  fr (j, i){
	    fr (p, k + 1 - dp3[j]){
	      dp1[(j + 1) & 1][p + dp3[j]] += dp1[j & 1][p];
	      dp1[(j + 1) & 1][p + dp3[j]] %= mod;
	    }
	    fr (p, k + 1 - (temp1 - dp3[j])){
	      dp1[(j + 1) & 1][p + temp1 - dp3[j]] += dp1[j & 1][p];
	      dp1[(j + 1) & 1][p + temp1 - dp3[j]] %= mod;
	    }
	    fr (p, k + 1){
	      dp1[j & 1][p] = 0;
	    }
	  }
	  fr (j, k + 1){
	    dp2[i] += dp1[i & 1][j];
	    dp2[i] %= mod;
	  }
	}	
      }
    }

    f (i, 1, n){
      if (n % i == 0){
	f (j, 1, i / 2 + 1){
	  if (i % j == 0){
	    dp2[i] -= dp2[j];
	    dp2[i] = (dp2[i] + mod) % mod;
	  }
	}
	//cout << " a " <<  i << dp2[i] << endl;
	res -= dp2[i];
	res = (res + mod) % mod;
      }
    }
    
    printf("%lld\n", res);
  }
  return 0;
}

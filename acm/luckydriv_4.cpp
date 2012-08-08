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
ll cnt[10];
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

ll binomial_coff(ll x,int cnt){
  ll res = 0;
  if (x < cnt)
    return 0;
  if (cnt == 1){
    res = x%mod;
  } else if (cnt == 2){ 
    res = ((((x * (x - 1)) % mod) * pow2) % mod);
  } else if (cnt == 3){
    res = ((((((x * (x - 1)) % mod) 
	      * (x - 2)) % mod)
	    * pow6) % mod);
  } else if (cnt == 4){
    res = ((((((((x * (x - 1)) % mod) 
		* (x - 2)) % mod)
	      * (x - 3)) % mod)
	    * pow24) % mod);
  }
  return res;
}

ll res_eval(){
  ll res = 0;
  f (i, 1, 10){
    if (i % 9 == 0){
      res += binomial_coff(cnt[i], 1);
    }
    if ((2 * i) % 9 == 0){
      res += binomial_coff(cnt[i], 2);
    }
    if ((3 * i) % 9 == 0){
      res += binomial_coff(cnt[i], 3);
    }
    if ((4 * i) % 9 == 0){
      res += binomial_coff(cnt[i], 4);
    }
    res %= mod;
  }

  fr (i, 10){
    f (j, i + 1, 10){
      if ((i + j) % 9 == 0){
	res += ((binomial_coff(cnt[i], 1) 
		 * binomial_coff(cnt[j], 1)) % mod);
	res += ((binomial_coff(cnt[i], 2) 
		 * binomial_coff(cnt[j], 2)) % mod);
	res %= mod;
      }
      if ((2 * i + j) % 9 == 0){
	res += ((binomial_coff(cnt[i], 2) 
		 * binomial_coff(cnt[j], 1)) % mod);
	res %= mod;
      }
      if ((3 * i + j) % 9 == 0){
	res += ((binomial_coff(cnt[i], 3) 
		 * binomial_coff(cnt[j], 1)) % mod);
	res %= mod;
      }
      if ((i + 2 * j) % 9 == 0){
	res += ((binomial_coff(cnt[i], 1) 
		 * binomial_coff(cnt[j], 2)) % mod);
	res %= mod;
      }
      if ((i + 3 * j) % 9 == 0){
	res += ((binomial_coff(cnt[i], 1) 
		 * binomial_coff(cnt[j], 3)) % mod);
	res %= mod;
      }
    }
  }

  fr (i, 10){
    f (j, i + 1, 10){
      f (k, j + 1, 10){
	if ((i + j + k) % 9 == 0){
	    res += ((((binomial_coff(cnt[i], 1) 
		       * binomial_coff(cnt[j], 1)) % mod)
		     * binomial_coff(cnt[k], 1)) % mod);
	    res %= mod;
	}
	if ((2 * i + j + k) % 9 == 0){
	    res += ((((binomial_coff(cnt[i], 2) 
		       * binomial_coff(cnt[j], 1)) % mod)
		     * binomial_coff(cnt[k], 1)) % mod);
	    res %= mod;
	}
	if ((i + 2 * j + k) % 9 == 0){
	    res += ((((binomial_coff(cnt[i], 1) 
		       * binomial_coff(cnt[j], 2)) % mod)
		     * binomial_coff(cnt[k], 1)) % mod);
	    res %= mod;
	}
	if ((i + j + 2 * k) % 9 == 0){
	    res += ((((binomial_coff(cnt[i], 1) 
		       * binomial_coff(cnt[j], 1)) % mod)
		     * binomial_coff(cnt[k], 2)) % mod);
	    res %= mod;
	}
      }
    }
  }

  fr (i, 10){
    f (j, i + 1, 10){
      f (k, j + 1, 10){
	f (p, k + 1, 10){
	  if ((i + j + k + p) % 9 == 0){
	    res += ((((((binomial_coff(cnt[i], 1) 
			 * binomial_coff(cnt[j], 1)) % mod)
		       * binomial_coff(cnt[k], 1)) % mod)
		     *binomial_coff(cnt[p], 1)) % mod);
	    res %= mod;
	  }
	}
      }
    }
  }

  return res;
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
    fr (i, 10){
      cnt[i] = 0;
    }
    
    fr (i, n){
      temp1 = c[i] - '0';
      cnt[temp1]++;
    }
    res = res_eval();
    printf("%lld\n", res);
  }
  return 0;
}

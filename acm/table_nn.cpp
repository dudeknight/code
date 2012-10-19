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
#define sll(x) scanf("%l64d",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

ll mod = 1000000007;

ll fast_exp(ll x, ll p){
  if (x == 0){
    return 0;
  }
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

ll bin[3][101][101];
ll init_bin(){
  fr (i, 101){
    fr (j, 101){
      bin[0][i][j] = 0;
    }
  }

  fr (i, 101){
    bin[0][i][0] = 1;
  }

  f (i, 1, 101){
    f (j, 1, i + 1){
      bin[0][i][j] = bin[0][i - 1][j] + bin[0][i - 1][j - 1];
      bin[0][i][j] %= mod;
    }
  }

}

int main(){
  init_bin();
  int n, k;
  ll m;
  cin >> n >> m >> k;
  ll a[n][k + 1];
  ll x = m / n;
  int modi = m % n;

  fr (i, n){
    fr (j, k + 1){
      a[i][j] = 0;
    }
  }


  fr (i, n + 1){
    fr (j, n + 1){
      bin[1][i][j] = fast_exp(bin[0][i][j], x);
      bin[2][i][j] = (bin[1][i][j] * bin[0][i][j]) % mod;
    }
  }


  fr (i, min(n + 1, k + 1)){
    if (0 < modi){
      a[0][i] = bin[2][n][i];
    } else {
      a[0][i] = bin[1][n][i];
    }
  }

  f (i, 1, n){
    int expn = 1;
    if (i < modi){
      expn += 1;
    }
    fr (j, min(k + 1, n + 1)){
      fr (p, min(k, (i + 1) * n) - j + 1){
	a[i][p + j] += (a[i - 1][p] * bin[expn][n][j]) % mod;
	a[i][p + j] %= mod;
      }
    }
  }

  /*
  fr (i, n){
    fr (j, k + 1){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  */

  cout << a[n - 1][k] << endl;
  return 0;
}

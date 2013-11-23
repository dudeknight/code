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

int main(){
  ll a[101][3001];

  int maxn = 101;
  int maxm = 3001;

  fr (i, maxn){
    fr (j, 30 * i + 1){
      a[i][j] = 0;
    }
  }

  ll dp[2][4][maxm];

  fr (k, 4){
    fr (j, maxm){
      dp[0][k][j] = 0;
      dp[0][k][j] = 0;
    }
  }
 
  
  // 0 nothing
  // 1 spare
  // 2 nothing strike
  // 3 strike strike
  
  dp[0][0][0] = 1;
  a[0][0] = 1;
  int cur = 1, prev = 0;

  f (i, 1, maxn){
    fr (j, 30 * i + 1){
      fr (p, 10){
	fr (q, 10 - p){
	  if (j >= (p + q)){
	    dp[cur][0][j] += dp[prev][0][j - (p + q)];
	  }
	  if (j >= (2 * p + q)){
	    dp[cur][0][j] += dp[prev][1][j - (2 * p + q)];
	  }
	  if (j >= (2 * (p + q))){
	    dp[cur][0][j] += dp[prev][2][j - (2 * p + 2 * q)];
	  }
	  if (j >= (3 * p + 2 * q)){
	    dp[cur][0][j] += dp[prev][3][j - (3 * p + 2 * q)];
	  }
	}
      }
      dp[cur][0][j] %= mod;	    	    

      fr (p, 10){
	if (j >= 10){
	  dp[cur][1][j] += dp[prev][0][j - 10];
	}
	if (j >=  (p + 10)){
	  dp[cur][1][j] += dp[prev][1][j - (p + 10)];
	}
	if (j >= (20)){
	  dp[cur][1][j] += dp[prev][2][j - 20];
	}
	if (j >= (p + 20)){
	  dp[cur][1][j] += dp[prev][3][j - (p + 20)];
	}
      }
      dp[cur][1][j] %= mod;	    	    
      
      if (j >= 10){
	dp[cur][2][j] += dp[prev][0][j - 10];
      }
      if (j >= 20){
	dp[cur][2][j] += dp[prev][1][j - 20];
      }
      dp[cur][2][j] %= mod;

      if (j >= 20){
	dp[cur][3][j] += dp[prev][2][j - 20];
      }
      if (j >= 30){
	dp[cur][3][j] += dp[prev][3][j - 30];
      }
      dp[cur][3][j] %= mod;

      a[i][j] += dp[cur][0][j];
      a[i][j] %= mod;

      fr (p, 11){
	if (j >= p){
	  a[i][j] += dp[cur][1][j - p];
	}
      }
      a[i][j] %= mod;
      fr (p, 10){
	fr (q, 11 - p){
	  if (j >= (p + q)){
	    a[i][j] += dp[cur][2][j - (p + q)];
	  }
	  if (j >= (2 * p + q)){
	    a[i][j] += dp[cur][3][j - (2 * p + q)];
	  }
	}
      }
      a[i][j] %= mod;
      fr (q, 11){
	if (j >= (10 + q)){
	  a[i][j] += dp[cur][2][j - (10 + q)];
	}
	if (j >= (20 + q)){
	  a[i][j] += dp[cur][3][j - (20 + q)];
	}
      }
      a[i][j] %= mod;	  
    }


    prev = cur;
    cur = cur ^ 1;
    fr (k, 4){
      fr (j, 30 * i + 1){
	dp[cur][k][j] = 0;
      }
    }
  }


  
  int t, n, m;
  s(t);
  while (t--){
    s(n); s(m);
    printf("%lld\n", a[n][m]);
  }
  return 0;
}

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
    cout << i << endl;
  }

  ll dp[4][maxn][maxm];

  fr (k, 4){
    fr (i, 101){      
      fr (j, 30 * i + 1){
	dp[k][i][j] = 0;
      }
      cout << i << endl;
    }
  }
 
  
  // 0 nothing
  // 1 spare
  // 2 nothing strike
  // 3 strike strike
  
  dp[0][0][0] = 1;

  f (i, 1, maxn){
    fr (j, 30 * i + 1){
      cout << i << " " << j << endl;
      fr (p, 10){
	fr (q, 10){
	  if (p + q < 10){
	    if (j >= (p + q)){
	      dp[0][i][j] += dp[0][i - 1][j - (p + q)];
	      dp[0][i][j] %= mod;	    	    
	    }
	    if (j >= (2 * p + q)){
	      dp[0][i][j] += dp[1][i - 1][j - (2 * p + q)];
	      dp[0][i][j] %= mod;	    	    
	    }
	    if (j >= (2 * (p + q))){
	      dp[0][i][j] += dp[2][i - 1][j - (2 * p + 2 * q)];
	      dp[0][i][j] %= mod;	    	    
	    }
	    if (j >= (3 * p + 2 * q)){
	      dp[0][i][j] += dp[3][i - 1][j - (3 * p + 2 * q)];
	      dp[0][i][j] %= mod;	    	    
	    }
	  }	  
	}
      }
      
      fr (p, 10){
	if (j >= 10){
	  dp[1][i][j] += dp[0][i - 1][j - 10];
	  dp[1][i][j] %= mod;	    	    
	}
	if (j >=  ( p + 10)){
	  dp[1][i][j] += dp[1][i - 1][j - (p + 10)];
	  dp[1][i][j] %= mod;	    	    
	}
	if (j >= (20)){
	  dp[1][i][j] += dp[2][i - 1][j - 20];
	  dp[1][i][j] %= mod;	    	    
	}
	if (j >= (p + 20)){
	  dp[1][i][j] += dp[3][i - 1][j - (p + 20)];
	  dp[1][i][j] %= mod;	    	    
	}
      }
      
      if (j >= 10){
	dp[2][i][j] += dp[0][i - 1][j - 10];
	dp[2][i][j] %= mod;
      }
      if (j >= 20){
	dp[2][i][j] += dp[1][i - 1][j - 20];
	dp[2][i][j] %= mod;
      }
      
      if (j >= 20){
	dp[3][i][j] += dp[2][i - 1][j - 20];
	dp[3][i][j] %= mod;
      }
      if (j >= 30){
	dp[3][i][j] += dp[3][i - 1][j - 30];
	dp[3][i][j] %= mod;
      }
    }
  }
  

  fr (i, maxn){
    fr (j, 30 * i + 1 ){
      a[i][j] += dp[0][i][j];
      a[i][j] %= mod;
      cout << "i " << i << " " << j << endl;
      fr (p, 11){
	if (j >= p){
	  a[i][j] += dp[1][i][j - p];
	  a[i][j] %= mod;
	}
      }
      fr (p, 11){
	fr (q, 11){
	  if (j >= (p + q)){
	    a[i][j] += dp[2][i][j - (p + q)];
	    a[i][j] %= mod;
	  }
	  if (j >= (2 * p + q)){
	    a[i][j] += dp[3][i][j - (2 * p + q)];
	    a[i][j] %= mod;
	  }
	}
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

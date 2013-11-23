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
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

inline void spIntRead(int* a){
  char c = 0;
  while (c < 33) c = fgetc(stdin);
  *a = 0;
  while (c > 33){
    *a = *a * 10 + c - '0';
    c = fgetc(stdin);
  }
}

inline void spLLRead(ll* a){
  char c = 0;
  while (c < 33) c = fgetc(stdin);
  *a = 0L;
  ll x = (ll) 10;
  while (c > 33){
    *a = *a * x + (ll)(c - '0');
    c = fgetc(stdin);
  }
}

int maxs[] = {60, 38, 26, 22};

#define szsss 1304160

ll dp[2][119][75][51][43];
ll dpxx[37][szsss];
ll dp_res1[37][60][38][26][22];

int val[][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {2, 0, 0, 0},
		{0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1}, {3, 0, 0, 0},
		{0, 2, 0, 0}};

ll dp_res2[37];

ll mod = (1LL << 32);

void pre1(){
  int cur = 0;
  fr (i, 2){
    fr (j1, 2 * maxs[0] - 1){
      fr (j2, 2 * maxs[1] - 1){
	fr (j3, 2 * maxs[2] - 1){
	  fr (j4, 2 * maxs[3] - 1){
	    //  dp[i][j1][j2][j3][j4] = 0;
	  }
	}
      }
    }
  }
  
  fr (i, 37){
    fr (j1, maxs[0]){
      fr (j2, maxs[1]){
	fr (j3, maxs[2]){
	  fr (j4, maxs[3]){
	  dp_res1[i][j1][j2][j3][j4] = 0;
	  /*   dpxx[i][j1 * maxs[1] * maxs[2] * maxs[3] + j2  * maxs[2] * maxs[3] + j3 * maxs[3] + j4] = 0; */
	  }
	}
      }
    }
  }
  
  /*
  fr (i, 37){
    fr (j, szsss){
      dpxx[i][j] = 0;
    }
  }
  */
  dp[0][0][0][0][0] = 1;
  
  return;
  
  f (i, 1, 37){
    
    fr (p, 9) {
      
      if (!cur){
	fr (j1, 2 * maxs[0] - 1 - val[p][0]){
	  fr (j2, 2 * maxs[1] - 1 - val[p][1]){
	    fr (j3, 2 * maxs[2] - 1 - val[p][2]){
	      fr (j4, 2 * maxs[3] - 1 - val[p][3]){
		dp[cur ^ 1][j1 + val[p][0]][j2 + val[p][1]][j3 + val[p][2]][j4 + val[p][3]] += dp[cur][j1][j2][j3][j4];
		dp[cur ^ 1][j1 + val[p][0]][j2 + val[p][1]][j3 + val[p][2]][j4 + val[p][3]] %= mod;
	      }
	    }
	  }
	}
      } else {
	f (j1, val[p][0], 2 * maxs[0] - 1){
	  f (j2, val[p][1], 2 * maxs[1] - 1){
	    f (j3, val[p][2], 2 * maxs[2] - 1){
	      f (j4, val[p][3], 2 * maxs[3] - 1){
		dp[cur ^ 1][j1 - val[p][0]][j2 - val[p][1]][j3 - val[p][2]][j4 - val[p][3]] += dp[cur][j1][j2][j3][j4];
		dp[cur ^ 1][j1 - val[p][0]][j2 - val[p][1]][j3 - val[p][2]][j4 - val[p][3]] %= mod;
	      }
	    }
	  }
	}
      }

    }
        

    fr (j1, 2 * maxs[0] - 1){
      fr (j2, 2 * maxs[1] - 1){
	fr (j3, 2 * maxs[2] - 1){
	  fr (j4, 2 * maxs[3] - 1){
	    dp[cur][j1][j2][j3][j4] = 0;
	  }
	}
      }
    }    
    cur = cur ^ 1;
    fr (j1, maxs[0]){
      fr (j2, maxs[1]){
	fr (j3, maxs[2]){
	  fr (j4, maxs[3]){
	    dp_res1[i][j1][j2][j3][j4] = dp[cur][j1 + maxs[0]][j2 + maxs[1]][j3 + maxs[2]][j4 +maxs[3]];
	  }
	}
      }
    }    
  }

}

void pre2(){


  
}


int main(){
  pre1();
  pre2();
  return 0;
  int t;
  spIntRead(&t);
  int n; ll v;
  while (t--){
    //  spIntRead(&n); spLLRead(&v);
    dp[0][0][0][0][0] = 122;
    printf("%lld\n", dp[0][0][0][0][0]);
  }
  
  return 0;
}

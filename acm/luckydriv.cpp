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

ll dp[2][11][4];
char c[100000];
ll sub[4];

int main(){
  int t, n;
  int temp1, temp2;
  ll res = 0;
  s(t);
  while (t--){
    cin >> c;
    //cout << c << endl;
    n = strlen(c);
    fr (i, 9){
      fr (j, 4){
	dp[1][i][j] = 0;
	dp[0][i][j] = 0;
      }
    }

    fr (i, 4){
      sub[i] = 0;
    }

    fr (i, n){
      temp1 = c[i] - '0';
      if (temp1 == 0){
	fr (i, 3){
	  sub[3 - i] += sub[3 - i - 1];
	  sub[3 - i] %= mod;
	}
	sub[0] += 1;
	sub[0] %= mod;
      }
      temp1 %= 9;
      fr (j, 9){
	fr (k, 3){
	  dp[i & 1][(temp1 + j) % 9][k + 1] += dp[(i & 1) ^ 1][j][k];
	  dp[i & 1][(temp1 + j) % 9][k + 1] %= mod;	
	}
      }
      dp[i & 1][temp1][0] += 1;
      dp[i & 1][temp1][0] %= mod;
      fr (j, 9){
	fr (k, 4){
	  dp[(i & 1) ^ 1][j][k] = dp[i & 1][j][k];
	}
      }
    }
    res = dp[0][0][0] + dp[0][0][1] + dp[0][0][2] + dp[0][0][3];
    res += (mod + mod + mod + mod);
    res -= (sub[0] + sub[1] + sub[2] + sub[3]);
    res %= mod;
    printf("%lld\n", res);
  }
  return 0;
}

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

double dp[2001][2001];

int main() {

  fr (i, 2001){
    fr (j, 2001){
      dp[i][j] = 0.0;
    }
  }
  dp[1][1] = 1.0;
  f (i, 2, 2001){
    dp[i][1] = 0.5 + 0.5 * (1 - dp[i - 1][1]);
    dp[i][i] = 0.5 + 0.5 * (1 - dp[i - 1][i - 1]);
    f (j, 2, i){
      dp[i][j] = 0.5 * (1 - dp[i - 1][j - 1]) + 0.5 * (1 - dp[i - 1][j]);
    }
  }
  
  double res;
  int t;
  s(t);
  int n, v;
  while (t--){
    res = 0.0;
    s(n);
    fr (i, n){
      s(v);
      res += ((double)v) * dp[n][i + 1];
    }
    printf("%f\n", res);
  }

  return 0;
}

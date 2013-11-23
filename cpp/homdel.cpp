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
int dp[250][250];

int main(){
  int n;
  s(n);
  fr (i, n){
    fr (j, n){
      s(dp[i][j]);
    }
  }

  fr (k, n){
    fr (i, n){
      fr (j, n){
	dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  int t;
  int a, b, c;
  s(t);
  while (t--){
    s(a); s(b); s(c);
    printf("%d %d\n",dp[a][b] + dp[b][c], dp[a][b] + dp[b][c] - dp[a][c]);
  }
  return 0;
}

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
  int t;
  string s;
  string sr;
  s(t);
  ll dp[200][200];

  while (t--){
    cin >> s;
    int n = s.size();
    sr = "";
    fr (i, n){
      fr (j, n){
	dp[i][j] = 0;
      }
      sr += s[n - 1 - i];
    }

    if (n == 1){
      printf("0\n");
      continue;
    }

    ll res = 0;
    if (sr[0] == s[0]){
      dp[0][0] = 1;
    }
    f (i, 1, n - 1){
      if (sr[0] == s[i]){
	res++;
	dp[0][i] = dp[0][i - 1] + 1;
      } else {
	dp[0][i] = dp[0][i - 1];
      }
    }

    int cur = n - 2;
    f (i, 1, n - 1){
      fr (j, cur){
	if (s[j] == s[cur]){
	  if (j == 0){
	    dp[i][j] += 1;
	    res += 1;
	  } else {
	    dp[i][j] += dp[i - 1][j - 1]  + 1;
	    res += dp[i - 1][j - 1] + 1;
	  }
	  dp[i][j] %= mod;
	  res %= mod;
	}
	dp[i][j] += dp[i - 1][j];
	dp[i][j] %= mod;
      }
      cur--;
    }
    printf("%lld\n", res);
  }

  return 0;
}

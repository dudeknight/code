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


int h[500];
int ptl[500];
int dp[1010];

int main(){
  int t, n;
  s(t);
  
  while (t--){
    s(n);
    int maxi = 501;
    fr (i, n){
      s(h[i]);
      maxi = max(maxi, h[i]);
    }
    fr (i, n){
      s(ptl[i]);
    }

    maxi = 2 * maxi;
    fr (i, maxi + 1){
      dp[i] = 1002;
    }
    dp[0] = 0;
    sort(ptl, ptl + n);
    f (i, 1, maxi + 1){
      fr (j, n){
	if (ptl[j] > i){
	  break;
	}
	dp[i] = min(dp[i], dp[i - ptl[j]] + 1);
      }
    }
    
    int res = 0;    
    fr (i, n){
      res += dp[2 * h[i]];
    }
    printf("%d\n", res);

  }
  return 0;
}

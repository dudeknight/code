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
typedef pair<int, int> pi;

bool comp(pi a, pi b){
  if (a.second < b.second){
    return true;
  } else if (a.second == b.second){
    if (a.first < b.first){
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

int main(){
  pi intv[1000];
  int dp1[1000];
  int dp2[1000];

  int t, n;
  s(t);
  while (t--){
    s(n);
    fr (i, n){
      s(intv[i].first); s(intv[i].second);
    }
    sort(intv, intv + n, comp);
    
    fr (i, n){
      dp1[i] = 0;
      dp2[i] = 1;
    }
    
    f (i, 1, n){
      fr (j, i){
	if (dp1[j] < intv[i].first){
	  if (dp2[i] < dp2[j] + 1){
	    dp2[i] = dp2[j] + 1;
	    if (intv[i].first > intv[j].second){
	      dp1[i] = dp1[j];
	    } else {
	      dp1[i] = intv[j].second;
	    }
	  } else if (dp2[i] == dp2[j] + 1){
	    if (intv[i].first > intv[j].second){
	      dp1[i] = min(dp1[i], dp1[j]);
	    } else {
	      dp1[i] = min(dp1[i], intv[j].second);
	    }
	  }
	}
      }
    }

    int res = 1;
    fr (i, n){
      res = max(res, dp2[i]);
    }
    printf("%d\n", res);
  }

  return 0;
}

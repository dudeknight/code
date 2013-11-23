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

struct event {
  int st;
  int end;
  ll cost;
};

bool comp(event x, event y){
  if (x.end < y.end){
    return true;
  } else if (x.end == y.end){
    return (x.st < y.st);
  } else {
    return false;
  }
}

event a[2000];
ll dp[2000];

int main(){
  int t;
  s(t);
  while (t--){
    int n; s(n);
    fr (i, n){
      s(a[i].st);
      s(a[i].end);
      sll(a[i].cost);
    }
    sort(a, a + n, comp);
    dp[0] = a[0].cost;
    f (i, 1, n){
      ll temp = a[i].cost;
      fr (j, i){
	if (a[j].end <= a[i].st){
	  temp = max(temp, dp[j] + a[i].cost);
	}
      }
      dp[i] = temp;
    }
    ll res = 0;
    fr (i, n){
      res = max(res, dp[i]);
    }
    printf("%lld\n", res);
  }
  return 0;
}

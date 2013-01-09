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
#define size 100000

typedef long long ll;

ll mod = 1000000000;

int a[size];
ll wt[size];

struct ed{
  int x;
  int y;
  ll wt;
};

bool comp(ed a, ed b){
  if (a.wt > b.wt){
    return true;
  } else {
    return false;
  }
}

ed v[size];


int parent (int x){
  while (x != a[x]){
    int temp = a[x];
    a[x] = a[a[x]];
    x = temp;
  }
  return x;
}

int main(){
  int n, m;
  s(n); s(m);

  fr (i, m){
    s(v[i].x); s(v[i].y); sll(v[i].wt);
    v[i].x--; v[i].y--;
  }
  
  sort(v, v + m, comp);
  ll wt[size];

  fr (i, n){
    wt[i] = 1;
    a[i] = i;
  }
  ll score = 0;
  ll res = 0;
  fr (i, m){
    ed x = v[i];
    int par_x = parent(x.x);
    int par_y = parent(x.y);
    ll e_wt = x.wt;
    if (par_x != par_y){
      score -= ((wt[par_x] * (wt[par_x] - 1)) / 2) % mod;
      score = (score + mod + mod + mod) % mod;
      score -= ((wt[par_y] * (wt[par_y] - 1)) / 2) % mod;
      score = (score + mod + mod + mod) % mod;
      ll scr_x = wt[par_x] + wt[par_y];
      score += ((scr_x * (scr_x - 1)) / 2) % mod;
      if (wt[par_x] < wt[par_y]){
	a[par_x] = par_y; wt[par_y] += wt[par_x];
      } else {
	a[par_y] = par_x; wt[par_x] += wt[par_y];
      }
    }
    res += ((e_wt * score) % mod);
    res %= mod;
  }

  printf("%lld\n", res);
  

  return 0;
}

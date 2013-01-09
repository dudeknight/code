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

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

ll tms[100][100];
ll tms2[100];
int n;
int m;
int k;
ll c;

VVI w;
VI mr;
VI mc;

bool is_good(ll v){
  
  fr (i, n){
    fr (j, m){
      if (tms[i][j] < v){
	w[i][j] = 1;
      } else {
	w[i][j] = 0;
      }
      if (tms[i][j] + c < v){
	w[i][j + m] = 1;
      } else {
	w[i][j + m] = 0;
      }
    }
  }
  
  if (BipartiteMatching(w, mr, mc) >= k){
    return true;
  } else {
    return false;
  }
}


int main(){
  int t;
  si(t);
  while (t--){
    si(n); si(m); si(k); sll(c);
    fr (i, n){
      fr (j, m){
	sll(tms[i][j]);
      }
    }

    fr (i, m){
      tms2[i] = tms[0][i];
    }

    fr (i, n){
      fr (j, m){
	tms2[j] = min(tms[i][j], tms2[j]);
      }
    }
    
    w.resize(n);
    fr (i, n){
      w[i].resize(2 * m);
    }
    
    ll hi = 10000002;
    ll lo = 1;
    while (lo < hi && hi - lo >= 2) {
      //   cout << lo << " " << hi << endl;
      ll mid = (hi + lo) / 2;
      if (!(is_good(mid))){
	lo = mid;
      } else {
	hi = mid;
      }
    }
    printf("%lld\n", lo);
  }
}

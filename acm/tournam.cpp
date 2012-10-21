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
typedef pair<double, double> pd;

int main(){
  int t;
  s(t);
  while (t--){
    ll n; sll(n);
    int k = 0;
    ll x = n;
    while (x){
      k++; x >>=1;
    }
    k--;
    int m; double p;
    s(m); sf(p); p /= 100;
    map<ll, pd> tree[2];
    int cur = 0;
    fr (i, m){
      ll x; sll(x);
      tree[cur][x - 1] = pd(1.0, 0.0);
    }
    map<ll, pd>::iterator it, jt;
    fr (i, k){
      for (it = tree[cur].begin(); it != tree[cur].end(); it++){
	jt = tree[cur].end(); jt--;
	if (it != jt){
	  jt = it; jt++;
	  ll x = it->first; ll y = jt->first;
	  if (x % 2 == 0 && y == x + 1){
	    pd xp = it->second;
	    pd yp = jt->second;
	    double pp = xp.first * yp.first + xp.second * yp.first * p + xp.first * yp.second * p;
	    pd np = pd(pp, 1 - pp);
	    tree[cur ^ 1][x >> 1] = np; 
	    it++;
	  } else {
	    pd xp = it->second;
	    double pp = xp.first * p;
	    pd np = pd(pp, 1 - pp);
	    tree[cur ^ 1][x >> 1] = np;
	  }
	} else {
	  pd xp = it->second;
	  ll x = it->first;
	  double pp = xp.first * p;
	  pd np = pd(pp, 1 - pp);
	  tree[cur ^ 1][x >> 1] = np;
	}
      }
      tree[cur].clear();
      cur = cur ^ 1;
    }
    double res = tree[cur][0].first;
    res = res * 100;
    printf("%.12f\n", res);
  }
  return 0;
}
